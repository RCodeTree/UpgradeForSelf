#include <stdio.h>
#include <math.h>
// @brief 打印100-200之间的所有素数
void main() {
    int count = 1;
    int flag = 0;
    for (int num = 100; num < 200; num++) {
        flag = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d ", num);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }
}
