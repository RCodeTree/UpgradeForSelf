#include <stdio.h>

int main()
{
	int n;
	printf("请输入项数 n (计算前 n 项斐波那契数列的和)> ");
	scanf("%d", &n);

	if (n < 1)
	{
		printf("S=0\n");
		return 0;
	}
	
	if (n == 1)
	{
		printf("S=1\n");
		return 0;
	}

	int F1 = 1, F2 = 1;
	int F, S = 2; // 这里 S 初始值为 2，是因为前 2 项斐波那契数列的和为 2

	for(int i = 3; i <= n; i++)
	{
		F = F1 + F2;
		F1 = F2;
		F2 = F;
		S = S + F;
	}

	printf("S=%d\n", S);

	return 0;
}
