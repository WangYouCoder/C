#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define Difficulty 10
//��ʼ������
void InitBoard(char board[ROWS][COLS],int row,int col,char ret);

//��ӡ����
void Displayboard(char board[ROWS][COLS], int row, int col);

//������
void Setmine(char baord[ROWS][COLS], int row, int col);

//�Ų���
void Sreachmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);