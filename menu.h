#ifndef MENU_H
#define MENU_H
#include<stdio.h>
#include"consumer.h"
#include"administor.h"

//所有信息
typedef struct {
	Administer_Node* administer_;	//管理员链表
	Consumer_Node* consumer_;	//消费者链表
	Apply_Node* apply_;			//购物卡申请信息链表
	char path[100];				//文件路径	
}Master;

//购物卡申请信息
typedef struct {
	int number_;	//卡号
	char name_[10];	//姓名
	char password_[6];	//密码
	char id_[18];	//身份证

	Apply_Node* next = NULL;	//下一个指针
}Apply_Node;


int ShowWindowMenu();	//菜单窗口
void MainOperator(int n);	//主操作页面
bool CheckCon(int number, char password[6]);	//检查用户的卡号是否存在，若存在，检查密码是否正确
bool CheckAdm(int account, char password[6]);	//检查管理员的账号是否存在，若存在，检查密码是否正确

Consumer BuildCon(int number);	//传入登录用户
Administer BuildAdm(int account, Apply_Node* apply);	//传入登录管理员

void AskCard(Apply_Node* apply);	//申请购物卡
bool EnterAdm(Administer& administer, Apply_Node* apply);	//进入管理员登录函数，所有的操作都在该函数内实现
bool EnterCon(Consumer& consumer);	//进入用户登录函数，所有的操作都在该函数内实现

void UpdateAdm(bool judge, Administer& administer);	//更新结束后管理员信息
void UpdateCon(bool judge, Consumer& consumer);		//更新结束后用户信息

#endif
