#include <stdio.h>
int main()
{
	int line;
	printf("请输入要生成的行数> ");
	scanf("%d", &line);

	for(int i = 0; i < line; i++)
	{
		// 空格
		for(int j = 0; j < line - (i + 1); j++)
		{
			printf(" ");
		}

		// *
		for(int j = 0; j < line; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
