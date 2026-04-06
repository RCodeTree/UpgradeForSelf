// 输入一个整数，分别输出奇数位和偶数位的值
// 00000000 00000000 00000000 00000001
// 假如输入 11
#include <stdio.h>
int main()
{
	int num;
	printf("请输入一个整数:");
	scanf("%d", &num);

	// 奇数位
	for(int i = 0; i < 32; i++)
	{
		if(i % 2 != 0)
		{
			printf("%d ", (num >> i) & 1);
		}
	}

	printf("\n");

	// 偶数位
	for(int i = 0; i < 32; i++)
	{
		if(i % 2 == 0)
		{
			printf("%d ", (num >> i) & 1);
		}
	}

	printf("\n");

	return 0;

}

