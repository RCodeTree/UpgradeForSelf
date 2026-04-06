// 递归实现：计算一个数的每位之和 ----> 1234 ----> 1 + 2 + 3 + 4
#include <stdio.h>

unsigned int DigitSum(unsigned int num)
{
	unsigned static int sum = 0;

	if(num > 9)
	{
		DigitSum(num / 10);
	}

	return sum += num % 10;
}

int main()
{
	int num;

	printf("请输入一个非负整数> ");
	scanf("%u", &num);

	unsigned int sum = DigitSum(num);

	printf(" %d 每位之和为> %d\n", num, sum);

	return 0;

}

