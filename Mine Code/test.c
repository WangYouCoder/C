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
	char mine[ROWS][COLS] = { 0 };   //����׵���Ϣ
	char show[ROWS][COLS] = { 0 };   //��ʾ����
	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	//��ӡ����
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//������
	Setmine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);

	//�Ų���
	Sreachmine(mine,show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
	return 0;
}