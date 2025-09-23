// 求阶乘的和
#include <stdio.h>
int main()
{
	int sum = 0;
	int Result;
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		Result = 1;
		for (int j = 0; j < i; j++)
		{
			Result *= i - j;
		}
		sum += Result;
	}

	printf("%d的阶乘为: %d\n", num, Result);
	printf("阶乘的和为: %d\n", sum);

	return 0;
}
