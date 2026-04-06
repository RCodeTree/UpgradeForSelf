#include <stdio.h>
#include <math.h> // 需要使用 sqrt 函数

int main() {
    // 定义系数 a, b, c 和判别式 delta，以及两个根 x1, x2
    double a, b, c, delta, x1, x2;

    printf("请输入一元二次方程的三个系数 a b c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("输入格式错误\n");
        return 1;
    }

    // 情况1：a = 0，不是二次方程
    if (a == 0) {
        printf("不是二次方程\n");
    } else {
        // 计算判别式 delta = b^2 - 4ac
        delta = b * b - 4 * a * c;

        // 情况2：delta = 0，有两个相等的实根
        // 注意：浮点数比较通常用一个很小的误差范围，但这里为了演示算法逻辑直接用 == 0 也可以，
        // 或者严谨一点用 fabs(delta) < 1e-6
        if (delta == 0) {
            x1 = x2 = -b / (2 * a);
            printf("有两个相等实根：x1 = x2 = %.2f\n", x1);
        }
        // 情况3：delta > 0，有两个不等的实根
        else if (delta > 0) {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("有两个不等实根：x1 = %.2f, x2 = %.2f\n", x1, x2);
        }
        // 补充情况：delta < 0，无实数根
        else {
            printf("无实数根 (delta < 0)\n");
        }
    }

    return 0;
}
