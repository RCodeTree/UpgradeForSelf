#include <stdio.h>

/**
 * @brief 判断一个数是否为偶数或奇数并且判断是否为负数或正数
 * @param n 一个数
 * @return 0
 */
int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("o");
        if (n < 0) {
            printf("f");
        } else {
            printf("z");
        }
    } else {
        printf("j");
        if (n < 0) {
            printf("f");
        } else {
            printf("z");
        }
    }
    return 0;
}
