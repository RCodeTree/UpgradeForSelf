#include <stdio.h>
int main()
{
    /* 
    解析：
    格式化输出字符串 s=%-5.3s
    字符串”student”的前 3 个字符是 stu
    - 表示左对齐
    5 表示输出宽度为 5
    .3 表示输出 3 个字符
    因此输出结果是 stu
    */
    printf("s=%-5.3s","student"); // s=stu
    return 0;
}