// 递归实现：字符串逆序
#include <stdio.h>
#include <string.h>

char* reverseStr(char *str, int left, int right)
{

	if (left > right)
	{
		return str;
	}

	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;

	left++;
	right--;


	return reverseStr(str, left, right);
}





int main()
{
	char str[100];

	printf("请输入一个字符串> ");
	scanf("%s", str);

	int left = 0;
	int right = strlen(str) - 1;

	char reverse[] = reverseStr(str, left, right);

	return 0;
}
