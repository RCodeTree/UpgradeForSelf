#include <stdio.h>
#include <string.h>

#define ROW 4
#define COL 4

// int fun(int a[][COL], int row, int* b)
// {
//     int k = 0;
//     int s = 0;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < row; j++)
//         {
//             if (a[i][j] > 0 && a[i][0] != 0)
//             {
//                 b[k++] = a[i][j];
//             }
//         }
//     }
//     for (int i = 0; i < row * row; i++)
//     {
//         if (b[i] > 0)
//         {
//             printf("%d ", b[i]);
//             s += b[i];
//         }
//     }
//     printf("\n");
//     return s;
// }

void fun(char* s1, char* s2)
{
    char *p = s1, *q = s2, *t = s1;
    int len = strlen(s1);
    int i = 0;
    int len2 = len;
    while (*q)
    {
        p = s1;
        len = len2;
        while (len--)
        {
            if (*q == *p) *p = '1';
            p++;
        }
        q++;
    }
    printf("s1 = %s\n", s1);
    p = s1;
    while (len2--)
    {
        if (*t != '1')
        {
            *(p + i) = *t;
            i++;
        }
        t++;
    }
    *(p + i) = '\0';
}

int main()
{
    // int a[5] = {0};
    // a[0] = 1;
    // for (int i = 0; i < 5; i++)
    // 	printf("%d\n", a[i]);

    // struct stud
    // {
    //     char num[6];
    //     int s[4];
    //     double ave;
    // };
    // printf("%lu\n", sizeof(struct stud)); // 32

    // struct
    // {
    //     int x;
    //     int y;
    // } s[2] = {{1, 2}, {3, 4}}, *p = s;
    // printf("%d\n", ++p->x); // 2

    // union data
    // {
    //     int a[10];
    //     int b[2][5];
    // };
    // union data ab;
    // int i, j;
    // for (int i = 0; i < 10; i++)
    //     scanf("%d", &(ab.a[i]));

    // int sss = 0, b[16] = {0};
    // int a[ROW][COL] = {{1, 2, -3, -4}, {0, -12, -13, 14}, {-21, 23, 0, -24}, {-31, 32, -33, 0}};
    // sss = fun(a, ROW, b);
    // printf("sss = %d\n", sss);

    char s1[300] = "abcaa63akdfk", s2[300] = "ayk5";
    fun(s1, s2);
    printf("%s\n", s1);
    return 0;
}
