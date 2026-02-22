#include <math.h>
#include <stdio.h>


/*
 * @brief 水仙花数是指一个3位数，它的每个位上的数字的立方和等于它本身。
 * 例如：153 = 1^3 + 5^3 + 3^3。
 */
int main() {
    double sum = 0;
    for (int num = 100; num < 1000; num++) {
        int g = num % 10;
        int s = num % 100 / 10;
        int b = num / 100;
        sum = pow(g, 3) + pow(s, 3) + pow(b, 3);
        if (sum == num) printf("%d ", num);
    }
    printf("\n");

    return 0;
}
