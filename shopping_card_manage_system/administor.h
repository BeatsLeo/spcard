#ifndef ADMINISTOR_H
#define ADMINISTOR_H
#include"consumer.h"

//管理员的信息链表
typedef struct
{
	int account_;	//账号
	char password_[6];	//密码
	Consumer_Node* consumer_;	//消费者链表

	Administer_Node* next_ = NULL;	//下一个节点位置
}Administer_Node;


//某一管理员的信息
typedef struct {
	int account_;	//账号
	char password_[6];	//密码
	Consumer_Node* consumer_ = NULL;	//消费者链表
}Administer;

void ShowWindowAdm();	//菜单窗口
void MakeCard(Apply_Node* card);	//制卡
void CheckApply(Apply_Node* apply);		//检查申请信息，并审批申请信息
void SendCard(Consumer_Node* card);		//发卡
void ShowInfo();		//查看信息
void ChangePsw();		//修改个人密码










#endif
