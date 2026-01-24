#include <stdio.h>
#include <string.h>

int main() {
    /*
    // 四舍五入
    float f=6.281523;
    int n;
    n=f*1000+0.5, f=n/1000.0;
    printf("%f\n",f); // 6.282000
    */

    /*int m = 7;
    float x = 2.5, y = 4.7;
    printf("%f\n", x + m % 3 * (int) (x + y) % 2 / 4); // 2.500000*/

    /*

    printf("%f\n", 3.0 / (int) 2.0);
    printf("%f\n", (int) 3.0 / 2.0);
    printf("%d\n", (int) (3.0 / 2.0));
    printf("%d\n", (int) 2.0 / (int) 3.0);
    // 1.500000
    // 1.500000
    // 1
    // 0
    */

    /*int a, b;
    double c;
    a = c = b = 3.5 / 2;
    printf("%d\n", a); // 1
    printf("%d\n", b); // 1
    printf("%f\n", c); // 1.000000*/


    /*int a, b;
    double c;
    a = b = c = 3.5 / 2;
    printf("%d\n", a); // 1
    printf("%d\n", b); // 1
    printf("%f\n", c); // 1.7500000*/

    /*int a, b;
    double c;
    a = b = c = 3 / 2; // 3/2 进行的是整数运算
    printf("%d\n", a); // 1
    printf("%d\n", b); // 1
    printf("%f\n", c); // 1.000000*/

    /*int a, b;
    double c;
    a = c = b = 3 / 2; // 3/2 进行的是整数运算
    printf("%d\n", a); // 1
    printf("%d\n", b); // 1
    printf("%f\n", c); // 1.000000*/

    // int a = 041;
    // printf("%d\n", a);
    // printf("%o\n", a);
    // printf("%x\n", a);
    // printf("%#o\n", a);
    /*
     * result:
     * 33
     * 41
     * 21
     * 041
     */


    /* 
    - str1 : "abc\\\t\nqw"
    - 展开： a b c \ \t \n q w
    - 长度（ strlen ）：8
    - 总字节数（ sizeof ）：9

    - str2 : "\\ta\12\123\1234\012"
    - 展开： \ t a \n 'S' 'S' '4' \n （其中 \12 = \012 为换行， \123 八进制83即 'S' ， \1234 是 'S' 和字符 '4' ）
    - 长度（ strlen ）：8
    - 总字节数（ sizeof ）：9

    - str3 : "abc\192\012r\092a"
    - 展开： a b c \x01 '9' '2' \n r \0 '9' '2' a （ \192 → \1 + '9' + '2' ， \092 → \0 + '9' + '2' ）
    - 长度（ strlen ）：8（因中间有 \0 ，在 r 之后立刻截断）
    - 总字节数（ sizeof ）：13（包含中间的 \0 以及结尾自动添加的 \0 ）

    - str4 : "\xab\012\xA1\t"
    - 展开： \xAB \n \xA1 \t
    - 长度（ strlen ）：4
    - 总字节数（ sizeof ）：5
    */
    // char str1[] = "abc\\\t\nqw";
    // char str2[] = "\\ta\12\123\1234\012";
    // char str3[] = "abc\192\012r\092a";
    // char str4[] = "\xab\012\xA1\t";
    //
    // printf("%ld %ld\n", strlen(str1), sizeof(str1));
    // printf("%ld %ld\n", strlen(str2), sizeof(str2));
    // printf("%ld %ld\n", strlen(str3), sizeof(str3));
    // printf("%ld %ld\n", strlen(str4), sizeof(str4));

    // int a, b;
    // scanf("%2d%2d", &a, &b); // 1010 2020
    // printf("%d\n", a + b); // 20

    // int a = 7, b = 4;
    // float m = 38.4, n = 6.4, x;
    // x = a / 2 + b * m / n + 1 / 2 + 0.55;
    // printf("%.1f\n", x); // 27.5

    int a, b;
    scanf("%2d%2d", &a, &b);
    printf("%d\n", b);

    float f = 123.4567;
    printf("%.3f\n", f);

    int m = 1, n = 2;
    m += n;
    n = m - n;
    m -= n;
    printf("%d,%d\n", m, n);

    return 0;
}
