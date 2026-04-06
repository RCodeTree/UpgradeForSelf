#include <stdio.h>
#include <string.h>

char* modify(char* str, int k)
{
	char* p = str;
	char* tmp = str;
	while(k--)
	{
		char first = *tmp;
		for (int i = 0; i < strlen(str) - 1; i++)
		{
			*(tmp + i) = *(tmp + i + 1);
		}
		*(tmp + (strlen(str) - 1)) = first;
	}
	return p;
}

int main()
{
	char str[100];
	printf("输入一个字符串：");
	scanf("%s", str); int k; printf("输入左旋次数："); scanf("%d", &k);
	printf("左旋前：%s\n", str);
	char* p = modify(str, k);
	printf("左旋后：%s\n", p);
	return 0;
}
