#include<stdio.h>
//#include<stdlib.h>
//#include"consumer.h"

double BuyBySave()  //struct Consumer& consumer
{
	int what,which=1,number,flag,flag1;
	double total=0,price,pri[9]={3,50,100,80,5,10,6000,50,7};
	printf("****************************************************************************\n");
	printf("*                          1--饮料----3.00元                                  *\n");
	printf("*                          2--耳机----50.00元                                 *\n");
	printf("*                          3--鼠标----100.00元                                *\n");
	printf("*                          4--键盘----80.00元                                 *\n");
	printf("*                          5--作业本--5.00元                                  *\n");
	printf("*                          6--笔------10.00元                                 *\n");
	printf("*                          7--电动车--6000.00元                               *\n");
	printf("*                          8--钢笔----50.00元                                 *\n");
	printf("*                          9--橡皮擦--7.00元                                  *\n");
	printf("****************************************************************************\n");
	
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
				printf("选中物品总计价格为：%.2f元",total);
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
				printf("选中物品总计价格为：%.2f元",total);   
				break;                        //回退到主界面，还要改 
			}	
		}
	which++;
	}	
	return  number * price;
}
double BuyByScore()
{
	int what,which=1,number,flag,flag1;
	double total=0,price,pri[9]={3.30,55.00,110.00,88.00,5.50,11.00,6600.00,55.00,7.70};
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
				printf("总计所需要的积分为：%.2f积分",total);
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
				printf("总计所需要的积分为：%.2f积分",total);   
				break;                        //回退到主界面，还要改 
			}	
		}
	which++;
	}	
	return  number * price;
}


int main()
{
//	Consumer_Node* next_ = NULL;
//	next_ = (Consumer_Node *)malloc(sizeof(Consumer_Node));
BuyBySave();
//BuyByScore(); 
return 0;
}
