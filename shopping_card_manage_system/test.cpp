﻿#include<stdio.h>
#include"menu.h"
#include"dofile.h"
#pragma warning(disable:4996)

int main() {
	//Master master;
	//ReadAdm(master, (char*)"C:/Users/LENOVO/Desktop./asd.csv");
	//ReadApply(master, (char*)"C:/Users/LENOVO/Desktop./apply.csv");
	//ReadConsumer(master, (char*)"C:/Users/LENOVO/Desktop./consumer.csv");
	//printf("%d\t%s\n", master.administer_->next_->next_->account_, master.administer_->next_->next_->password_);
	//printf("%d\t%s\t%s\t%s\n", master.apply_->next_->next_->number_, master.apply_->next_->next_->name_, master.apply_->next_->next_->password_, master.apply_->next_->next_->id_);
	//printf("%d\t%s\t%s\t%s\t%.2f\t%.2f\t%d", master.consumer_->next_->next_->number_, master.consumer_->next_->next_->name_, master.consumer_->next_->next_->password_, master.consumer_->next_->next_->id_, master.consumer_->next_->next_->balance_, master.consumer_->next_->next_->score_, master.consumer_->next_->next_->is_available_);
	//WriteAdm(master, (char*)"C:/Users/LENOVO/Desktop./asd.csv");
	//WriteApply(master, (char*)"C:/Users/LENOVO/Desktop./apply.csv");
	//WriteConsumer(master, (char*)"C:/Users/LENOVO/Desktop./consumer.csv");

//测试：李浩宇
	//int n;
	//Consumer consumer;//实例化某个消费者对象
	//consumer.balance_ = 100;	//余额
	//consumer.score_ = 0;	//积分
	//consumer.is_available_ = 1;	//激活状态
	//while (1)
	//{
	//	ShowWindowCon(consumer);
	//	scanf("%d", &n);
	//	switch (n)
	//	{
	//	case 1:
	//		BuyBySave(consumer);
	//		break;
	//	case 2:
	//		BuyByScore(consumer);
	//		break;
	//	}
	//}

//测试：敖瑞成

	ShowWindowMenu();

	return 0;
}