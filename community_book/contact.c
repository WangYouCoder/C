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
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &pc->date[pc->sz].age);
	printf("请输入电话:>");
	scanf("%s", pc->date[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("增加成功\n");
}

void print(Contact* pc)
{
	// 打印标题
	printf("%-10s\t%-5s\t%s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
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
		printf("通讯录为空，无法删除\n");
		return;
	}
	char name[NAME] = { 0 };
	printf("请输入需要删除人员的名字:>");
	scanf("%s", name);
	// 先找到所需要删除人员的下标
	int ret = Find(pc,name);
	if (ret == -1)
	{
		printf("人员不存在\n");
		return;
	}
	// 删除
	int i = 0;
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void Sreachcontact(Contact* pc)
{
	char name[NAME] = { 0 };
	printf("请输入需要查找人员的名字:>");
	scanf("%s", name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("人员不存在\n");

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
	printf("请输入需要修改人员的名字:>");
	scanf("%s", name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("人员不存在\n");

	}
	printf("请输入姓名:>");
	scanf("%s", pc->date[ret].name);
	printf("请输入性别:>");
	scanf("%s", pc->date[ret].sex);
	printf("请输入年龄:>");
	scanf("%d", &pc->date[ret].age);
	printf("请输入电话:>");
	scanf("%s", pc->date[ret].tele);
	printf("请输入地址:>");
	scanf("%s", pc->date[ret].addr);
	printf("修改成功\n");
}