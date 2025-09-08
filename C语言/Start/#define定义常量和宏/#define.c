/* 
#define 定义常量、宏
    常量：使用#define定义的变量，在程序运行过程中，不能被修改
    宏：使用#define定义的函数，在程序运行过程中，参数会被替换为参数值
*/
#include <stdio.h>
#define A 10 // 定义一个常量
#define ADD(x, y) ((x) + (y)) // 定义一个宏，实现两个数的加法
int main()
{
    int result;
    int a = 10;
    int b = 20;

    result = ADD(a, b);
    printf("%d\n", result);
    return 0;
}
