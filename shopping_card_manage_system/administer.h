#ifndef ADMINISTER_H
#define ADMINISTER_H
#include"menu.h"

//管理员的信息链表
struct Administer_Node {
	int account_;	//账号
	char password_[7];	//密码
	struct Consumer_Node* consumer_;	//消费者链表

	struct Administer_Node* next_ = NULL;	//下一个节点位置
};


//某一管理员的信息
struct Administer {
	int account_;	//账号
	char password_[7];	//密码
	struct Consumer_Node* consumer_ = NULL;	//消费者链表
};

bool ShowWindowAdm(struct Administer& administer, struct Apply_Node* apply);	//菜单窗口
void MakeCard(struct Administer& administer, struct Apply_Node* card);	//制卡
void CheckApply(struct Administer& administer, struct Apply_Node* apply);		//检查申请信息，并审批申请信息
void SendCard(struct Administer& administer);		//发卡
void ShowInfo(struct Administer& administer);		//查看信息
void ChangePsw(struct Administer& administer);		//修改个人密码










#endif
