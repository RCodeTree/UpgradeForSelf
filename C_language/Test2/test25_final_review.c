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
    for (int i = 1; i < la; i++)
        if (a[i] > maxc)
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
 * 计算x和y的大小关系
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

/**
 * 打印x和y的大小关系
 * @param x 整数x
 * @param y 整数y
 * @return 无
 * @note 无
 */
void printNum(int x, int y)
{
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
    printf("%d\n", x++);
}

/**
 * 将8进制字符串转换为十进制整数
 * @param s 字符串s
 * @return 整数r
 * @note 无
 */
double eightToTen(char* s)
{
    int l = strlen(s);
    int n = l - 1;
    double r = 0;
    while (l)
    {
        r += pow(8, n) * (*s - '0');
        n--;
        s++;
        l--;
    }
    return r;
}

/**
 * 计算数组arr的游标位置
 * @param arr 数组arr
 * @return 整数*(p+2) - *(--p)
 * @note 无
 */
int arrCursor(int* arr)
{
    int* p = arr;
    return *(p + 2) - *(--p);
}

/**
 * 移除字符串s中的公共字符
 * @param s 字符串s
 * @return 整数1
 * @note 无
 */
int removeCommonChar(char* s)
{
    int i, j;
    for (i = 0; i < strlen(s); i++)
        for (j = i + 1; j < strlen(s); j++)
            if (s[i] == s[j])
            {
                // strcpy(s+j,s+j+1);
                int k = j;
                for (; s[k] != '\0'; k++) s[k] = s[k + 1];
                return 1;
            }
    return 0;
}

/**
 * 计算1到m的和
 * @param m 整数m
 * @return s
 */
int getSum(int m)
{
    static int i = 2;
    int s = 0;
    for (; i <= m; i++) s += i;
    return s;
}

/**
 * 在字符串s中搜索字符串search
 * @param s 字符串s
 * @param search 字符串search
 * @return 整数i或-1，i为search在s中的位置，-1为未找到
 * @note 无
 */
int searchStr(char* s, char* search)
{
    /*int i, j, k;
    int len1 = strlen(s);
    int len2 = strlen(search);
    for (i = 0; i < len1; i++)
    {
        j = i;
        for (k = 0; k < len2; k++)
        {
            if (s[j] != search[k]) break;
            j++;
        }
        if (search[k] == '\0') return i;
    }
    return -1;*/

    char *p1 = s, *p2 = search;
    while (*p1)
    {
        char* t = p1;
        p2 = search;
        while (*p2)
        {
            if (*t != *p2) break;
            t++;
            p2++;
        }
        if (*p2 == '\0') return p1 - s;
        p1++;
    }
    return -1;
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

    printf("%.0f\n", eightToTen("556"));

    printf("----------------------------------\n");

    int arr[5] = {2, 4, 6, 8, 10};
    int* p = arr + 1;
    printf("%d\n", arrCursor(p));

    printf("----------------------------------\n");

    char x[] = "Office--2007";
    puts(x);
    while (removeCommonChar(x)) puts(x);

    printf("----------------------------------\n");

    printf("%d\n", getSum(3) + getSum(5));

    printf("----------------------------------\n");

    int a1[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}}, i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j <= 3 - i; j++) printf("   ");
        for (j = 3 - i; j < 4; j++) printf("%3d", a1[i][j]);
        putchar('\n');
    }

    printf("----------------------------------\n");

    printf("%d\n", searchStr("abcd1235", "123"));

    return 0;
}
