#include <stdio.h>


/*
 * 计算等比数列前n项和
 */
int main()
{
    double s = 0.0, a = 2, b = 1, n, tmp;
    scanf("%lf", &n);
    for (double i = 1; i <= n; i++)
    {
        s += a / b;
        tmp = b;
        b = a;
        a = a + tmp;
    }
    printf("%lf\n", s);

    return 0;
}
