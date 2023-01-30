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
		printf("通讯录已满，添加失败");
		return;
	}
	printf("请输入联系人的姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入联系人的性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入联系人的年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入联系人的电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入联系人的地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
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
		printf("通讯录为空，无法删除\n");
		return;
	}
	//找到所需人员的下标
	char name[NAME];
	printf("请输入需要删除人员的姓名:>");
	scanf("%s", name);
	int ret = Find_name(pc,name);
	if (ret == -1)
	{
		printf("人员不存在\n");
		return;
	}
	// 进行删除，也就是将所有数据一个一个向前移动
	int i = 0;
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");

}

void Print(Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-10s\t%-3s\t%s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
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
	printf("请输入需要查找人员的姓名:>");
	scanf("%s", name);
	int ret = Find_name(pc, name);
	if (ret == -1)
	{
		printf("人员不存在\n");
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
	printf("请输入需要修改人员的姓名:>");
	scanf("%s", name);
	int ret = Find_name(pc, name);
	if (ret == -1)
	{
		printf("人员不存在\n");
		return;
	}
	printf("请输入联系人的姓名:>");
	scanf("%s", pc->data[ret].name);
	printf("请输入联系人的性别:>");
	scanf("%s", pc->data[ret].sex);
	printf("请输入联系人的年龄:>");
	scanf("%d", &pc->data[ret].age);
	printf("请输入联系人的电话:>");
	scanf("%s", pc->data[ret].tele);
	printf("请输入联系人的地址:>");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功\n");
}