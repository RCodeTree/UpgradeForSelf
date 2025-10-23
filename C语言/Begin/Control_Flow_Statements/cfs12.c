/*
 *  猜数字
 *  	1. 生成一个随机数字
 *  	2. 猜数字，如果猜大了输出 “猜大了”；如果猜小了输出 “猜小了”；直到猜对为止
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 菜单输出
void menu()
{
	printf("==========欢迎来到猜数字游戏==========\n");
	printf("0. exit\n");
	printf("1. play\n");
	printf("======================================\n");
}

// 猜数字逻辑
void game()
{
	// 生成随机数 % 100 得到 0-99 的随机数，再 +1 得到 1-100 的随机数
	// 注意：rand() 函数生成的随机数是伪随机数，每次运行程序时生成的随机数序列是相同的，这里是需要一个固定的序列
	// 为了每次运行程序时生成不同的随机数序列，需要调用 srand() 函数初始化随机数生成器
	int random = rand() % 100 + 1;

	while (true)
	{
		int guess = 0;
		printf("请输入一个数字> ");
		scanf("%d", &guess);
		printf("\n");
		if (guess > random)
		{
			printf("猜大了\n");
		} 
		else if (guess < random)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}

int main()
{
	/*
	要使用rand()函数生成随机数，需要先调用srand()函数初始化随机数生成器
	rand() 函数用于生成随机数
	参数：无
	返回值：int 类型的随机数

	srand() 函数用于初始化随机数生成器 
	参数：unsigned int seed
	返回值：无

	time() 函数用于获取当前时间
	参数：time_t *timer
	返回值：time_t 类型的时间值
	*/
	srand((unsigned int) time(NULL));
	int input = 0;

	do
	{
		menu();
		printf("请选择> ");
		scanf("%d", &input);
		printf("\n");
		switch(input)
		{
			case 0:
				printf("退出游戏\n");
				break;
			case 1:
				game();
				break;
			default:
				printf("输入异常，请重新输入\n");
				break;
		}
	} while(input);

	return 0;
}
