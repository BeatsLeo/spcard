#ifndef DOFILE_H
#define DOFILE_H
#include"menu.h"
#include<stdio.h>
#include<stdlib.h>


void ReadAdm(struct Master& master, char path[100]);	//读取管理员文件
void WriteAdm(struct Master& master, char path[100]);	//写入管理员文件
void ReadApply(struct Master& master, char path[100]);	//读取购物卡申请文件
void WriteApply(struct Master& master, char path[100]);	//写入购物卡申请文件
void ReadConsumer(struct Master& master, char path[100]);	//读取用户信息文件
void WriteConsumer(struct Master& master, char path[100]);	//写入用户信息文件
int ToInt(char str[128]);								//将字符串转化为int型
float ToFloat(char str[128]);
#endif
