#include <stdio.h>

// 求并集
int f(int* a, int* b, int* c, int la, int lb, int lc)
{
    int cl = 0;
    for (int i = 0; i < la; i++)
    {
        int flag = 0;
        for (int j = 0; j < lc; j++)
        {
            if (a[i] == c[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) c[cl++] = a[i];
    }

    for (int i = 0; i < lb; i++)
    {
        int flag = 0;
        for (int j = 0; j < lc; j++)
        {
            if (b[i] == c[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) c[cl++] = b[i];
    }
    for (int i = 0; i < cl; i++)
        for (int j = 0; j < cl - 1 - i; j++)
            if (c[j] > c[j + 1])
            {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
    return cl;
}

int main()
{
    int
        a[5] = {2, 3, 13, 4, 3},
        b[6] = {2, 3, 11, 9, 1, 0},
        c[100] = {0};
    int len = f(a, b, c, 5, 6, 100);
    for (int i = 0; i < len; i++) printf("%d ", c[i]);
    printf("\n");
    return 0;
}
