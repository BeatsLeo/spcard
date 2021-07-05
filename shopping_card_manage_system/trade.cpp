#include<stdio.h>
#include"consumer.h"


void BuyBySave(struct Consumer consumer)  
{
	
	if(consumer.is_available_==0)
	{
		printf("您的卡没有激活，请先进行激活操作！\n");        //是否激活 
	}
	
	else
	{
		int what,which=1,number,flag,flag1,flag2;
		float total=0,price,pri[9]={3,50,100,80,5,10,6000,50,7};
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
		
		printf("请输入想购买物品所对应的代码(1~9)：");
		scanf("%d",&what); 	
		
		while(1)
		{
			if(which == what)
			{
				price=pri[which-1];
				printf("请输入想购买的数量:");
				scanf("%d",&number);
				printf("选择了代码为%d的商品%d个,",what,number);
				printf("价格为:%.2f元\n",number * price);
				total += number * price;
				printf("是否继续选择(输入1表示继续，0表示结束):");
				scanf("%d",&flag1);
				while(flag1!=0&&flag1!=1)
				{
					printf("错误，请输入1或0：");
					scanf("%d",&flag1);
		  	    }
				if(flag1 == 1)
				{
					which=0;
					printf("请输入想购买物品所对应的代码(1~9)：");
					scanf("%d",&what); 	
				}
				else
				{
					printf("选中物品总计价格为：%.2f元\n",total);
					break;
				}
			}
			if(which >= 9)
			{
				printf("请输入正确代码(1~9)!\n");
				printf("是否继续购买(输入1表示继续，0表示结束):");
				scanf("%d",&flag);
				while(flag!=0&&flag!=1)
				{
					printf("错误，请输入1或0：");
					scanf("%d",&flag);
		 	    }
				if(flag == 1)
				{
					printf("请输入想购买物品所对应的代码：");
					scanf("%d",&what);
					which=0;
				}
				if(flag == 0)
				{
					printf("选中物品总计价格为：%.2f元\n",total);   
					break;                        //回退到主界面，还要改 
				}	
			}
		which++;
		}
		printf("是否确认购买(1表示确认，0表示退出):");
		scanf("%d",&flag2);
		while(flag2!=0&&flag2!=1)
		{
			printf("错误，请输入1或0：");
			scanf("%d",&flag2);
		}
		if(flag2==1)
		{
			MinusSave(consumer,total);
		}
		else
		{
			printf("退出购买\n");
		}	
	}
}

void MinusSave(struct Consumer consumer, float balance)
{
	if(consumer.balance_<balance)
	{
		printf("购买无法完成，余额不足，请进行充值!\n");
		printf("您的余额为%.2f元,所需金额为%.2f元\n",consumer.balance_,balance);
	}
	else
	{
		consumer.balance_ -= balance;
		consumer.score_ += 0.3 * balance;
		printf("已完成购买，谢谢惠顾!\n");
		printf("本次购买一共花费%.2f元,余额为%.2f元\n",balance,consumer.balance_);
		printf("本次购买获得了%.2f的积分，您的积分为%.2f\n",0.3*balance,consumer.score_);
	}
}

void BuyByScore(struct Consumer consumer)
{
	if(consumer.is_available_==0)
	{
		printf("您的卡没有激活，请先进行激活操作！\n");        //是否激活 
	}
	
    else
	{
		int what,which=1,number,flag,flag1,flag2;
		float total=0,price,pri[9]={3.30,55.00,110.00,88.00,5.50,11.00,6600.00,55.00,7.70};
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
	
		printf("请输入想购买物品所对应的代码(1~9)：");
		scanf("%d",&what); 	
	
		while(1)
		{
			if(which == what)
			{
				price=pri[which-1];
				printf("请输入想购买的数量:");
				scanf("%d",&number);
				printf("选择了代码为%d的商品%d个,",what,number);
				printf("需要:%.2f积分\n",number * price);
				total += number * price;
				printf("是否继续选择(输入1表示继续，0表示结束):");
				scanf("%d",&flag1);
				while(flag1!=0&&flag1!=1)
				{
					printf("错误，请输入1或0：");
					scanf("%d",&flag1);
				}
				if(flag1 == 1)
				{
					which=0;
					printf("请输入想购买物品所对应的代码(1~9)：");
					scanf("%d",&what); 	
				}
				else
				{
					printf("总计所需要的积分为：%.2f\n",total);
					break;
				}
			}
			if(which == 9)
			{
				printf("请输入正确代码(1~9)!\n");
				printf("是否继续购买(输入1表示继续，0表示结束:");
				scanf("%d",&flag);
				while(flag!=0&&flag!=1)
				{
					printf("错误，请输入1或0：");
					scanf("%d",&flag);
				}
				if(flag == 1)
				{
					printf("请输入想购买物品所对应的代码：");
					scanf("%d",&what);
					which=0;
				}
				if(flag == 0)
				{
					printf("总计所需要的积分为：%.2f\n",total);   
					break;                        //回退到主界面，还要改 
				}	
			}
			which++;
		}
		printf("是否确认购买(1表示确认，0表示退出):");
		scanf("%d",&flag2);
		while(flag2!=0&&flag2!=1)
		{
			printf("错误，请输入1或0：");
			scanf("%d",&flag2);
		}
		if(flag2==1)
		{
			MinusScore(consumer,total);
		}
		else
		{
			printf("退出购买\n");
		}	
	}
}

void MinusScore(struct Consumer consumer, float score)
{
	if(consumer.score_<score)
	{
		printf("积分不足,消费来获取积分!\n");
		printf("您的积分为%.2f,所需积分为%.2f\n",consumer.score_,score);
	}
	else
	{
		consumer.score_ -= score;
		printf("已完成购买，谢谢惠顾!\n");
		printf("本次购买一共花费积分%.2f,积分余额为%.2f\n",score,consumer.score_);

	}
}


void ShowWindowCon(struct Consumer consumer){
        printf("****************************\n");
        printf("*\n");
        printf("*    1.余额\n*    2.积分\n*    ");
        printf("*\n");
        printf("****************************\n");
        printf("*    Please choose operator: ");//选择操作数
};

int main(void){
    int n;
    Consumer consumer;//实例化某个消费者对象
    consumer.balance_ =100 ;	//余额
	consumer.score_ =0;	//积分
	consumer.is_available_=1;	//激活状态
    while(1)
	{
		ShowWindowCon(consumer);
		scanf("%d",&n);
		switch (n)
        {
        case 1:
            BuyBySave(consumer);
			break;
        case 2:
			BuyByScore(consumer);
            break;
        }
    }
}
