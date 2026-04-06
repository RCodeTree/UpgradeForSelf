#include <stdio.h>

int string_length(char* str)
{
    char* p = str;
    int c = 0;
    while (*p)
    {
        c++;
        p++;
    }
    return c;
}

int main()
{
    //  输入三个整数，输出其中的最大值
    /* int n, max = 0;
    for (int i = 0; i < 3; i++) {scanf("%d", &n); if (n > max) max = n;}
    printf("max=%d\n", max); */

    //  输出100以内的所有偶数的和
    /* int s = 0;
      for (int i = 1; i <= 100; i++)
          if (i % 2 == 0) s += i;
      printf("s=%d\n", s); */

    /*char str[100];
    scanf("%s", str);
    int l = string_length(str);
    printf("%d\n", l);*/

    //  输出5*5的二维数组的元素, 并求其对角线元素的和
    /*int a[5][5] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        }, s = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 5; i++) s += a[i][i];
    printf("对角线元素和s=%d\n", s);*/

    char a[100], b[100];
    printf("输入a串：");
    scanf("%s", a);
    printf("输入b串：");
    scanf("%s", b);
    printf("连接前a=%s\n", a);
    char* p = a;
    while (*p) p++;
    int i = 0;
    while (b[i] != '\0')
    {
        *p = b[i];
        p++;
        i++;
    }
    *p = '\0';
    printf("连接后a=%s\n", a);
    return 0;
}
