// 模仿函数库的 strlen(str) 函数，实现自己的求字符串长度的函数，不能使用临时变量
#include <stdio.h>

int getStrlen(char *str) // 参数str是一个字符指针，指向字符串的第一个字符
{
	if (*str != '\0')
	{
		return 1 + getStrlen(str + 1); // 递归调用，每次调用时，str指针向后移动一位
	}
	return 0;
}


int main()
{
	char str[100];

	printf("请输入一个字符串> ");
	scanf("%s", str);

	// 使用自定义函数求字符串长度
	int len = getStrlen(str);

	printf("字符串 str 的长度为> %d\n", len);

	return 0;
}



