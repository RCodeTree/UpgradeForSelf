/*
指针变量的大小取决于地址的大小
32位平台下地址是32个bit位（即4个字节）
64位平台下地址是64个bit位（即8个字节）

示例代码：
#include <stdio.h>

int main()
{
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(short *));
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(double *));
    return 0;
}

说明：
- 无论指针指向什么类型的变量，指针变量本身的大小都是固定的
- 在32位系统中，所有指针都是4个字节
- 在64位系统中，所有指针都是8个字节
- 这是因为指针存储的是内存地址，而地址的大小由系统架构决定
*/