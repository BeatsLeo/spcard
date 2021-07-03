#ifndef MENU_H
#define MENU_H
#include<stdio.h>
#include"consumer.h"
#include"administor.h"
typedef struct {
	Administor_Node* admin_;	//管理员链表
	Consumer_Node* consumer_;	//消费者链表
}Master;

typedef struct {
	int number_;	//卡号
	char name_[10];	//姓名
	char password_[6];	//密码
	char id_[18];	//身份证
}Apply;

int ShowWindow();	//菜单窗口
void MainOperator(int n);	//主操作页面
Apply* AskCard();	//申请购物卡

#endif
