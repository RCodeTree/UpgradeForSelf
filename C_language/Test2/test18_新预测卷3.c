#include <stdio.h>

/*union Data
{
    int a;
    char b;
};

int main()
{
    union Data d;
    d.a = 65;
    printf("%c\n", d.a);
    d.b = 'B';
    printf("%d\n", d.b);
    union Data d2;
    d2 = d;
    return 0;
}*/

// 编程题
int f(int* a, int* b, int la, int lb, int* c, int lc)
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
    int a[5] = {2, 3, 13, 4, 3},
        b[6] = {2, 3, 11, 9, 1, 0};
    int c[100] = {0};
    int len = f(a, b, 5, 6, c, 100);
    printf("交集:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}
