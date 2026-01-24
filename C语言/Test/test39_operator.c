#include <stdio.h>
int main()
{
    int a, b, c;
    a = 5;
    c = ++a;
    b = ++c, c++, ++a, a++; // 逗号表达式，这里一共有四个表达式
    b += a++ + c; // += 是赋值运算符，优先级小于算术表达式
    printf("a = %d b = %d c = %d\n", a, b, c);
    return 0;
}