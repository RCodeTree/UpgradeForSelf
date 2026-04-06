#include <stdio.h>
int main()
{
    /* 
    条件操作符（三目操作符）：
    exp1 ? exp2 : exp3  ---->  如果 exp1 为真，则执行 exp2；否则执行 exp3
    */

    // 示例
    int a = 10, b = 20, c = 0;
    c = a > b ? a : b;
    printf("%d\n", c); // 输出结果为 20
}