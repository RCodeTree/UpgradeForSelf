// 写一个函数，判断一年是不是闰年
// 闰年的判断条件：
// 1. 能被 4 整除，但不能被 100 整除 (该年为普通年，必须能被 4 整除，但不能被 100 整除(如果能被 100 整除，是世纪年但不是闰年))
// 2. 能被 400 整除 (该年为世纪年，必须能被 400 整除，才是闰年)
#include <stdio.h>

void isLeapYear(int num)
{
	if ((num % 4 == 0 && num % 100 != 0) || (num % 400 == 0))
	{
		printf("该年为闰年\n");
	}
	else
	{
		printf("该年不为闰年");
	}
}

int main()
{
	int num;

	printf("请输入一个年份：");
	scanf("%d", &num);

	isLeapYear(num);

	return 0;

}
