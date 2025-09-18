#include <stdio.h>
int main()
{
	/*
	 * switch语句 中，case语句 的选项只能是常量或者字符类型(ASCCI码表)，不能是表达式
	 * 如果 case语句 没有 break 做限制，会导致 case语句穿透
	 */
	int num;
	printf("请输入一个数字：");
	scanf("%d", &num);

	switch(num)
	{
		case 1:
			printf("该数字为 %d\n", num);
			break;
		case 2:
			printf("该数字为 %d\n", num);
			break;
		default:
			printf("输入错误\n");
	}

	return 0;
}
