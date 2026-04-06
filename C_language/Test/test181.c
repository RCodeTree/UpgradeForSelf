#include <stdio.h>

int main()
{
    // err
    // char a[20];
    // a = "hello world";

    // char* s;
    // s = "hello world";
    // printf("%s", s);

    int a = 7, b = 2;
    b += (float)(a + b) / 2;
    printf("%d\n", b); // 6
    return 0;
}
