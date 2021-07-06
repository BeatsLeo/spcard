#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>

#include"menu.h" 
#include"dofile.h"
#include"administer.h"
#include"consumer.h"




//修改函数原型bool CheckCon(struct Master master, int number, char password[6]);
//修改函数原型bool CheckAdm(struct Master master, int account, char password[6]); 

//修改函数原型bool EnterAdm(struct Administer& administer, struct Apply_Node* apply, struct Consumer_Node* consumer);
//修改函数原型bool EnterCon(struct Consumer& consumer)

//修改函数原型bool ShowWindowAdm(struct Administer& administer, struct Apply_Node* apply, struct Consumer_Node* consumer);
//修改函数原型bool ShowWindowCon(struct Consumer& consumer);

//修改函数原型struct Consumer BuildCon(struct Master master, int number);
//修改函数原型struct Administer BuildAdm(struct Master master, int account, struct Apply_Node* apply);

//修改函数原型void UpdateAdm(bool judge, struct Master& master, struct Administer& administer);
//修改函数原型void UpdateCon(bool judge, struct Master& master, struct Consumer& consumer);



int ShowWindowMenu()
{
	struct Master master;
	ReadMaster(master, (char*)"./root.config");
	ReadAdm(master, (char*)"./administer.csv");
	ReadApply(master, (char*)"./apply.csv");
	ReadConsumer(master, (char*)"./consumer.csv");
	system("COLOR B9");
	system("cls");
	while (1) {
		printf("******************************************\n");
		printf("*                                        *\n");
		printf("*        欢迎使用购物卡管理系统！        *\n");
		printf("*                                        *\n");
		printf("*  请按下相应按键以选择你要进行的操作：  *\n");
		printf("*                                        *\n");
		printf("*           0.管理员登录                 *\n");
		printf("*                                        *\n");
		printf("*           1.用户登录                   *\n");
		printf("*                                        *\n");
		printf("*           2.购物卡申请                 *\n");
		printf("*                                        *\n");
		printf("*           3.管理员注册                 *\n");
		printf("*                                        *\n");
		printf("*           4.退出程序                   *\n");
		printf("*                                        *\n");
		printf("******************************************\n");
		float num;
		scanf("%f", &num);
		while (num != 0 && num != 1 && num != 2 && num != 3 && num != 4) {
			printf("错误，请重新选择\n");
			scanf("%f", &num);
		}
		if (num == 4) {//选择退出程序 
			WriteMaster(master, (char*)"./root.config");
			WriteAdm(master, (char*)"./administer.csv");
			WriteApply(master, (char*)"./apply.csv");
			WriteConsumer(master, (char*)"./consumer.csv");
			break;
		}
		else {//未选择退出程序 
			MainOperator(master, (int)num);
		}
	}
	printf("☆☆☆期待您的下次使用~☆☆☆\n");
	return 0;
}

void MainOperator(struct Master& master, int n) {
	int flag = 0;
	switch (n) {
	case 0:
		if (master.administer_->next_ == NULL) {
			system("cls");
			printf("当前没有管理员，请进行管理员注册！\n");
			break;
		}
		else flag = 1;
	case 1:
		if (master.consumer_->next_ == NULL && flag == 0) {
			system("cls");
			printf("当前没有用户，请申请购物卡！\n");
			break;
		}
		int account;//输入账号 
		char password[7]; //输入密码 
		password[6] = '\0';
		int i;
		while (1) {
			printf("请输入你的账号\n");
			scanf("%d", &account);	//输入账号
			if (account == 0) {
				break;
			}
			printf("请输入你的密码\n");
			while (getchar() != '\n');
			for (i = 0; i < 6; i++) {//输入密码 
				password[i] = getchar();
			}
			while (getchar() != '\n');
			if (n == 0) {//选择管理员登录 
				if (!CheckAdm(master, account, password)) {//账号密码错误 
					system("cls");
					printf("请重新输入账号密码或输入0返回上一界面\n");
				}
				else {//账号密码正确 
					system("cls");
					printf("管理员登陆成功！\n");
					struct Administer administer;
					administer = BuildAdm(master, account, master.apply_, master.consumer_);
					bool sign = EnterAdm(administer, master.apply_);
					UpdateAdm(master, sign, administer);
					break;
				}
			}
			if (n == 1) {//选择用户登录 
				if (!CheckCon(master, account, password)) {//账号密码错误 
					system("cls");
					printf("请重新输入账号密码或输入0返回上一界面\n");
				}
				else {//账号密码正确 
					system("cls");
					printf("用户登陆成功！\n");
					struct Consumer consumer;
					consumer = BuildCon(master, account);
					bool sign = EnterCon(consumer);
					UpdateCon(master, sign, consumer);
					break;
				}
			}
		}
		break;
	case 2://选择购物卡申请 
		AskCard(master.apply_);
		system("cls");
		printf("您的信息已提交\n");
		break;
	case 3:
		AdmSign(master);
		break;
	}
}



bool CheckPass(char number1[6], char number2[6]) {//判断密码是否正确 
	for (int i = 0; i < 6; i++) {
		if (number1[i] != number2[i]) {//如果密码某一位不匹配 
			system("cls");
			printf("密码错误\n");
			return	false;
		}
	}
	return true;
}

bool CheckCon(struct Master master, int number, char password[7]) {
	struct Consumer_Node* temp = master.consumer_->next_;
	while (temp) {//当master.consumer_为空，即已遍历完链表后退出 
		if (temp->number_ == number) {//匹配到账号 
			return CheckPass(password, temp->password_);
		}
		else {
			temp = temp->next_;//指针后移
		}
	}
	system("cls");
	printf("该账号不存在，请申请购物卡！\n");
	return false;
}

bool CheckAdm(struct Master master, int account, char password[7]) {
	struct Administer_Node* temp = master.administer_->next_;
	while (temp) {	//当master.administer_为空，即已遍历完链表后退出 
		if (temp->account_ == account) {	//匹配到账号 
			return CheckPass(password, temp->password_);
		}
		else {
			temp = temp->next_;//指针后移 
		}
	}
	system("cls");
	printf("该账号不存在，请进行注册！\n");
	return false;
}

struct Consumer BuildCon(struct Master master, int number) {
	while (master.consumer_) {	//当master.consumer_为空，即已遍历完链表后退出 
		if (master.consumer_->number_ == number) {//匹配到账号 
			return ToConsumer(*(master.consumer_));
		}
		else {
			master.consumer_ = master.consumer_->next_;//指针后移
		}
	}
	printf("ERROR\n");
	return ToConsumer(*(master.consumer_));
}

struct Administer BuildAdm(struct Master master, int account, struct Apply_Node* apply, struct Consumer_Node* consumer) {
	while (master.administer_) {//当master.administer_为空，即已遍历完链表后退出 
		if (master.administer_->account_ == account) {//匹配到账号 

			struct Administer administer = ToAdminister(*(master.administer_));
			administer.consumer_ = consumer;
			return administer;
		}
		else {
			master.administer_ = master.administer_->next_;//指针后移 
		}
	}
	printf("ERROR\n");
	return ToAdminister(*(master.administer_));
}

bool EnterAdm(struct Administer& administer, struct Apply_Node* apply) {
	return ShowWindowAdm(administer, apply);
}

bool EnterCon(struct Consumer& consumer) {
	return ShowWindowCon(consumer);
}

void UpdateAdm(struct Master& master, bool judge, struct Administer& administer) {
	if (judge == 1) {	//正常退出 
		struct Administer_Node* temp = master.administer_->next_;//创建临时指针 
		while (temp) {//当temp为空，即已遍历完链表后退出 
			if (temp->account_ == administer.account_) {	//匹配到账号 
				ToAdministerNode(*(temp), administer);
				return;
			}
			else {
				temp = temp->next_;//指针后移 
			}
		}
		printf("ERROR\n");
		return;
	}
	else {	//注销账号 
		struct Administer_Node* temp = master.administer_;//创建临时指针 
		while (temp->next_) {	//当temp->next_为空，即已遍历完链表后退出 
			if (temp->next_->account_ == administer.account_) {//匹配到账号(temp下一个指针的账号匹配） 
				struct Administer_Node* temp2 = temp->next_;
				temp->next_ = temp2->next_;
				free(temp2);
				printf("您的账号注销成功！\n");
				return;
			}
			else {
				temp = temp->next_;//指针后移 
			}
		}
		return;
	}
}

void UpdateCon(struct Master& master, bool judge, struct Consumer& consumer) {
	if (judge == 1) {	//正常退出 
		struct Consumer_Node* temp = master.consumer_->next_;//创建临时指针 
		while (temp) {//当temp为空，即已遍历完链表后退出 
			if (temp->number_ == consumer.number_) {//匹配到账号 
				ToConsumerNode(*(temp), consumer);
				return;
			}
			else {
				temp = temp->next_;//指针后移 
			}
		}
		printf("ERROR\n");
		return;
	}
	else { //注销账号
		struct Consumer_Node* temp = master.consumer_;//创建临时指针 
		while (temp->next_) {//当temp->next_为空，即已遍历完链表后退出 
			if (temp->next_->number_ == consumer.number_) {//匹配到账号(temp下一个指针的账号匹配） 
				struct Consumer_Node* temp2 = temp->next_;
				temp->next_ = temp2->next_;
				free(temp2);
				printf("您的账号注销成功！\n");
				return;
			}
			else {
				temp = temp->next_;//指针后移 
			}
		}
		return;
	}
}

struct Consumer ToConsumer(struct Consumer_Node consumer_) {
	struct Consumer consumer;
	consumer.number_ = consumer_.number_;
	for (int i = 0; i < 10; i++) {
		consumer.name_[i] = consumer_.name_[i];
	}
	for (int i = 0; i < 6; i++) {
		consumer.password_[i] = consumer_.password_[i];
	}
	consumer.password_[6] = '\0';
	for (int i = 0; i < 18; i++) {
		consumer.id_[i] = consumer_.id_[i];
	}
	consumer.id_[18] = '\0';
	consumer.balance_ = consumer_.balance_;
	consumer.score_ = consumer_.score_;
	consumer.is_available_ = consumer_.is_available_;
	return consumer;
}

struct Administer ToAdminister(struct Administer_Node administer_) {
	Administer administer;
	administer.account_ = administer_.account_;
	for (int i = 0; i < 6; i++) {
		administer.password_[i] = administer_.password_[i];
	}
	administer.password_[6] = '\0';
	administer.consumer_ = administer_.consumer_;
	return administer;
}

void ToConsumerNode(struct Consumer_Node& consumer_, struct Consumer consumer) {
	consumer_.number_ = consumer.number_;
	for (int i = 0; i < 10; i++) {
		consumer_.name_[i] = consumer.name_[i];
	}
	for (int i = 0; i < 6; i++) {
		consumer_.password_[i] = consumer.password_[i];
	}
	for (int i = 0; i < 18; i++) {
		consumer_.id_[i] = consumer.id_[i];
	}
	consumer_.balance_ = consumer.balance_;
	consumer_.score_ = consumer.score_;
	consumer_.is_available_ = consumer.is_available_;
}

void ToAdministerNode(struct Administer_Node& administer_, struct Administer administer) {
	administer_.account_ = administer.account_;
	for (int i = 0; i < 6; i++) {
		administer_.password_[i] = administer.password_[i];
	}
	administer_.consumer_ = administer.consumer_;
}

void AdmSign(struct Master& master) {
	system("cls");
	char n[7];
	while (1) {
		printf("请输入root密码（六位数字）：");
		scanf("%s", n);
		if (strlen(n) != 6) {
			printf("请输入正确的位数！\n");
		}
		else break;
	}
	n[6] = '\0';
	int root_p = ToInt(n);
	if (root_p == master.root_) {
		printf("请输入管理员账号：");
		int num;
		scanf("%d", &num);
		while (1) {
			printf("请输入管理员密码（六位）：");
			scanf("%s", n);
			if (strlen(n) != 6) {
				printf("请输入正确的位数！\n");
			}
			else break;
		}
		n[6] = '\0';
		struct Administer_Node* new_adm = (Administer_Node*)malloc(sizeof(Administer_Node));
		new_adm->account_ = num;
		for (int i = 0; i <= 6; i++) {
			new_adm->password_[i] = n[i];
		}
		new_adm->consumer_ = NULL;
		new_adm->next_ = master.administer_->next_;
		master.administer_->next_ = new_adm;
		system("cls");
		printf("管理员注册成功！\n");
		return;
	}
	else {
		system("cls");
		printf("root密码输入错误，注册被拒绝！\n");
		return;
	}
}

/*
int main(){
	int num=ShowWindowMenu();
	MainOperator(num);
	return 0;
}
*/
//测试程序 
