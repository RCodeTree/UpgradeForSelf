// 递归实现：计算一个数的每位之和 ----> 1234 ----> 1 + 2 + 3 + 4
#include <stdio.h>


/*
 DigitSum(1234)
  → DigitSum(123) + 4
    → DigitSum(12) + 3
      → DigitSum(1) + 2
        → 1
      → 1 + 2 = 3
    → 3 + 3 = 6
  → 6 + 4 = 10
 */

unsigned int DigitSum(unsigned int num)
{
	if(num > 9)
	{
		return DigitSum(num / 10) + num % 10;
	}
	else 
	{
		return num;
	}
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

