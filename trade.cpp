#include<stdio.h>
//#include<stdlib.h>
//#include"consumer.h"

double BuyBySave()  //struct Consumer& consumer
{
	int what,which=1,number,flag,flag1;
	double total=0,price,pri[9]={3,50,100,80,5,10,6000,50,7};
	printf("****************************************************************************\n");
	printf("*                          1--����----3.00Ԫ                                  *\n");
	printf("*                          2--����----50.00Ԫ                                 *\n");
	printf("*                          3--���----100.00Ԫ                                *\n");
	printf("*                          4--����----80.00Ԫ                                 *\n");
	printf("*                          5--��ҵ��--5.00Ԫ                                  *\n");
	printf("*                          6--��------10.00Ԫ                                 *\n");
	printf("*                          7--�綯��--6000.00Ԫ                               *\n");
	printf("*                          8--�ֱ�----50.00Ԫ                                 *\n");
	printf("*                          9--��Ƥ��--7.00Ԫ                                  *\n");
	printf("****************************************************************************\n");
	
	printf("�������빺����Ʒ����Ӧ�Ĵ���(1~9)��");
	scanf("%d",&what); 	
	while(1)
	{
		if(which == what)
		{
			price=pri[which-1];
			printf("�������빺�������:");
			scanf("%d",&number);
			printf("ѡ���˴���Ϊ%d����Ʒ%d��,",what,number);
			printf("�۸�Ϊ:%.2fԪ\n",number * price);
			total += number * price;
			printf("�Ƿ����ѡ��(����1��ʾ������0��ʾ����):");
			scanf("%d",&flag1);
			while(flag1!=0&&flag1!=1)
			{
				printf("����������1��0��");
				scanf("%d",&flag1);
		    }
			if(flag1 == 1)
			{
				which=0;
				printf("�������빺����Ʒ����Ӧ�Ĵ���(1~9)��");
				scanf("%d",&what); 	
			}
			else
			{
				printf("ѡ����Ʒ�ܼƼ۸�Ϊ��%.2fԪ",total);
				break;
			}
		}
		if(which >= 9)
		{
			printf("��������ȷ����(1~9)!\n");
			printf("�Ƿ��������(����1��ʾ������0��ʾ����):");
			scanf("%d",&flag);
			while(flag!=0&&flag!=1)
			{
				printf("����������1��0��");
				scanf("%d",&flag);
		    }
			if(flag == 1)
			{
				printf("�������빺����Ʒ����Ӧ�Ĵ��룺");
				scanf("%d",&what);
				which=0;
			}
			if(flag == 0)
			{
				printf("ѡ����Ʒ�ܼƼ۸�Ϊ��%.2fԪ",total);   
				break;                        //���˵������棬��Ҫ�� 
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
	printf("*                          1--����----3.30����                                  *\n");
	printf("*                          2--����----55.00����                                 *\n");
	printf("*                          3--���----110.00����                                *\n");
	printf("*                          4--����----88.00����                                 *\n");
	printf("*                          5--��ҵ��--5.50����                                  *\n");
	printf("*                          6--��------11.00����                                 *\n");
	printf("*                          7--�綯��--6600.00����                               *\n");
	printf("*                          8--�ֱ�----55.00����                                 *\n");
	printf("*                          9--��Ƥ��--7.70����                                  *\n");
	printf("*********************************************************************************\n");
	
	printf("�������빺����Ʒ����Ӧ�Ĵ���(1~9)��");
	scanf("%d",&what); 	
	
	while(1)
	{
		if(which == what)
		{
			price=pri[which-1];
			printf("�������빺�������:");
			scanf("%d",&number);
			printf("ѡ���˴���Ϊ%d����Ʒ%d��,",what,number);
			printf("��Ҫ:%.2f����\n",number * price);
			total += number * price;
			printf("�Ƿ����ѡ��(����1��ʾ������0��ʾ����):");
			scanf("%d",&flag1);
			while(flag1!=0&&flag1!=1)
			{
				printf("����������1��0��");
				scanf("%d",&flag1);
			}
			if(flag1 == 1)
			{
				which=0;
				printf("�������빺����Ʒ����Ӧ�Ĵ���(1~9)��");
				scanf("%d",&what); 	
			}
			else
			{
				printf("�ܼ�����Ҫ�Ļ���Ϊ��%.2f����",total);
				break;
			}
		}
		if(which == 9)
		{
			printf("��������ȷ����(1~9)!\n");
			printf("�Ƿ��������(����1��ʾ������0��ʾ����:");
			scanf("%d",&flag);
			while(flag!=0&&flag!=1)
			{
				printf("����������1��0��");
				scanf("%d",&flag);
			}
			if(flag == 1)
			{
				printf("�������빺����Ʒ����Ӧ�Ĵ��룺");
				scanf("%d",&what);
				which=0;
			}
			if(flag == 0)
			{
				printf("�ܼ�����Ҫ�Ļ���Ϊ��%.2f����",total);   
				break;                        //���˵������棬��Ҫ�� 
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
