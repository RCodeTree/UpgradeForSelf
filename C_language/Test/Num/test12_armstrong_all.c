/*
题目：
求出 0 ~ 100000 之间的所有“水仙花数”并输出。

定义：
“水仙花数”是指一个 n 位数，其各位数字的 n 次方之和恰好等于该数本身。

示例：
153 = 1^3 + 5^3 + 3^3，因此 153 是一个“水仙花数”。
*/
#include <stdio.h>
#include <math.h>
int main()
{
	for(int i = 0; i <= 100000; i++)
	{
		/*
		 计算数的位数
		 */
		int count = 1; // 任何一个数都至少是 1 位数
		int temp = i; // 将每一个数临时存到 temp 中，防止在内循环中改变数的值
		while(temp / 10) // 这里判断位数不要用 temp % 10，因为当某个数是 10 的倍数时(即当某个数的个位数是 0 时)，temp % 10 会得到 0，而不是 1，会提前结束循环，导致位数计算错误
		{
			count++;
			temp /= 10;
		}


		/*
		 判断是否为水仙花数
		 */
		int sum = 0;
		temp = i;
		while(temp)
		{
			sum += pow(temp % 10, count);
			temp /= 10;
		}

		if(sum == i)
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return 0;

}


		


