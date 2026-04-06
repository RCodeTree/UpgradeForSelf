#include <stdio.h>

/**
 * 找到100以内能被17整除的最大数
 * @return 0
 */
int main() {
    int max = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 17 == 0) {
            if (i > max) {
                max = i;
            }
        }
    }
    printf("100以内能被17整除的最大数为：%d\n", max);
    return 0;
}
