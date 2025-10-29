#include <stdio.h>
int main()
{
    /* 
    赋值运算符：
    = 赋值
    += 加法赋值
    -= 减法赋值
    *= 乘法赋值
    /= 除法赋值
    %= 取余赋值
    &= 按位与赋值
    |= 按位或赋值
    ^= 按位异或赋值
    <<= 左移赋值
    >>= 右移赋值
    */

    // 各个示例
    int a = 10;
    int b = 3;
    
    a += b; // 等价于 a = a + b;
    printf("%d\n", a); // 输出结果为 13

    a -= b; // 等价于 a = a - b;
    printf("%d\n", a); // 输出结果为 10

    a *= b; // 等价于 a = a * b;
    printf("%d\n", a); // 输出结果为 30

    a /= b; // 等价于 a = a / b;
    printf("%d\n", a); // 输出结果为 10

    a %= b; // 等价于 a = a % b;
    printf("%d\n", a); // 输出结果为 1

    a &= b; // 等价于 a = a & b;
    printf("%d\n", a); // 输出结果为 2

    a |= b; // 等价于 a = a | b;
    printf("%d\n", a); // 输出结果为 11

    a ^= b; // 等价于 a = a ^ b;
    printf("%d\n", a); // 输出结果为 9

    a <<= b; // 等价于 a = a << b;
    printf("%d\n", a); // 输出结果为 72

    a >>= b; // 等价于 a = a >> b;
    printf("%d\n", a); // 输出结果为 9




    return 0;
}