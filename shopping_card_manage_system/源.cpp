//#include<stdio.h>
//#include"administer.h"
//#include"consumer.h"
//#include"menu.h"
//#include"dofile.h"
//
//bool ShowWindowCon(struct Consumer& consumer) {
//	if (!(consumer.is_available_)) {
//		printf("Your account is invalid\n");
//		printf("****************************\n");
//		printf("*\n");
//		printf("*    1.save (invalid)\n*    2.pay(invalid)\n*    3.show\n*    4.change code(invalid)\n*    5.delete\n*    6.quit\n");//操作
//		printf("*\n");
//		printf("****************************\n");
//		printf("*    Please choose operator: ");
//	}//选择操作数
//	else {
//		printf("Your account is valid\n");
//		printf("****************************\n");
//		printf("*\n");
//		printf("*    1.save\n*    2.pay\n*    3.show\n*    4.change code\n*    5.delete\n*    6.quit\n");//操作
//		printf("*\n");
//		printf("****************************\n");
//		printf("*    Please choose operator: ");//选择操作数
//	}
//	int n;//n表示操作数
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		if (consumer.is_available_) {
//			Save(consumer);//money表示存的钱
//		}
//		else { printf("Pelase activate your code first !\n"); };
//		break;
//	case 2:
//		if (consumer.is_available_) { Pay(consumer); }
//		else { printf("Pelase activate your code first !\n"); };
//		break;
//	case 3:
//		ShowInfo(consumer);
//		break;
//	case 4://修改密码
//		ChangePsw(consumer);
//		// printf("%s\n",consumer.password_);
//		break;
//	case 5://注销
//		printf("You succeesfully delete yourself !");
//		return false;
//		break;
//	case 6://退出
//		printf("You succeesfully quit !\n");
//		return true;
//		break;
//	}
//};
//
////存款函数
//void Save(struct Consumer& consumer) {
//	float money;//存的钱
//	printf("Please input your money: ");
//	scanf("%f", &money);
//	printf("You seccessfully save %.2f dollor !\n", money);
//	consumer.balance_ += money;
//};
//
////付款函数
//void Pay(struct Consumer consumer) { return; };//函数体由李浩宇完成
//
////报表函数
//void ShowInfo(struct Consumer consumer) {
//	printf("name: %s\n", consumer.name_);//姓名
//	printf("id: %s\n", consumer.id_);//身份证
//	printf("balance: %.2f\n", consumer.balance_);//余额
//	printf("number: %d\n", consumer.number_);//卡号
//	printf("score: %.2f\n", consumer.score_);//积分
//	if (consumer.is_available_) { printf("Your card is valid !\n"); }
//	else printf("Your card is invalid !\n");//是否激活
//};
//
////注销函数
//void Delete(struct Consumer consumer) {};
//
//
//int main(void) {
//	Consumer consumer;//实例化某个消费者对象
//	for (;;) {
//		ShowWindowCon(consumer);//窗口显示
//	}
//}
