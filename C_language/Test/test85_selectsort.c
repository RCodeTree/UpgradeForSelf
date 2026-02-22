#include <stdio.h>

/*
 * @brief 选择排序
 */
int main() {
    int arr[] = {81, 7, 9, 6, -2, 50, 44, 1, 3, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len - 1; i++) {
        int k = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[k])
                k = j;
        }
        // if (k != i) {
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        // }
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
