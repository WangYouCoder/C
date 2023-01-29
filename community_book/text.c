#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("************************************\n");
	printf("********* 1. Add    2. Del   *******\n");
	printf("********* 3. search 4.modify *******\n");
	printf("********* 5.print   0. exit  *******\n");
	printf("************************************\n");
}
enum
{
	EXIT,
	ADD,
	DEL,
	SREACH,
	MODIFY,
	PRINT
};
int main()
{
	int input = 0;
	// 创建通讯录
	Contact con;
	// 初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SREACH:
			Sreachcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case PRINT:
			print(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}