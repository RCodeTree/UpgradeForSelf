#include <stdio.h>
#include <math.h>

double facn(double n)
{
    if (n == 0 || n == 1) return 1.0;
    return n * facn(n - 1);
}

int main()
{
    double e = 0;
    double i = 0;
    while (1)
    {
        double d = facn(i);
        double r = 1 / d;
        if (fabs(r) < 1e-7) break;
        e += r;
        i++;
    }
    printf("e的近似值为：%lf\n", e);
    return 0;
}
