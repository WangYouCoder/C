#pragma once
#include<stdio.h>
#include<string.h>

#define NAME 10
#define SEX  5
#define TELE 12
#define ADDR 20
#define MAX  100
//创建通讯录人员信息
typedef struct PeoInfo
{
	char name[NAME];
	char sex[SEX];
	int age;
	char tele[TELE];
	char addr[ADDR];
}Peoinfo;

typedef struct Contact
{
	Peoinfo date[MAX];
	int sz;
}Contact;

// 初始化通讯录
void InitContact(Contact* pc);

// 增加人员信息
void Addcontact(Contact* pc);

//打印通讯录信息
void print(Contact* pc);

// 删除信息
void Delcontact(Contact* pc);

// 查找信息
void Sreachcontact(Contact* pc);

// 修改信息
void Modifycontact(Contact* pc);