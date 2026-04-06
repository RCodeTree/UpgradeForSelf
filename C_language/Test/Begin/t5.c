/*
题目：
将一句话的单词进行倒置，标点不倒置。

例如：
I like beijing.

经过函数处理后应变为：
beijing. like I

输入描述：
每个测试输入包含 1 个测试用例，例如：I like beijing.
输入用例长度不超过 100。

输出描述：
依次输出倒置之后的字符串，单词之间以空格分割。

.gnijieb ekil I  ----> beijing. like I
*/
#include <stdio.h>
#include <string.h>
/*
void reverse(char* str)
{
	int strLen = strlen(str);
	for(int i = 0; i < strLen / 2; i++)
	{
		char temp = *(str + i);
		*(str + i ) = *(str + (strLen - 1 - i));
		*(str + (strLen - 1 - i)) = temp;
	}
}
*/

void reverse(char* left, char* right)
{
	while(left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}


int main()
{
	char str[100] = { 0 };
	printf("请输入一个字符串: ");
	gets(str);

	// 先逆序整个字符串
	reverse(str, str + (strlen(str) - 1));

	// 再逆序每一个单词
	char* start = str; // 指向字符串开头的位置
	
	while(*start != '\0')
	{
            char* end = start;
            while(*end != ' ' && *end != '\0')	
            {
                end++;
            }	
            reverse(start, end - 1); // 逆序单词 ----> 此时的end已经指向空格了
            if(*end != '\0')
            {
                end++; // 跳过空格
            }
            start = end; // 跳过空格后，使start重新指向另一个单词的开头位置
	}


	printf("%s\n", str);

	return 0;

}


