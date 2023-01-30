#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("*************************************\n");
	printf("********** 1.add    2.del ***********\n");
	printf("********** 3.sreach 4.modify*********\n");
	printf("********** 5.print  0.exit **********\n");
	printf("*************************************\n");
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
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SREACH:
			SreachContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case PRINT:
			Print(&con);
			break;
		case EXIT:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}