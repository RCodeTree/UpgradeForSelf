#include <stdio.h>

/**
 * 输出200-400之间不能被3整除的数的和
 * @return 0
 */
int main() {
    int sum = 0;
    for (int i = 200; i <= 400; i++) {
        if (i % 3 != 0) {
            sum += i;
        }
    }
    printf("200-400之间能被3整除的数的和为：%d\n", sum);
    return 0;
}
