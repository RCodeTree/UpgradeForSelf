// 递归实现：字符串逆序
#include <stdio.h>
#include <string.h>

// 求字符串长度
int getStrlen(char *str)
{
	if (*str != '\0')
	{
		return 1 + getStrlen(str + 1); // 递归调用，每次调用时，str指针向后移动一位
	}
	return 0;
}


// 实现字符串逆序
void reverseStr(char *str)
{
	// 先将第一个元素存起来
	char temp = *str;

	// 将最后一个元素放到第一个的位置
	int len = getStrlen(str);
	*str = *(str + len - 1);

	// 将最后一个变为 \0 ----> 保证每次递归交换的是中间剩余的首尾两个字符
	*(str + len - 1) = '\0';
	
	// 先使用递归将中间剩余的字符交换
        if(getStrlen(str + 1) >= 2)
	{
		reverseStr(str + 1);
	}

	// 最后将最后一个元素改为当时存起来的第一个元素，相对于每一次递归
	*(str + len - 1) = temp;
}


int main()
{
	char str[100];

	printf("请输入一个字符串> ");
	scanf("%s", str);

	reverseStr(str);

	printf("逆序后的字符串为> %s\n", str);

//	int len = getStrlen(str);
//	printf("%d\n", len);

	return 0;
}
