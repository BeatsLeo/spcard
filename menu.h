#ifndef MENU_H
#define MENU_H
#include<stdio.h>
#include"consumer.h"
#include"administer.h"

//������Ϣ
struct Master {
	struct Administer_Node* administer_;	//����Ա����
	struct Consumer_Node* consumer_;	//����������
	struct Apply_Node* apply_;			//���￨������Ϣ����
	char path[100];				//�ļ�·��	
};

//���￨������Ϣ
struct Apply_Node {
	int number_;	//����
	char name_[10];	//����
	char password_[6];	//����
	char id_[18];	//���֤

	struct Apply_Node* next = NULL;	//��һ��ָ��
};


int ShowWindowMenu();	//�˵�����
void MainOperator(int n);	//������ҳ��
bool CheckCon(int number, char password[6]);	//����û��Ŀ����Ƿ���ڣ������ڣ���������Ƿ���ȷ
bool CheckAdm(int account, char password[6]);	//������Ա���˺��Ƿ���ڣ������ڣ���������Ƿ���ȷ

struct Consumer BuildCon(int number);	//�����¼�û�
struct Administer BuildAdm(int account, struct Apply_Node* apply);	//�����¼����Ա

void AskCard(struct Apply_Node* apply);	//���빺�￨
bool EnterAdm(struct Administer& administer, struct Apply_Node* apply);	//�������Ա��¼���������еĲ������ڸú�����ʵ��
bool EnterCon(struct Consumer& consumer);	//�����û���¼���������еĲ������ڸú�����ʵ��

void UpdateAdm(bool judge, struct Administer& administer);	//���½��������Ա��Ϣ
void UpdateCon(bool judge, struct Consumer& consumer);		//���½������û���Ϣ

#endif
