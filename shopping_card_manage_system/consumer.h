#ifndef CONSUMER_H
#define CONSUMER_H

typedef struct {
	int number_;	//卡号
	char name_[10];	//姓名
	char password_[6];	//密码
	char id_[18];	//身份证
	float balance_;	//余额
	int score_;	//积分
	bool is_available_;	//激活状态

	Consumer_Node* next_;	//下一个指针
}Consumer_Node;

void ShowWindow();	//菜单窗口
Consumer_Node* Build(Consumer_Node* user);	//传入本用户
void ShowInfo(Consumer_Node* user);			//报表，显示信息
void ChangePsw(Consumer_Node* user);		//修改密码
void Save(Consumer_Node* user);				//存款
void BuyBySave(Consumer_Node* user);		//余额交易
void BuyByScore(Consumer_Node* user);		//积分交易	
void Delete(Consumer_Node* user);			//注销
void Quit(Consumer_Node* user);				//退出







#endif
