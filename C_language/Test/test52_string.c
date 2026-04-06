#include <stdio.h>
#include <string.h>
int main()
{
    char str[100] = "Hello, World!";
    char str2[100];


    /* 
    为什么不能用 = ：
         数组不是可赋值对象； char a[10]; a = "abc"; 是非法。
         只有初始化时可用字面量： char a[] = "abc"; 或 char a[10] = "abc"; 。
         指针可以指向字面量： char *p = "abc"; （指向只读存储，不能改内容）。
    */

    // str2 = "abcd"; // 错误！不能直接赋值
    strcpy(str2, "abcd"); // 正确！使用 strcpy 函数复制字符串

    printf("%s\n", str);

    return 0;
}