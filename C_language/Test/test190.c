#include <stdio.h>
#include <string.h>

int main()
{
    /*printf("%llu\n", strlen("\\a\\56\t\00\abc")); // 6
    printf("%llu\n", sizeof("\nsum=%d\n")); // 包含一个'\0'，所以结果为9*/


    /*int a = 1, b = 2;
    printf("交换前a=%d,b=%d\n", a, b);
    // a = a + b;
    // b = a - b;
    // a = a - b;
    a = a ^ b; // 3
    b = a ^ b; // 1
    a = b ^ a; // 2
    printf("交换后a=%d,b=%d\n", a, b);*/

    /*int x = 12;
    char ch = 'a';
    printf("%c,%d,", ch, ch);
    printf("x=%%d\n", x);*/

    /*char str[] = "hello\tworld\n"; // 包括'\0'，为13
    printf("%d,%c\n", sizeof(str), *(str + 10)); // 13 d  */

    /*// int a[3][4] = {{1, 2, 3}, {4, 5}, {6, 7, 8}};
    // int* p;
    // // p = a[0];
    // // for (int i = 0; i < sizeof(a[0]) / sizeof(a[0][0]); i++)
    // //     printf("%d ", *(p + i));
    // p = &a[0][0];
    // printf("%d ", *(p + 5));*/

    // int x = 1, y;
    // y = 2.75 + x / 4;
    // printf("%d\n", y);

    // printf("%d\n", strlen("\x69\072\n")); // 3

    /*double a = 3.12;
    float b = 4.56;
    int c = 2;
    printf("%d\n", sizeof(f = a + b + c)); // 未定义行为*/

    /*char str[] = "abc\000def\n";
    printf("%lld\n", strlen(str)); // 3
    printf("%lld\n", sizeof(str)); // 9*/

    /*int i;
    for (i = 1; i++ < 4;);
    printf("%d\n", i); // 5*/

    // int a = 1;
    // int b = 10;
    // do
    // {
    //     b -= a;
    //     a++;
    // }
    // while (b-- < 0);
    // printf("%d\n", b); //


    // int a[2][3] = {2, 4, 6, 8, 10, 12};
    // printf("%d\n", *(a[1] + 2)); // 12
    return 0;
}
