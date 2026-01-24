#include <stdio.h>

int fib(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return fib(n - 1) + fib(n - 2);
}

void main() {
    int n;
    printf("输入前n项的数：");
    scanf("%d", &n);
    int result = fib(n);
    printf("%d\n", result);
}
