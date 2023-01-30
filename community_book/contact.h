#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME 10
#define SEX  5
#define TELE 12
#define ADDR 20
#define CAPA_MAX 3
#define INC_SZ 2

//����ͨѶ¼��Ա��Ϣ
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
	Peoinfo* date;
	int sz;
	int capacity;
}Contact;
// ��ʼ��ͨѶ¼
void InitContact(Contact* pc);

// ������Ա��Ϣ
void Addcontact(Contact* pc);

//��ӡͨѶ¼��Ϣ
void print(Contact* pc);

// ɾ����Ϣ
void Delcontact(Contact* pc);

// ������Ϣ
void Sreachcontact(Contact* pc);

// �޸���Ϣ
void Modifycontact(Contact* pc);

//����ͨѶ¼
void Destorycontact(Contact* pc);