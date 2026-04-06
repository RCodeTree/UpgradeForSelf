#include <stdio.h>
/**
 * @brief 对数组进行排序
 *
 * @param array 数组指针
 * @param n 数组大小
 */
void sort(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(array + j) > *(array + j + 1)) {
                int tmp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = tmp;
            }
        }
    }
}

int main() {
    int N;
    printf("请输入数组的大小：");
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        printf("请输入数组的第%d个元素：", i + 1);
        scanf("%d", &arr[i]);
    }
    sort(arr, N);
    printf("排序后的数组为：");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
