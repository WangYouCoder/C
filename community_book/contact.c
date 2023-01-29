#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(Contact* pc)
{
	// Contact con = { 0 };
	pc->sz = 0;
	memset(pc->date, 0, sizeof(pc->date));
}

void Addcontact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->date[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &pc->date[pc->sz].age);
	printf("������绰:>");
	scanf("%s", pc->date[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("���ӳɹ�\n");
}

void print(Contact* pc)
{
	// ��ӡ����
	printf("%-10s\t%-5s\t%s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%d\t%-12s\t%-20s\n", pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].age,
			pc->date[i].tele,
			pc->date[i].addr);
	}
}
static int Find(Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Delcontact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	char name[NAME] = { 0 };
	printf("��������Ҫɾ����Ա������:>");
	scanf("%s", name);
	// ���ҵ�����Ҫɾ����Ա���±�
	int ret = Find(pc,name);
	if (ret == -1)
	{
		printf("��Ա������\n");
		return;
	}
	// ɾ��
	int i = 0;
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void Sreachcontact(Contact* pc)
{
	char name[NAME] = { 0 };
	printf("��������Ҫ������Ա������:>");
	scanf("%s", name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("��Ա������\n");

	}
	printf("%-10s\t%-5s\t%d\t%-12s\t%-20s\n", pc->date[ret].name,
			pc->date[ret].sex,
			pc->date[ret].age,
			pc->date[ret].tele,
			pc->date[ret].addr);
}

void Modifycontact(Contact* pc)
{
	char name[NAME] = { 0 };
	printf("��������Ҫ�޸���Ա������:>");
	scanf("%s", name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("��Ա������\n");

	}
	printf("����������:>");
	scanf("%s", pc->date[ret].name);
	printf("�������Ա�:>");
	scanf("%s", pc->date[ret].sex);
	printf("����������:>");
	scanf("%d", &pc->date[ret].age);
	printf("������绰:>");
	scanf("%s", pc->date[ret].tele);
	printf("�������ַ:>");
	scanf("%s", pc->date[ret].addr);
	printf("�޸ĳɹ�\n");
}