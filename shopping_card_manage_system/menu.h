#ifndef MENU_H
#define MENU_H
#include<stdio.h>
#include"consumer.h"
#include"administer.h"

//所有信息
struct Master {
	struct Administer_Node* administer_;	//管理员链表
	struct Consumer_Node* consumer_;	//消费者链表
	struct Apply_Node* apply_;			//购物卡申请信息链表
	char path_[100];				//文件路径	
	int root_;						//root密码
};

//购物卡申请信息
struct Apply_Node {
	int number_;	//卡号
	char name_[11];	//姓名
	char password_[7];	//密码
	char id_[19];	//身份证

	struct Apply_Node* next_ = NULL;	//下一个指针
};


int ShowWindowMenu();	//菜单窗口
void MainOperator(struct Master& master, int n);	//主操作页面
bool CheckCon(struct Master master, int number, char password[7]);	//检查用户的卡号是否存在，若存在，检查密码是否正确
bool CheckAdm(struct Master master, int account, char password[7]);	//检查管理员的账号是否存在，若存在，检查密码是否正确

struct Consumer BuildCon(struct Master master, int number);	//传入登录用户
struct Administer BuildAdm(struct Master master, int account, struct Apply_Node* apply, struct Consumer_Node* consumer);	//传入登录管理员

void AskCard(struct Apply_Node* apply);	//申请购物卡
bool EnterAdm(struct Administer& administer, struct Apply_Node* apply);	//进入管理员登录函数，所有的操作都在该函数内实现
bool EnterCon(struct Consumer& consumer);	//进入用户登录函数，所有的操作都在该函数内实现

void UpdateAdm(struct Master&, bool judge, struct Administer& administer);	//更新结束后管理员信息
void UpdateCon(struct Master&, bool judge, struct Consumer& consumer);		//更新结束后用户信息

bool CheckPass(char number1[7], char number2[7]);	//判断密码是否正确 

void AdmSign(struct Master&);	//管理员注册


struct Consumer ToConsumer(struct Consumer_Node consumer_);//将Consumer_Node类型转化为Consumer类型 
struct Administer ToAdminister(struct Administer_Node administer_);//将Administer_Node类型转化为Administer类型 
void ToConsumerNode(struct Consumer_Node& consumer_, struct Consumer consumer);// 将Consumer类型的数据称传递给Consumer_Node 
void ToAdministerNode(struct Administer_Node& administer_, struct Administer administer);//Administer类型的数据成员传递给Administer_Node

#endif
