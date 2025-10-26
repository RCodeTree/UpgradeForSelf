// 递归实现：字符串逆序
#include <stdio.h>
#include <string.h>

void reverseStr(char *str, int left, int right)
{

	if (left > right)
	{
		return;
	}

	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;

	return reverseStr(str, left + 1, right - 1);
}





int main()
{
	char str[100];

	printf("请输入一个字符串> ");
	scanf("%s", str);

	int left = 0;
	int right = strlen(str) - 1;

	reverseStr(str, left, right);

	printf("逆序后的字符串为> %s\n", str);

	return 0;
}
