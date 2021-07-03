#ifndef ADMINISTOR_H
#define ADMINISTOR_H
#include"consumer.h"
//管理员结构体信息
typedef struct
{
	int account_;	//账号
	char password_[6];	//密码
	Consumer_Node* consumer_;	//消费者链表

	Administor_Node* next_;	//下一个节点位置

}Administor_Node;

void ShowWindow();	//菜单窗口
void CheckApply();	//检查申请信息，并审批申请信息
void MakeCard();	//制卡
void SendCard();	//发卡
void ShowInfo();	//查看信息
void ChangePsw();	//修改个人密码
void Quit();		//退出










#endif
