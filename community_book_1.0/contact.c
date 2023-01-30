#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		perror("AddContact");
		printf("ͨѶ¼���������ʧ��");
		return;
	}
	printf("��������ϵ�˵�����:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("��������ϵ�˵��Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("��������ϵ�˵�����:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("��������ϵ�˵ĵ绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("��������ϵ�˵ĵ�ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}

int Find_name(Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	//�ҵ�������Ա���±�
	char name[NAME];
	printf("��������Ҫɾ����Ա������:>");
	scanf("%s", name);
	int ret = Find_name(pc,name);
	if (ret == -1)
	{
		printf("��Ա������\n");
		return;
	}
	// ����ɾ����Ҳ���ǽ���������һ��һ����ǰ�ƶ�
	int i = 0;
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");

}

void Print(Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-10s\t%-3s\t%s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-3s\t%d\t%-12s\t%-20s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

void SreachContact(Contact* pc)
{
	char name[NAME];
	printf("��������Ҫ������Ա������:>");
	scanf("%s", name);
	int ret = Find_name(pc, name);
	if (ret == -1)
	{
		printf("��Ա������\n");
		return;
	}
	printf("%-10s\t%-3s\t%d\t%-12s\t%-20s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr);

}

void ModifyContact(Contact* pc)
{
	char name[NAME];
	printf("��������Ҫ�޸���Ա������:>");
	scanf("%s", name);
	int ret = Find_name(pc, name);
	if (ret == -1)
	{
		printf("��Ա������\n");
		return;
	}
	printf("��������ϵ�˵�����:>");
	scanf("%s", pc->data[ret].name);
	printf("��������ϵ�˵��Ա�:>");
	scanf("%s", pc->data[ret].sex);
	printf("��������ϵ�˵�����:>");
	scanf("%d", &pc->data[ret].age);
	printf("��������ϵ�˵ĵ绰:>");
	scanf("%s", pc->data[ret].tele);
	printf("��������ϵ�˵ĵ�ַ:>");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�\n");
}