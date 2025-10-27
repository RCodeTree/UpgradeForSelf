// 求 2 个数的最大公约数
#include <stdio.h>
#include <stdbool.h>

/*
 * 第一种方法：num1 和 num2 中，最大公约数不会大于这两个数中小的那个数，使用小的那个数如果能同时整除 num1 和 num2 ，则该数为最大公约数
 */
void getNum(int num1, int num2, int min)
{
	while(true)
	{
		if (num1 % min == 0 && num2 % min == 0)
		{
			printf("getNum最大公约数为：%d\n", min);
		       	break;
		}

		min--;	
	}
}	


/*
 * 第二种方法：辗转相除法
 * num1 % num2 = result ----> 如果 result 不为 0 ----> num2 % result = result2 ----> 如果 result2 不为0 ----> .... ----> 直到有一个被模的 result 为最大公约数
 * num1 % num2 = result ----> 如果 result 为 0 ----> num2 为最大公约数
 */
void getNum2(int num1, int num2)
{
	while(true)
	{
		int result = num1 % num2;
		if (result == 0)
		{
			printf("getNum2最大公约数为：%d\n", num2);
			break;
		}

		num1 = num2;
		num2 = result;
	}
}


int main()
{
	int num1;
	int num2;

	printf("请输入2个整数：");
	scanf("%d %d", &num1, &num2);

	int min = num1 > num2 ? num2 : num1;

	getNum(num1, num2, min);

	getNum2(num1, num2);

	return 0;
}
