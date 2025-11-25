/*
题目补充：
打印由 '*' 组成的菱形图案。
要求：
1. 顶部 1 个星号，逐行递增到中间最大宽度，再逐行递减到 1。
2. 每行星号居中对齐，整体左右对称，形成菱形。
      *
     ***
    *****
   *******
  *********
 ***********
*************
 ***********
  *********
   *******
    *****
     ***
      *

当 i, j 初始化值为：1
// 上半部分
for(int i = 1; i <= line; i++)
{
        // 空格
        for(int j = 1; j <= line - i; j++)
        {
                printf(" ");
        }
        // *
        for(int j = 1; j <= 2 * i - 1; j++)
        {
                printf("*");
        }
        printf("\n");
}

// 打印下半部分
for(int i = 1; i <= line - 1; i++)
{
        // 空格
        for(int j = 1; j <= i; j++)
        {
                printf(" ");
        }

        // *
        for(int j = 1; j <= 2 * line - 2 * i - 1; j++)
        {
                printf("*");
        }

        printf("\n");
}


*/
#include <stdio.h>
int main()
{
	unsigned int line;

	printf("请输入行数: ");
	scanf("%u", &line);

	// 打印上半部分
	for(int i = 0; i < line; i++)
	{
		// 空格
		for(int j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}

		// *
		for(int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}

		printf("\n");
	}



	// 打印下半部分
	for(int i = 0; i < line - 1; i++)
	{
		// 空格
		for(int j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		
		// *
		for(int j = 0; j < 2 * (line - 1) - (1 + i) - i; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}	
