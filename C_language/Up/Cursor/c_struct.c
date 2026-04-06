#include <stdio.h>

struct Test {
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
} *p = (struct Test *) 0x100000;

// 假设 p 的值为0x100000 如下表达式的值分别为多少？
// 已知，结构体 Test 类型的变量大小是 20 字节
int main() {
    printf("%p\n", p + 0x1); // 0x100014 ----> p是指针，+1 操作是 p 指向的结构体变量的下一个字节，即跳过一个结构体变量的大小
    printf("%p\n", (unsigned long) p + 0x1); // 0x100001 ----> p 转换为无符号长整型后再加上 0x1
    printf("%p\n", (unsigned int *) p + 0x1); // 0x100004 ----> p 转换为无符号整型指针后再加上 0x1


    return 0;
}
