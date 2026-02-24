#include <stdio.h>

/*
 * 功能：查找二维数组中的最小值及其所在的行号和列号
 * 输入：一个3行4列的二维数组a
 * 输出：最小值min，所在的行号row，所在的列号col
 */
int main()
{
    int i, r;
    char *s1 = "bus", *s2 = "book";
    for (i = r = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] == s2[i]) i++;
        else
        {
            printf("%c\n", s1[i]);
            printf("%c\n", s2[i]);
            r = s1[i] - s2[i];
            break;
        }
    printf("%d\n", r);
    return 0;
}
