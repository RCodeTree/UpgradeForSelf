#include <stdio.h>

/**
 * 测试++运算符
 * @return 0
 */
int main() {
    int a, b;
    a = 2, b = 5, a++, b++, a + b;
    printf("a = %d, b = %d, a + b = %d\n", a, b, a + b); // a = 3, b = 6, a + b = 9
    return 0;
}
