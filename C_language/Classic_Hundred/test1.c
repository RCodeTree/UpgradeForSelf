#include <stdio.h>

int main()
{
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
