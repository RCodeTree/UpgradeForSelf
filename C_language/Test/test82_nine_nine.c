#include <stdio.h>

/**
 * @brief 输出99乘法表
 *
 * @return int 0
 */
int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) printf("%d*%d=%d\t", j, i, j * i);
            else printf("     \t");
        }
        printf("\n");
    }
    return 0;
}
