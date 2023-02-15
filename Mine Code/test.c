#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*************************\n");
	printf("********* 0.exit ********\n");
	printf("********* 1.play ********\n");
	printf("*************************\n");
}
void play()
{
	char mine[ROWS][COLS] = { 0 };   //存放雷的信息
	char show[ROWS][COLS] = { 0 };   //显示棋盘
	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	//打印棋盘
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//布置雷
	Setmine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);

	//排查雷
	Sreachmine(mine,show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}