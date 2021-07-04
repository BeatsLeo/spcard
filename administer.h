#ifndef ADMINISTOR_H
#define ADMINISTOR_H
#include"menu.h"

//管理员的信息链表
struct Administer_Node {
	int account_;	//账号
	char password_[6];	//密码
	struct Consumer_Node* consumer_;	//消费者链表

	struct Administer_Node* next_ = NULL;	//下一个节点位置
};


//某一管理员的信息
struct Administer {
	int account_;	//账号
	char password_[6];	//密码
	struct Consumer_Node* consumer_ = NULL;	//消费者链表
};

void ShowWindowAdm();	//菜单窗口
void MakeCard(struct Apply_Node* card);	//制卡
void CheckApply(struct Apply_Node* apply);		//检查申请信息，并审批申请信息
void SendCard(struct Consumer_Node* card);		//发卡
void ShowInfo();		//查看信息
void ChangePsw();		//修改个人密码










#endif
