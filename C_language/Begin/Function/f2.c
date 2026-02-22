// 定义一个函数交换两个整数的值
#include <stdio.h>

/*
 * 函数名：swap
 * 功能：交换两个整数的值
 * 参数：
 * 	x：指向第一个整数的指针
 * 	y：指向第二个整数的指针
 * 返回值：无

 * 详解：
 * 	通过指针参数x和y，交换指向的整数的值
 * 	在函数内部，使用一个临时变量temp来存储x指向的整数的值
 * 	然后将y指向的整数的值赋值给x指向的整数
 * 	最后将temp的值赋值给y指向的整数
 */
void swap(int *x, int *y)
{
	// 解引用指针x和y，获取它们指向的整数的值
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int num1 = 0;
	int num2 = 0;

	printf("请输入两个数字：");
	scanf("%d %d", &num1, &num2);

	printf("交换前num1的值：%d，交换前num2的值：%d\n", num1, num2);
	
	swap(&num1, &num2);

	printf("交换后num1的值：%d，交换后num2的值：%d\n", num1, num2);

	return 0;
}
