#include <stdio.h>
#include <math.h>
int main()
{
    double y = 0.5, z = 1.5;
    int x = 10;

    x = (int)(atan2((double)x, y)) + exp(y - 0.2);

    printf("%d\n", x);
    return 0;
}