// 实现 字符串逆序
/*
 * strlen() 函数的返回值是 unsigned int, 即size_t
 */
#include <stdio.h>
#include <string.h>

// 临时数组实现
void reverse(char* str)
{
	int index = 0;
	char reverseStr[100];
	for(int i = (int)strlen(str) - 1; i >= 0; i--)
	{
		reverseStr[index] = str[i];
		index++;
	}

	reverseStr[strlen(str)] = '\0';

	printf("逆序后> %s\n", reverseStr);
}

// 使用临时变量原地逆序
void reverse2(char* str)
{
	int start = 0;
	int end = strlen(str) - 1;

	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}





int main()
{
	char str[100];

	printf("请输入一个字符串> ");
	scanf("%s", str);

	reverse(str);

	reverse2(str);
	printf("逆序后> %s\n", str);

	return 0;
}
	
