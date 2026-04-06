#include <stdio.h>
#include <math.h>

int main()
{
    double a[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%lf", &a[i][j]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%lf ", a[i][j]);
    printf("\n");
    printf("-----------------------------\n");
    for (int i = 0; i < 3; i++)
    {
        double max = fabs(a[i][0]);
        for (int j = 0; j < 3; j++)
        {
            if (fabs(a[i][j]) > max)
            {
                max = fabs(a[i][j]);
            }
        }
        printf("max = %lf\n", max);
        for (int k = 0; k < 3; k++) a[i][k] /= max;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%.3lf ", a[i][j]);
    printf("\n");
    return 0;
}
