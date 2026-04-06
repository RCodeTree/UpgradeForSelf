#include <stdio.h>
int main
{
    /* 
    关系操作符：
    > 大于
    < 小于
    >= 大于等于
    <= 小于等于
    == 等于
    != 不等于
    */
    // 示例
    int a = 10;
    int b = 20;
    int c = a > b;
    printf("%d\n", c); // 输出结果为 0

    // 示例2
    int d = a < b;
    printf("%d\n", d); // 输出结果为 1

    // 示例3
    int e = a >= b;
    printf("%d\n", e); // 输出结果为 0

    // 示例4
    int f = a <= b;
    printf("%d\n", f); // 输出结果为 1

    // 示例5
    int g = a == b;
    printf("%d\n", g); // 输出结果为 0

    // 示例6
    int h = a != b;
    printf("%d\n", h); // 输出结果为 1

    return 0;
}