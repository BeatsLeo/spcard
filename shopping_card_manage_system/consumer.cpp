#include<stdio.h>
#include"consumer.h"
#pragma warning(disable:4996)

void BuyBySave(struct Consumer& consumer)
{

	if (consumer.is_available_ == 0)
	{
		printf("您的卡没有激活，请先进行激活操作！\n");        //是否激活 
	}

	else
	{
		int what, which = 1, number, flag, flag1, flag2;
		float total = 0, price, pri[9] = { 3,50,100,80,5,10,6000,50,7 };
		printf("*******************************************************************************\n");
		printf("*                          1--饮料----3.00元                                  *\n");
		printf("*                          2--耳机----50.00元                                 *\n");
		printf("*                          3--鼠标----100.00元                                *\n");
		printf("*                          4--键盘----80.00元                                 *\n");
		printf("*                          5--作业本--5.00元                                  *\n");
		printf("*                          6--笔------10.00元                                 *\n");
		printf("*                          7--电动车--6000.00元                               *\n");
		printf("*                          8--钢笔----50.00元                                 *\n");
		printf("*                          9--橡皮擦--7.00元                                  *\n");
		printf("*******************************************************************************\n");

		printf("您现在的余额为：%.2f\n", consumer.balance_);
		printf("请输入想购买物品所对应的代码(1~9)：");
		scanf("%d", &what);

		while (1)
		{
			if (which == what)
			{
				price = pri[which - 1];
				printf("请输入想购买的数量:");
				scanf("%d", &number);
				printf("选择了代码为%d的商品%d个,", what, number);
				printf("价格为:%.2f元\n", number * price);
				total += number * price;
				printf("是否继续选择(输入1表示继续，0表示结束):");
				scanf("%d", &flag1);
				while (flag1 != 0 && flag1 != 1)
				{
					printf("错误，请输入1或0：");
					scanf("%d", &flag1);
				}
				if (flag1 == 1)
				{
					which = 0;
					printf("请输入想购买物品所对应的代码(1~9)：");
					scanf("%d", &what);
				}
				else
				{
					printf("选中物品总计价格为：%.2f元\n", total);
					break;
				}
			}
			if (which >= 9)
			{
				printf("请输入正确代码(1~9)!\n");
				printf("是否继续购买(输入1表示继续，0表示结束):");
				scanf("%d", &flag);
				while (flag != 0 && flag != 1)
				{
					printf("错误，请输入1或0：");
					scanf("%d", &flag);
				}
				if (flag == 1)
				{
					printf("请输入想购买物品所对应的代码：");
					scanf("%d", &what);
					which = 0;
				}
				if (flag == 0)
				{
					printf("选中物品总计价格为：%.2f元\n", total);
					break;                        //回退到主界面，还要改 
				}
			}
			which++;
		}
		printf("是否确认购买(1表示确认，0表示退出):");
		scanf("%d", &flag2);
		while (flag2 != 0 && flag2 != 1)
		{
			printf("错误，请输入1或0：");
			scanf("%d", &flag2);
		}
		if (flag2 == 1)
		{
			MinusSave(consumer, total);
		}
		else
		{
			printf("退出购买\n");
		}
	}
}

void MinusSave(struct Consumer& consumer, float balance)
{
	if (consumer.balance_ < balance)
	{
		printf("购买无法完成，余额不足，请进行充值!\n");
		printf("您的余额为%.2f元,所需金额为%.2f元\n", consumer.balance_, balance);
	}
	else
	{
		consumer.balance_ -= balance;
		consumer.score_ += 0.3 * balance;
		printf("已完成购买，谢谢惠顾!\n");
		printf("本次购买一共花费%.2f元,余额为%.2f元\n", balance, consumer.balance_);
		printf("本次购买获得了%.2f的积分，您的积分为%.2f\n", 0.3 * balance, consumer.score_);
	}
}

void BuyByScore(struct Consumer& consumer)
{
	if (consumer.is_available_ == 0)
	{
		printf("您的卡没有激活，请先进行激活操作！\n");        //是否激活 
	}

	else
	{
		int what, which = 1, number, flag, flag1, flag2;
		float total = 0, price, pri[9] = { 3.30,55.00,110.00,88.00,5.50,11.00,6600.00,55.00,7.70 };
		printf("*********************************************************************************\n");
		printf("*                          1--饮料----3.30积分                                  *\n");
		printf("*                          2--耳机----55.00积分                                 *\n");
		printf("*                          3--鼠标----110.00积分                                *\n");
		printf("*                          4--键盘----88.00积分                                 *\n");
		printf("*                          5--作业本--5.50积分                                  *\n");
		printf("*                          6--笔------11.00积分                                 *\n");
		printf("*                          7--电动车--6600.00积分                               *\n");
		printf("*                          8--钢笔----55.00积分                                 *\n");
		printf("*                          9--橡皮擦--7.70积分                                  *\n");
		printf("*********************************************************************************\n");

		printf("您现在的积分为：%.2f\n", consumer.score_);
		printf("请输入想购买物品所对应的代码(1~9)：");
		scanf("%d", &what);

		while (1)
		{
			if (which == what)
			{
				price = pri[which - 1];
				printf("请输入想购买的数量:");
				scanf("%d", &number);
				printf("选择了代码为%d的商品%d个,", what, number);
				printf("需要:%.2f积分\n", number * price);
				total += number * price;
				printf("是否继续选择(输入1表示继续，0表示结束):");
				scanf("%d", &flag1);
				while (flag1 != 0 && flag1 != 1)
				{
					printf("错误，请输入1或0：");
					scanf("%d", &flag1);
				}
				if (flag1 == 1)
				{
					which = 0;
					printf("请输入想购买物品所对应的代码(1~9)：");
					scanf("%d", &what);
				}
				else
				{
					printf("总计所需要的积分为：%.2f\n", total);
					break;
				}
			}
			if (which == 9)
			{
				printf("请输入正确代码(1~9)!\n");
				printf("是否继续购买(输入1表示继续，0表示结束:");
				scanf("%d", &flag);
				while (flag != 0 && flag != 1)
				{
					printf("错误，请输入1或0：");
					scanf("%d", &flag);
				}
				if (flag == 1)
				{
					printf("请输入想购买物品所对应的代码：");
					scanf("%d", &what);
					which = 0;
				}
				if (flag == 0)
				{
					printf("总计所需要的积分为：%.2f\n", total);
					break;                        //回退到主界面，还要改 
				}
			}
			which++;
		}
		printf("是否确认购买(1表示确认，0表示退出):");
		scanf("%d", &flag2);
		while (flag2 != 0 && flag2 != 1)
		{
			printf("错误，请输入1或0：");
			scanf("%d", &flag2);
		}
		if (flag2 == 1)
		{
			MinusScore(consumer, total);
		}
		else
		{
			printf("退出购买\n");
		}
	}
}

void MinusScore(struct Consumer& consumer, float score)
{
	if (consumer.score_ < score)
	{
		printf("积分不足,消费来获取积分!\n");
		printf("您的积分为%.2f,所需积分为%.2f\n", consumer.score_, score);
	}
	else
	{
		consumer.score_ -= score;
		printf("已完成购买，谢谢惠顾!\n");
		printf("本次购买一共花费积分%.2f,积分余额为%.2f\n", score, consumer.score_);

	}
}

bool ShowWindowCon(struct Consumer& consumer) {
	if (!(consumer.is_available_)) {
		printf("您的账户未激活\n");
		printf("****************************\n");
		printf("*        　    　  　　  　　*\n");
		printf("*    1.存款（非法）      　　*\n");
		printf("*    2.存款交易（非法）      *\n");
		printf("*    3.积分交易（非法）      *\n");
		printf("*    4.报表                 *\n");
		printf("*    5.修改密码（非法）      *\n");
		printf("*    6.注销                 *\n");
		printf("*    7.退出                 *\n");//操作
		printf("*\n");
		printf("****************************\n");
		printf("    选择操作: ");
	}//选择操作数
	else {
		printf("您的账户已激活\n");
		printf("****************************\n");
		printf("*                          *\n");
		printf("*    1.存款                 *\n");
		printf("*    2.存款交易             *\n");
		printf("*    3.积分交易             *\n");
		printf("*    4.报表                 *\n");
		printf("*    5.修改密码             *\n");
		printf("*    6.注销                 *\n");
		printf("*    7.退出                 *\n");//操作
		printf("*                           *\n");
		printf("****************************\n");
		printf("    选择操作: ");
	}//选择操作数
	int n;//n表示操作数
	scanf("%d", &n);
	switch (n)
	{
	case 1://存款
		if (consumer.is_available_) {//如果用户已激活，则可以正常存款
			Save(consumer);//money表示存的钱
		}
		else { printf("请先激活您的账户 !\n"); };//若未激活，则提示存款操作非法
		break;
	case 2://存款交易
		if (consumer.is_available_) { BuyBySave(consumer); }//如果用户已激活，则可以正常交易
		else { printf("请先激活您的账户 !\n"); };//若未激活，则提示交易操作非法
		break;
	case 3://积分交易
		if (consumer.is_available_) { BuyByScore(consumer); }//如果用户已激活，则可以正常交易
		else { printf("请先激活您的账户 !\n"); };//若未激活，则提示交易操作非法
		break;
	case 4://报表
		ShowInfo(consumer);
		break;
	case 5://修改密码
		ChangePsw(consumer);
		// printf("%s\n",consumer.password_);
		break;
	case 6://注销
		printf("注销成功 !");
		return false;
		break;
	case 7://退出
		printf("已退出 !\n");
		return true;
		break;
	}
};

//存款函数
void Save(struct Consumer& consumer) {
	float money;//存的钱
	printf("Please input your money: ");
	scanf("%f", &money);
	printf("You seccessfully save %.2f dollor !\n", money);
	consumer.balance_ += money;
};


//报表函数
void ShowInfo(struct Consumer consumer) {
	printf("name: %s\n", consumer.name_);//姓名
	printf("id: %s\n", consumer.id_);//身份证
	printf("balance: %.2f\n", consumer.balance_);//余额
	printf("number: %d\n", consumer.number_);//卡号
	printf("score: %.2f\n", consumer.score_);//积分
	if (consumer.is_available_) { printf("Your card is valid !\n"); }
	else printf("Your card is invalid !\n");//是否激活
};


//修改密码函数
void ChangePsw(struct Consumer& consumer) {
	printf("New password: ");
	for (int i = 0; i <= 6; i++) {
		char ch;
		ch = getchar();
		consumer.password_[i] = ch;
	}//修改密码
};
