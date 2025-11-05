#include <stdio.h>

int main()
{
    char a = '\017'; // 15 的八进制表示
    printf("%d\n", a); // 15

    char b = '\f'; // 换页符
    printf("%c\n", b);

    // char c = '\\0'; // 反斜杠和 0
    // printf("%c\n", c);

    char d = '\xf'; // 15 的十六进制表示
    printf("%d\n", d); // 15

    char e = '\101'; // 65 的八进制表示
    printf("%c\n", e); // A

    char f = '\a';
    printf("%c\n", f); // 响铃符

    double g = 2.4;
    printf("%f\n", g / 2); // 1.200000



    return 0;
}