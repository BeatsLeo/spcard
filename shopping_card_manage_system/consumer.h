#ifndef CONSUMER_H
#define CONSUMER_H
#include"menu.h"
//ĳһ�û�����Ϣ����
struct Consumer_Node {
	int number_;	//����
	char name_[10];	//����
	char password_[6];	//����
	char id_[18];	//���֤
	float balance_ = 0;	//���
	float score_ = 0;	//����
	bool is_available_;	//����״̬

	struct Consumer_Node* next_ = NULL;	//��һ��ָ��
};


//ĳһ�û�����Ϣ
struct Consumer {
	int number_;	//����
	char name_[10];	//����
	char password_[6];	//����
	char id_[18];	//���֤
	float balance_ = 100;	//���
	float score_ = 100;	//����
	bool is_available_=1;	//����״̬
};

void ShowWindowCon();						//�˵�����
void ShowInfo(struct Consumer consumer);			//������ʾ��Ϣ
void ChangePsw(struct Consumer& consumer);			//�޸�����
void Save(struct Consumer& consumer);				//���
void BuyBySave(struct Consumer&  consumer);			//����
void MinusSave(struct Consumer consumer, float balance);	//�۳����
void BuyByScore(struct Consumer consumer);		//���ֽ���
void MinusScore(struct Consumer consumer, float score);		//�۳�����





#endif
