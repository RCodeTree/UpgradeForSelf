// 计算n的阶乘 ---> !3 = 1 x 2 x 3
#include <stdio.h>

// 递归求阶乘
int getResult(int n)
{
	return n * getResult(n - 1);
}

int main()
{
	int n;
	int result = 1;

	printf("请输入一个整数: ");
	scanf("%d", &n);

	// 递归求阶乘
	int num = getResult(n);
	printf("输入的数的阶乘为☞ %d"， num);
	
	/* 循环求阶乘
	for (int i = 0; i < n; i++)
	{
		result *= n - i;
	}

	printf("输入的数的阶乘是: %d\n", result);
    */
	return 0;
}
