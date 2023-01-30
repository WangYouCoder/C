#pragma once
#include<stdio.h>
#include<string.h>
#define NAME 10
#define SEX  3
#define TELE 12
#define ADDR 20
#define MAX  100

//�����ṹ��
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

// ��ʼ���ṹ��
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

// ��ӡ��Ϣ
void Print(Contact* pc);

// ������ϵ��
void SreachContact(Contact* pc);

// �޸���ϵ��
void ModifyContact(Contact* pc);