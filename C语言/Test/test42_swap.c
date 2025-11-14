#include <stdio.h>
int main( )
{
    int a = 1;
    int b = 2;
    printf("交换前：");
    printf("a=%d b=%d\n", a, b);

    a += b;
    b = a - b;
    a -= b;

    printf("交换后：");
    printf("a=%d b=%d\n", a, b);

    
    return 0;
}