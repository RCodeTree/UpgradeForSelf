#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6

int string_length(char* str)
{
    char* p = str;
    int len = 0;
    while (*p)
    {
        len++;
        p++;
    }
    return len;
}

int main()
{
    // 6  输入20个整数存入一数组，输出其中能被数组中其它元素(至少有一个)整除的那些数组元素
    // int a[N] = {2, 4, 6, 8, 10, 12};
    // for (int i = 0; i < N; i++)
    // {
    //     int flag = 0;
    //     for (int j = 0; j < N; j++)
    //     {
    //         if (j != i)
    //         {
    //             if (a[i] % a[j] == 0)
    //             {
    //                 flag = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     if (flag) printf("%d ", a[i]);
    // }
    // printf("\n");
    // int a[N] = {2, 4, 6, 8, 10, 12};
    // for (int i = 0; i < N; i++)
    // {
    //     int flag = 0; // 标记是否存在其他元素能整除a[i]
    //     for (int j = 0; j < N; j++)
    //     {
    //         if (j != i && a[i] % a[j] == 0)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag)
    //     {
    //         printf("%d ", a[i]);
    //     }
    // }
    // printf("\n");


    // 7  输入两个数组（数组元素个数自定），输出在两个数组中都出现的元素（如a[5]={2,3,4,5,6}，b[6]={3,5,7,9,10,-1}，则输出3、5）
    // int a[5], b[5], c[1000] = {0};
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%d", &a[i]);
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%d", &b[i]);
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if (a[i] == b[j])
    //         {
    //             c[a[i]] = a[i];
    //         }
    //     }
    // }
    // for (int i = 0; i < 1000; i++)
    // {
    //     if (c[i] != 0) printf("%d ", c[i]);
    // }
    // printf("\n");
    // 更高效的交集查找（不需要额外数组）
    // printf("交集元素：");
    // for (int i = 0; i < 5; i++)
    // {
    //     int isDuplicate = 0;
    //     // 检查当前元素是否已经输出过
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (a[i] == a[j])
    //         {
    //             isDuplicate = 1;
    //             break;
    //         }
    //     }
    //
    //     if (!isDuplicate)
    //     {
    //         // 检查是否在b数组中
    //         for (int k = 0; k < 5; k++)
    //         {
    //             if (a[i] == b[k])
    //             {
    //                 printf("%d ", a[i]);
    //                 break;
    //             }
    //         }
    //     }
    // }
    // printf("\n");

    // 8  输入两个数组（数组元素个数自定），输出在两个数组中都不出现的元素（如a[5]={2,3,4,5,6}，b[6]={3,5,7,9,10,-1}，则输出2、4、6、7、9、10、-1）
    /*int a[5] = {2, 3, 4, 5, 6}, b[6] = {3, 5, 7, 9, 10, -1};
    for (int i = 0; i < 5; i++)
    {
        int flag = 0;
        for (int j = 0; j < 6; j++)
        {
            if (a[i] == b[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d ", a[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        int flag = 0;
        for (int j = 0; j < 5; j++)
            if (b[i] == a[j])
            {
                flag = 1;
                break;
            }
        if (!flag) printf("%d ", b[i]);
    }*/


    // 9  编程，将字符数组S2中的全部字符拷贝到字符数组S1中（不用strcpy函数）
    /*char S1[100], S2[100];
    puts("输入S1：");
    gets(S1);
    puts("输入S2：");
    gets(S2);
    printf("复制前S1 = %s\n", S1);
    int i = 0;
    while (S2[i] != '\0')
    {
        S1[i] = S2[i];
        i++;
    }
    S1[i] = '\0';
    printf("复制后S1 = %s\n", S1);*/

    // 11  输入一行小写字母后，将字母变成其下一字母（a变成b、b变成c、c变成d、…、x变成y、y变成z、z变成a）输出
    /*char* s = malloc(100);
    printf("请输入小写字母：");
    scanf("%s", s);
    char* p = s;
    while (*p)
    {
        if (*p >= 'a' && *p <= 'y')
        {
            *p = *p + 1;
        }
        else if (*p == 'z')
        {
            *p = 'a';
        }
        p++;
    }
    printf("%s\n", s);
    free(s);*/


    // int x = 10;
    // x += x -= x * x;
    // printf("%d\n", x);


    // char str[] = "China";
    // char* p = str;
    // while (*p != '\0')
    // {
    //     printf("%c", *p + 1);
    //     p++;
    // }
    // printf("\n");


    //  输入一个3*3的矩阵，输出主对角线元素之和
    // int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int i, j, sum = 0;
    // for (i = 0; i < 3; i++)
    // {
    //     for (j = 0; j < 3; j++)
    //     {
    //         if (i == j)
    //         {
    //             sum += a[i][j];
    //         }
    //     }
    // }
    // printf("%d\n", sum);


    // int arr[5] = {2, 4, 6, 8, 10};
    // int* p;
    // for (p = arr; p < &arr[5]; p++) // &arr[5] 或 arr + 5
    // {
    //     printf("%d ", *p);
    // }


    // int n;
    // int min = 0, max = 0;
    // for (int i = 1; i <= 10; i++)
    // {
    //     scanf("%d", &n);
    //     if (n < min) min = n;
    //     if (n > max) max = n;
    // }
    // printf("min = %d, max = %d\n", min, max);


    // char str[100];
    // printf("请输入一个字符串：");
    // gets(str);
    // int l = string_length(str);
    // printf("字符串的长度为：%d\n", l);


    int a = 7, b = 9, t;
    t = a > b ? a : b;
    printf("%d", t);
    return 0;
}
