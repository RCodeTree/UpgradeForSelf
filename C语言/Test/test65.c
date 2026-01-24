// 打印菱形
#include <stdio.h>
int main()
{
	int line;
	printf("请输入行数> ");
	scanf("%d", &line);

	for(int i = 0; i < line; i++)
	{
		// 空格
		for(int j = 0; j < line - (i + 1); j++)
		{
			printf(" ");
		}

		// *
		for(int j = 0; j < 2 * (i + 1) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for(int i = 0; i < line - 1; i++)
	{
		// 空格
		for(int j = 0; j < i + 1; j++)
		{
			printf(" ");
		}

		// *
		for(int j = 0; j < 2 * (line - 1) - (1 + i) - i ; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
