#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include"dofile.h"
#include<string.h>
//读取管理员文件
void ReadAdm(struct Master& master, char path[100]) {
	FILE* read_adm = NULL;
	fopen_s(&read_adm, path, "r");	//只读打开文件
	if (read_adm == NULL) {
		printf("该文件不存在！");		//错误检测
	}
	else {
		char tem[128];
		fscanf(read_adm, "%s", tem);	//读掉表头
		master.administer_ = (struct Administer_Node*)malloc(sizeof(struct Administer_Node));	//建立头节点
		master.administer_->next_ = NULL;
		struct Administer_Node* tmp = (struct Administer_Node*)malloc(sizeof(struct Administer_Node));	//建立第二个节点
		while (fscanf(read_adm, "%s", tem) != -1)	//挨个读取
		{
			char account[11], password[7];
			int k = 0;
			for (int i = 0; i < strlen(tem); i++) {
				if (tem[i] == ',') {
					account[i] = '\0';
					k = i + 1;
					break;
				}
				else {
					account[i] = tem[i];
				}
			}
			for (int i = 0; i < strlen(tem) - k; i++) {
				password[i] = tem[k + i];
			}
			password[6] = '\0';
			//给对应参数赋值
			tmp->account_ = ToInt(account);
			strcpy(tmp->password_, password);
			tmp->next_ = NULL;		//将下一个节点指向NULL
			tmp->consumer_ = NULL;	//将consumer_指向NULL
			tmp->next_ = master.administer_->next_;
			master.administer_->next_ = tmp;
			tmp = (struct Administer_Node*)malloc(sizeof(struct Administer_Node));
		}
	}
	fclose(read_adm);
}
//写入管理员文件
void WriteAdm(struct Master& master, char path[100]) {
	FILE* write_adm = NULL;
	fopen_s(&write_adm, path, "w");	//截断打开文件
	if (write_adm == NULL) {
		printf("该文件不存在！");		//错误检测
	}
	fprintf(write_adm, "%s", "账号,密码\n");
	Administer_Node* iter = master.administer_->next_;
	for (; iter != NULL; iter = iter->next_) {
		fprintf(write_adm, "%d,%s\n", iter->account_, iter->password_);
	}
}
//读取购物卡申请文件
void ReadApply(struct Master& master, char path[100]) {
	FILE* read_apply = NULL;
	fopen_s(&read_apply, path, "r");	//只读打开文件
	if (read_apply == NULL) {
		printf("该文件不存在！");		//错误检测
	}
	else {
		char tem[128];
		fscanf(read_apply, "%s", tem);	//读掉表头
		master.apply_ = (struct Apply_Node*)malloc(sizeof(struct Apply_Node));	//建立头节点
		master.apply_->next_ = NULL;
		struct Apply_Node* tmp = (struct Apply_Node*)malloc(sizeof(struct Apply_Node));	//建立第二个节点
		while (fscanf(read_apply, "%s", tem) != -1)	//挨个读取
		{
			char info[4][19];	//0：卡号，1：姓名:2：密码，3：身份证
			int k = 0, times = 0;
			for (int i = 0; i < strlen(tem); i++) {
				if (tem[i] == ',') {
					int pos = 0;
					for (int j = k; j < i; j++, pos++) {
						info[times][pos] = tem[j];
					}
					info[times][pos] = '\0';
					k = i + 1;
					times++;
				}
			}
			//处理最后一项
			int pos = 0;
			for (int i = k; i < strlen(tem); i++, pos++) {
				info[times][pos] = tem[i];
			}
			info[times][pos] = '\0';
			//给对应参数赋值
			tmp->number_ = ToInt(info[0]);
			strcpy(tmp->name_, info[1]);
			strcpy(tmp->password_, info[2]);
			strcpy(tmp->id_, info[3]);
			tmp->next_ = master.apply_->next_;
			master.apply_->next_ = tmp;
			tmp = (struct Apply_Node*)malloc(sizeof(struct Apply_Node));
		}
	}
	fclose(read_apply);
}
//写入购物卡申请文件
void WriteApply(struct Master& master, char path[100]) {
	FILE* write_apply = NULL;
	fopen_s(&write_apply, path, "w");	//截断打开文件
	if (write_apply == NULL) {
		printf("该文件不存在！");		//错误检测
	}
	fprintf(write_apply, "%s", "卡号,姓名,密码,身份证\n");
	Apply_Node* iter = master.apply_->next_;
	for (; iter != NULL; iter = iter->next_) {
		fprintf(write_apply, "%d,%s,%s,%s\n", iter->number_, iter->name_, iter->password_, iter->id_);
	}
}
//读取用户信息文件
void ReadConsumer(struct Master& master, char path[100]) {
	FILE* read_consumer = NULL;
	fopen_s(&read_consumer, path, "r");	//只读打开文件
	if (read_consumer == NULL) {
		printf("该文件不存在！");		//错误检测
	}
	else {
		char tem[128];
		fscanf(read_consumer, "%s", tem);	//读掉表头
		master.consumer_ = (struct Consumer_Node*)malloc(sizeof(struct Consumer_Node));	//建立头节点
		master.consumer_->next_ = NULL;
		struct Consumer_Node* tmp = (struct Consumer_Node*)malloc(sizeof(struct Consumer_Node));	//建立第二个节点
		while (fscanf(read_consumer, "%s", tem) != -1)	//挨个读取
		{
			char info[7][19];	//0：卡号，1：姓名:2：密码，3：身份证，4：余额，5：积分，6：激活状态
			int k = 0, times = 0;
			for (int i = 0; i < strlen(tem); i++) {
				if (tem[i] == ',') {
					int pos = 0;
					for (int j = k; j < i; j++, pos++) {
						info[times][pos] = tem[j];
					}
					info[times][pos] = '\0';
					k = i + 1;
					times++;
				}
			}
			//处理最后一项
			int pos = 0;
			for (int i = k; i < strlen(tem); i++, pos++) {
				info[times][pos] = tem[i];
			}
			info[times][pos] = '\0';
			//给对应参数赋值
			tmp->number_ = ToInt(info[0]);
			strcpy(tmp->name_, info[1]);
			strcpy(tmp->password_, info[2]);
			strcpy(tmp->id_, info[3]);
			tmp->balance_ = ToFloat(info[4]);
			tmp->score_ = ToFloat(info[5]);
			tmp->is_available_ = info[6][0] == '0' ? false : true;
			tmp->next_ = master.consumer_->next_;
			master.consumer_->next_ = tmp;
			tmp = (struct Consumer_Node*)malloc(sizeof(struct Consumer_Node));
		}
	}
	fclose(read_consumer);
}
//写入用户信息文件
void WriteConsumer(struct Master& master, char path[100]) {
	FILE* write_consumer = NULL;
	fopen_s(&write_consumer, path, "w");	//截断打开文件
	if (write_consumer == NULL) {
		printf("该文件不存在！");		//错误检测
	}
	fprintf(write_consumer, "%s", "卡号,姓名,密码,身份证,余额,积分,激活状态\n");
	Consumer_Node* iter = master.consumer_->next_;
	for (; iter != NULL; iter = iter->next_) {
		fprintf(write_consumer, "%d,%s,%s,%s,%.2f,%.2f,%d\n", iter->number_, iter->name_, iter->password_, iter->id_, iter->balance_, iter->score_, iter->is_available_);
	}
}

int ToInt(char str[128]) {
	int num = 0;
	for (int i = 0; i < strlen(str); i++) {
		num = num * 10 + (str[i] - '0');
	}
	return num;
}
float ToFloat(char str[128]) {
	float num = 0;
	int k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != '.') {
			num = num * 10 + (str[i] - '0');
		}
		else {
			k = i + 1;
			break;
		}
	}
	if (k != 0) {
		float times = 0.1;
		for (int i = k; i < strlen(str); i++) {
			num += (float)(str[i] - '0') * times;
			times *= 0.1;
		}
	}
	return num;
}
