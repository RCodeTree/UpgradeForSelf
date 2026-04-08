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
void f(int* a, int* b, int la, int lb, int* c, int lc)
{
    int i, j, k, t;
    int q = 0;
    for (i = 0; i < la; i++)
    {
        for (j = 0; j < lb; j++)
        {
            if (a[i] == b[j])
            {
                t = b[j];
                break;
            }
        }
        for (k = 0; k < lc; k++)
        {
            if (t != c[k] && j < lb)
            {
                c[q++] = t;
                break;
            }
            else break;
        }
    }
    for (int i = 0; i < q; i++)
        for (int j = 0; j < q - 1 - i; j++)
            if (c[j] > c[j + 1])
            {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
}

int main()
{
    int a[5] = {1, 1, 2, 3, 4}, b[6] = {2, 1, 3, 5, 6, 7};
    int c[100] = {0};
    f(a, b, 5, 6, c, 100);
    printf("交集:\n");
    for (int i = 0; i < 100; i++)
        if (c[i] != 0) printf("%d ", c[i]);
    printf("\n");
    return 0;
}
