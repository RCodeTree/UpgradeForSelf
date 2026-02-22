/*
打印如下三角形：
    *
   ***
  *****
 *******
*********
*/
#include <stdio.h>
int main()
{
	int line;
	printf("请输入要打印的行数> ");
	scanf("%d", &line);
	for(int i = 0; i < line; i++)
	{
		for(int j = 0; j < line - (i + 1); j++)
		{
			printf(" ");
		}

		for(int j = 0; j < 2 * (i + 1) - 1; j++)
		{
			printf("*");
		}

		printf("\n");
	}
	
	return 0;
}
