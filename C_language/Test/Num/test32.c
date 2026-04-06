#include <stdio.h>
#include <math.h>

void fun(int n) {
    int k, r;
    for (k = 2; k <= sqrt(n); k++) {
        r = n % k;
        while (r == 0) {
            printf("%d", k);
            n = n / k;
            if (n > 1) printf("*");
            r = n % k;
        }
    }
    if (n != 1) printf("%d\n", n);
}

void main() {
    int n;
    printf("请输入一个整数：");
    scanf("%d", &n);
    printf("%d=", n);
    if (n < 0) printf("-");
    n = abs(n);
    fun(n);
    printf("\n");
}
