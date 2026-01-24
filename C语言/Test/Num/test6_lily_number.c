/*
变种水仙花数 - Lily Number: 把任意的数字，从中间拆分成两个数字，比如1461可以拆分成 (1和461)，(14和61)，(146和1),如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
例如:
655 = 6 * 55 + 65 * 5
1461 = 1 * 461 + 14 * 61 + 146 * 1
求出 5 位数中的所有 Lily Number
*/
#include <stdio.h>
#include <math.h>

void getLily(int num)
{
	int sum  = 0;
	/* 
    for(int i = 1; i <= 4; i++)
	{
		int k = (int)pow(10, i);
		sum += (num / k) * (num % k);
	} 
    */
	int k = 1;
	for (int i = 1; i <= 4; i++)
	{
		k *= 10;
		sum += (num / k) * (num % k);
	}

	if(num == sum)
	{
		printf(" %d 为变种水仙花数\n", num);
		return;
	}
	
	printf(" %d 不为变种水仙花数\n", num);
}


int main() 
{
	int num;

	printf("请输入一个 5位数 整数> ");
	scanf("%d", &num);

	getLily(num);

	return 0;
}
