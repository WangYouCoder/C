#pragma once
#include<stdio.h>
#include<string.h>
#define NAME 10
#define SEX  3
#define TELE 12
#define ADDR 20
#define MAX  100

//声明结构体
typedef struct Peoinfo
{
	char name[NAME];
	char sex[SEX];
	int age;
	char tele[TELE];
	char addr[ADDR];
}Peoinfo;
typedef struct Contact
{
	Peoinfo data[MAX];
	int sz;
}Contact;

// 初始化结构体
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

// 打印信息
void Print(Contact* pc);

// 查找联系人
void SreachContact(Contact* pc);

// 修改联系人
void ModifyContact(Contact* pc);