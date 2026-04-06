#include <stdio.h>
#include <math.h>

/**
 * @brief 用级数求圆周率 --- Π^2 / 6 = 1/1^2 + 1/2^2 + 1/3^2 + ...
 *
 * @return int 0
 */
int main() {
    double num = 1;
    double sum = 0;
    int i = 1;
    while (num / (i * i) > pow(10, -6)) {
        sum += num / (i * i);
        i++;
    }
    double pi = sqrt(sum * 6);
    printf("pi = %f\n", pi);
    return 0;
}
