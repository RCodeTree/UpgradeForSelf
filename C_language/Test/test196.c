#include <stdio.h>

int main()
{
    /*int max = 0;
    for (int i = 100; i < 1000; i++)
        if (55555 % i == 0)
            if (i > max) max = i;
    printf("最大的三位约数：%d\n", max);*/


    int n;
    scanf("%d", &n);
    /*int t = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int k = 1; k <= 2 * i - 1; k++) printf("*");
        printf("\n");
    }*/

    /*for (int i = 1; i <= n; i++)
    {
        int t = 2;
        for (int j = 1; j <= i; j++) printf("%d ", 1);
        for (int k = 1; k <= (n - i); k++)
        {
            printf("%d ", t);
            t++;
        }
        printf("\n");
    }*/

    double sum = 0;
    double i = 1.0;
    while (1)
    {
        double r = 1 / i++;
        if (r < 1e-3) break;
        sum += r;
    }
    printf("%.2f\n", sum);


    return 0;
}
