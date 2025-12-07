/* 
- 这里的字符指针ch指向的是一个字符串常量"hello world"，实际上指向的是字符串常量的第一个字符'h'的地址，即指向的是该字符串的首地址
- 当使用%s格式化输出时，会从该地址开始输出，直到遇到字符串结束符'\0'为止
*/
#include <stdio.h>
int main()
{
	char* ch = "hello world";
    printf("%c\n", *ch); // h
    printf("%c\n", *(ch + 1)); // e
	printf("%s\n", ch); // hello world 
    printf("%s\n", ch + 1); // ello world ----> 调整char指针，指向字符串常量的第二个字符'e'的地址
	return 0;
}