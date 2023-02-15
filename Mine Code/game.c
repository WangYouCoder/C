#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int row, int col,char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ret;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("**********扫雷游戏**********\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < Difficulty)                    // 布置十个雷
	{
		int x = rand() % ROW + 1;       // 生成 1~9 的随机数
		int y = rand() % COL + 1;
		if (board[x][y] == '0')          // 判断是否已经布置过雷
		{
			board[x][y] = '1';
			count++;
		}
	}
}
int win = 0;

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		show[x][y] = ' ';
		win++;
	}
	else
	{
		show[x][y] = count + '0';
		win++;
	}
	if (show[x][y] == ' ')
	{
		for (i = x - 1; i < x + 1; i++)
		{
			for (j = y - 1; j < y + 1; j++)
			{
				if (mine[i][j] != '1' && show[i][j] == '*' && i > 0 && i <= ROW && j > 0 && j <= COL)
				{
					Findmine(mine, show, i, j);
				}
			}
		}
	}
}
void Sreachmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (win<ROW*COL-Difficulty)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{
			if (mine[x][y] == '0')
			{
				Findmine(mine, show, x, y);
				Displayboard(show, ROW, COL);
			}
			else
			{
				printf("扫到雷了，游戏结束\n");
				Displayboard(show, ROW, COL);
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	printf("恭喜你，游戏胜利！！\n");
}