// 字符串逆序：输入一个字符串，输出其逆序字符串
// 注意点：如果使用临时数组存储逆序字符串，需要在末尾存入一个'\0'，不然在开辟的缓冲区中是没有结束标志的
#include <stdio.h>
#include <string.h>
int main() 
{
	/*
	  使用临时数组实现
	*/
	int index = 0; // 逆序字符串索引
	char inStr[100];
	char outStr[100];

	printf("请输入一个字符串：");
	scanf("%s", inStr);

	for (int i = strlen(inStr) - 1; i < strlen(inStr); i--) 
	{
		outStr[index] = inStr[i];
		index++;
	}
	outStr[strlen(inStr)] = '\0';


	printf("输入的字符串的逆序字符串为：%s\n", outStr);
	
	
	/* 
	  原地逆序
	*/
	char Str[100];
	int start, end; // 索引
	char temp; // 临时变量

	printf("请输入一个字符串：");
        scanf("%s", Str);

	// 索取长度：长度必须在输入后取出，不然会读取错误
	start = 0;
	end = strlen(Str) - 1;

	while (start < end)
	{
		temp = Str[start];
		Str[start] = Str[end];
		Str[end] = temp;

		start++;
		end--;
	}

	printf("输入的字符串的逆序字符串为：%s\n", Str);


	return 0;
}
