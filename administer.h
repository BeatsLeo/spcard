#ifndef ADMINISTOR_H
#define ADMINISTOR_H
#include"menu.h"

//����Ա����Ϣ����
struct Administer_Node {
	int account_;	//�˺�
	char password_[6];	//����
	struct Consumer_Node* consumer_;	//����������

	struct Administer_Node* next_ = NULL;	//��һ���ڵ�λ��
};


//ĳһ����Ա����Ϣ
struct Administer {
	int account_;	//�˺�
	char password_[6];	//����
	struct Consumer_Node* consumer_ = NULL;	//����������
};

void ShowWindowAdm();	//�˵�����
void MakeCard(struct Apply_Node* card);	//�ƿ�
void CheckApply(struct Apply_Node* apply);		//���������Ϣ��������������Ϣ
void SendCard(struct Consumer_Node* card);		//����
void ShowInfo();		//�鿴��Ϣ
void ChangePsw();		//�޸ĸ�������










#endif
