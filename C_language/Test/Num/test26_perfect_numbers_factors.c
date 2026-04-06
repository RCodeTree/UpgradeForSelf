#include <stdio.h>

/*
 * @brief 输出1000以内的完数
 */
int main() {
    for (int num = 1; num < 1000; num++) {
        int sum = 0;
        int count = 0;
        int arr[100];
        int i = 0;
        for (int j = 1; j < num; j++) {
            if (num % j == 0) {
                sum += j;
                count++;
                arr[i] = j;
                i++;
            }
        }
        if (sum == num) {
            printf("完数：%d\n", sum);
            for (int i = 0; i < count; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
