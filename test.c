#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int cnt = 9;
	while (cnt)
	{
		printf("%d\r", cnt);
		cnt--;
	}
	return 0;
}