#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * 插入字符串b到字符串a的position位置
 * @param a 字符串a
 * @param b 字符串b
 * @param position 插入位置
 * @return 无
 * @note 无
 */
void insertString(char* a, char* b, int position)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    for (int i = len1; i >= position; i--) a[i + len2] = a[i];
    int j = 0;
    for (int i = position; b[j] != '\0'; i++, j++) a[i] = b[j];
}

/**
 * 插入字符串b到字符串a的最大字符位置的下一个位置(后面)
 * @param a 字符串a
 * @param b 字符串b
 * @return 无
 * @note 无
 */
void insertString2(char* a, char* b)
{
    int la = strlen(a);
    int lb = strlen(b);
    char maxc = a[0];
    int maxi = 0;
    for (int i = 1; i < la; i++) if (a[i] > maxc)
    {
        maxc = a[i];
        maxi = i;
    }
    for (int i = la; i >= maxi + 1; i--) a[i + lb] = a[i];
    int j = 0;
    for (int i = maxi + 1; b[j] != '\0'; i++, j++) a[i] = b[j];
}

/**
 * 连接字符串b到字符串a的后面
 * @param a 字符串a
 * @param b 字符串b
 * @return 无
 * @note 无
 */
void connectString(char* a, char* b)
{
    int la = strlen(a);
    int lb = strlen(b);
    if (lb > 5)
    {
        for (int i = 0; i < 5; i++) a[la + i] = b[i];
    }
    else
    {
        for (int i = 0; i < lb; i++) a[la + i] = b[i];
    }
}

/**
 * @param x 整数x
 * @param y 整数y
 * @return 整数x
 * @note 无
 */
int num(int x, int y) // x = 1, y = 0
{
    // return x > (y + x) ? 10 : 12.5 > y++ ? 'a' : 'A';
    return x-- > (y + x) ? 5 : 25 > y++ ? '1' : '2';
}

void printNum(int x, int y)
{
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
}

int main()
{
    char a[100] = "abcd1235";
    char b[] = "999";
    printf("%s\n", a);
    insertString(a, b, 3);
    printf("%s\n", a);

    printf("----------------------------------\n");

    char c[100] = "bcdzmah";
    char d[] = "1234";
    printf("%s\n", c);
    printf("%s\n", c);
    insertString2(c, d);

    printf("----------------------------------\n");

    char e[100] = "99999";
    char f[] = "123456789";
    connectString(e, f);
    printf("%s\n", e);

    printf("----------------------------------\n");

    printf("--num(1, 0)--: %c\n", num(1, 0));

    printf("----------------------------------\n");

    printNum(1, 0);

    printf("----------------------------------\n");
    return 0;
}
