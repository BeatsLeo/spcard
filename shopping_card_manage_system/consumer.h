#ifndef CONSUMER_H
#define CONSUMER_H
#include"menu.h"
//某一用户的信息链表
struct Consumer_Node {
	int number_;	//卡号
	char name_[11];	//姓名
	char password_[7];	//密码
	char id_[19];	//身份证
	float balance_;	//余额
	float score_;	//积分
	bool is_available_;	//激活状态

	struct Consumer_Node* next_;	//下一个指针
};


//某一用户的信息
struct Consumer {
	int number_;	//卡号
	char name_[11];	//姓名
	char password_[7];	//密码
	char id_[19];	//身份证
	float balance_;	//余额
	float score_;	//积分
	bool is_available_;	//激活状态
};

bool ShowWindowCon(struct Consumer& consumer);						//菜单窗口
void ShowInfo(struct Consumer consumer);			//报表，显示信息
void ChangePsw(struct Consumer& consumer);			//修改密码
void Save(struct Consumer& consumer);				//存款
void BuyBySave(struct Consumer& consumer);			//余额交易
void MinusSave(struct Consumer& consumer, float balance);	//扣除余额
void BuyByScore(struct Consumer& consumer);		//积分交易
void MinusScore(struct Consumer& consumer, float score);		//扣除积分





#endif
