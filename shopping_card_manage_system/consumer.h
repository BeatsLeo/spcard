#ifndef CONSUMER_H
#define CONSUMER_H

//某一用户的信息链表
typedef struct {
	int number_;	//卡号
	char name_[10];	//姓名
	char password_[6];	//密码
	char id_[18];	//身份证
	float balance_;	//余额
	int score_;	//积分
	bool is_available_;	//激活状态

	Consumer_Node* next_ = NULL;	//下一个指针
}Consumer_Node;

//某一用户的信息
typedef struct {
	int number_;	//卡号
	char name_[10];	//姓名
	char password_[6];	//密码
	char id_[18];	//身份证
	float balance_;	//余额
	int score_;	//积分
	bool is_available_;	//激活状态
}Consumer;

void ShowWindowCon();						//菜单窗口
void ShowInfo(Consumer consumer);			//报表，显示信息
void ChangePsw(Consumer& consumer);			//修改密码
void Save(Consumer& consumer);				//存款
void BuyBySave(Consumer& consumer);			//余额交易
void MinusSave(Consumer& consumer, float balance);	//扣除余额
void BuyByScore(Consumer& consumer);		//积分交易
void MinusScore(Consumer& consumer, int score);		//扣除积分





#endif
