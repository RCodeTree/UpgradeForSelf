#include <stdio.h>

// 求并集
int unionSet(int* a, int* b, int* c, int la, int lb, int lc)
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

// 求交集
int intersectionSet(int* a, int* b, int la, int lb, int* c, int lc)
{
    int i, j, k;
    int q = 0;
    for (i = 0; i < la; i++)
    {
        int t = 0;
        for (j = 0; j < lb; j++)
        {
            if (a[i] == b[j])
            {
                t = b[j];
                break;
            }
        }
        int flag = 0;
        for (k = 0; k < lc; k++)
        {
            if (t == c[k])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) c[q++] = t;
    }
    for (int i = 0; i < q; i++)
        for (int j = 0; j < q - 1 - i; j++)
            if (c[j] > c[j + 1])
            {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
    return q;
}

int main()
{
    int
        a[5] = {2, 3, 13, 4, 3},
        b[6] = {2, 3, 11, 9, 1, 0},
        c[100] = {0},
        d[100] = {0};
    int len = unionSet(a, b, c, 5, 6, 100);
    for (int i = 0; i < len; i++) printf("%d ", c[i]);
    printf("\n");
    len = intersectionSet(a, b, 5, 6, d, 100);
    for (int i = 0; i < len; i++) printf("%d ", d[i]);
    printf("\n");
    return 0;
}
