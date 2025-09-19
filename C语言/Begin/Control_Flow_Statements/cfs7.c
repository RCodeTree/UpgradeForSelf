// 计算n的阶乘 ---> !3 = 1 x 2 x 3
#include <stdio.h>
int main()
{
	int n;
	int result = 1;

	printf("请输入一个整数: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		result *= n - i;
	}

	printf("输入的数的阶乘是: %d\n", result);

	return 0;
}
