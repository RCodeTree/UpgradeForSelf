// 递归实现：打印数的每一位
#include <stdio.h>

/*
 输入 ----> 123
 getNum(123); ----> 123 % 10 = 3
 getNum(12); ----> 12 % 10 = 2
 getNum(1); ----> 1 % 10 = 1
 */

void getNum(int num)
{
	if(num > 9)
	{
		getNum(num / 10);
	}
	
	printf("%d ", num % 10);

}


int main()
{
	int num;

	printf("请输入一个整数> ");
	scanf("%d", &num);

	getNum(num);

	return 0;
}


