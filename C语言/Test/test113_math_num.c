#include <stdio.h>
#include <math.h>

/**
 * 求解一元二次方程的根
 * @return 0
 */
int main() {
    double a, b, c, x1, x2, delta;
    printf("请输入a、b、c的值：");
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = (b * b) - (4 * a * c);
    if (delta > 0) {
        printf("有两个实数根：");
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1 = %lf, x2 = %lf\n", x1, x2);
    } else if (delta == 0) {
        printf("有两个相等的根：");
        x1 = x2 = (-b) / (2 * a);
        printf("x1 = x2 = %lf\n", x1);
    } else {
        printf("无实数根！\n");
    }
    return 0;
}
