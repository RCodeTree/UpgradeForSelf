#include <stdio.h>

int main()
{
    /* 
     * 测试1：
     * 输入：234
     * 输出：234 12
     * 解释：234的4位补码为00001010，右移4位为00000000，与00001111按位与为00000000，即12。
     */
    unsigned a, b, c, d;
    // scanf("%o", &a);
    b = a >> 4;
    c = ~(~0 << 4);
    d = b & c;
    printf("%o\n%o\n", a, d);

    int m, n;
    m = 234;
    n = ~m;
    printf("The a's 1 complement(decimal) is %d \n", n);
    m = ~m;
    printf("The a's 1 complement(hexidecimal) is %x \n", m);
    return 0;
}
