/*
 * 完数：一个数如果恰好等于它的真因子之和，这个数就称为完数。
 * 每一个真因子的判断：如果一个数能被整除除了 num 本身之内的所有整数，则它就是 num 的一个真因子。
 * 例如：6 = 1 + 2 + 3，因此 6 是完数。
 */

#include <stdio.h>
int main()
{
	int num;
	printf("请输入完数的最大范围> ");
	scanf("%d", &num);

	for(int i = 1; i <= num; i++)
	{
		int sum = 0; // 存储 真因子 之和
		
		// 若为 num 的真因子，则 num 能被整除除了 num 本身之内的所有整数 ----> 这里的 num 由 i 代替
		for(int j = 1; j < i; j++)
		{
			if(i % j == 0)
			{
				sum += j;
			}
		}

		// 根据所有的 真因子 之和判断该数是否为完数并输出
		if(sum == i)
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return 0;
}
