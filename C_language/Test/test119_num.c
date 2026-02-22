#include <stdio.h>

/**
 * 计算1-100之间所有偶数的和
 * @return 0
 */
int main() {
    int s = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            s += i;
        }
    }
    printf("1-100之间所有偶数的和为：%d\n", s);
    return 0;
}
