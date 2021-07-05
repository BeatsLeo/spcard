#include"administer.h"
#include"consumer.h"
#include"dofile.h"
#include"menu.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

//void ShowWindowAdm();
//void MakeCard(Apply_Node *card);
//void CheckApply(Apply_Node *Apply);
//void SendCard(Consume_Node *card);
//void Showinfo();
//void ChangePsw();

Consumer_Node* head;               //头节点
Apply_Node* head_Apply;            //头节点

bool ShowWindowAdm(struct Administer& administer, struct Apply_Node* apply) {
	while (true)
	{
		printf("尊敬的管理员,欢迎使用购物卡管理系统!n");
		printf("  *********************\n");
		printf("**  购物卡管理系统  **\n");
		printf("**  审批并制卡---1  **\n");
		printf("**  发卡---2  **\n");
		printf("**  查看信息---3  **\n");
		printf("**  修改密码---4  **\n");
		printf("**  退出管理系统---0  **\n");

		int choice = 0;
		printf("请输入对应的功能键(数字):  ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			CheckApply(administer, apply);
			break;
		case 2:
			SendCard(administer);
			break;
		case 3:
			ShowInfo(administer);
			break;
		case 4:
			ChangePsw(administer);
			break;
		case 0:
			return true;
		default:
			printf("请输入正确的选择！\n");
			break;
		}
	}
}

void MakeCard(struct Administer& administer, Apply_Node* card) {                                      //制卡
	Consumer_Node* s = (Consumer_Node*)malloc(sizeof(Consumer_Node));

	s->number_ = card->number_;
	int f = 0;
	for (int i = 0; i < strlen(card->name_); i++) {
		s->name_[i] = card->name_[i];
		f = i;
	}
	s->name_[f + 1] = '\0';
	for (int i = 0; i < strlen(card->password_); i++) {
		s->password_[i] = card->password_[i];
		f = i;
	}
	s->password_[f + 1] = '\0';
	for (int i = 0; i < strlen(card->id_); i++) {
		s->id_[i] = card->id_[i];
		f = i;
	}
	s->id_[f + 1] = '\0';
	s->is_available_ = false;
	s->score_ = 0;
	s->balance_ = 0;

	s->next_ = administer.consumer_->next_;
	administer.consumer_->next_ = s;
	printf("制卡成功！！！\n");

}

void CheckApply(struct Administer& administer, Apply_Node* apply) {                                //审批
	system("cls");
	Apply_Node* p = (Apply_Node*)malloc(sizeof(Apply_Node));
	int number;
	int flag;
	p = apply->next_;
	if (apply->next_ != NULL) {
		while (p != NULL) {
			printf("正在申请的购物卡信息:\n");
			printf("卡号:%d\n", p->number_);
			printf("姓名:%s\n", p->name_);
			printf("身份证:%s\n", p->id_);
			printf("\n");

			p = p->next_;
		}

		while (1) {
			printf("输入批准申请的卡号:");
			scanf("%d", &number);

			p = apply->next_;
			while (1) {
				if (p->number_ == number) {
					MakeCard(administer, p);
					break;
				}
				p = p->next_;
			}
			printf("是否继续操作(是(1)/否(0)):");
			scanf("%d", &flag);
			if (flag == 0) {
				break;
			}
		}
	}

	else if (apply->next_ = NULL) {
		printf("无正在申请的购物卡\n");
	}
}

void SendCard(Administer& administer) {                          //发卡
	printf("请输入需要发卡的卡号");
	int num;
	scanf("%d", &num);
	Consumer_Node* card = administer.consumer_;
	while (card->next_ != NULL) {
		if (card->next_->number_ == num) {
			card->next_->is_available_ = true;
			system("cls");
			return;
		}
	}
	printf("该卡号不存在！\n");
	return;
}

void ShowInfo(struct Administer& administer) {
	system("cls");
	Consumer_Node* s = administer.consumer_->next_;
	while (s != NULL) {
		printf("卡号:%d\n", s->number_);
		printf("姓名:%s\n", s->name_);
		printf("密码:%s\n", s->password_);
		printf("身份证:%s\n", s->id_);
		printf("余额:%.2f\n", s->balance_);
		printf("积分:%.2f\n", s->score_);
		if (s->is_available_ == false) {
			printf("激活状态：未激活！");
		}
		else {
			printf("激活状态：已激活！");
		}
		printf("\n\n");
		s = s->next_;
	}
	return;
}

void ChangePsw(struct Administer& administer) {
	char password[7];
	printf("请输入六位数新密码:");
	scanf("%s", password);
	if (strlen(password) != 6) {
		printf("请输入正确的位数！\n");
	}
	else {
		for (int i = 0; i < 6; i++)
		{
			administer.password_[i] = password[i];
		}
		administer.password_[6] = '\0';
	}
	system("cls");
	printf("修改成功！\n\n");
}

void AskCard(struct Apply_Node* apply) {        //申请购物卡
	int number;
	char name[10];
	char password[6];
	char id[18];
	printf("请输入卡号:");
	scanf("%d", &number);

	printf("输入姓名:");
	scanf("%s", name);

	printf("请输入密码:");
	scanf("%s", password);

	printf("请输入身份证:");
	scanf("%s", id);

	Apply_Node* p = (Apply_Node*)malloc(sizeof(Apply_Node));
	p->number_ = number;
	for (int i = 0; i < strlen(name); i++)
	{
		p->name_[i] = name[i];
	}
	for (int i = 0; i < strlen(password); i++)
	{
		p->password_[i] = password[i];
	}
	for (int i = 0; i < strlen(id); i++)
	{
		p->id_[i] = id[i];
	}


	p->next_ = apply->next_;
	apply->next_ = p;

}
