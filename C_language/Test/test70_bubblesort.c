#include  <stdio.h>

int main() {
    int arr[5] = {1, 2, 4, 3, 5};

    int flag = 1; // 假设数组已经有序

    // 冒泡排序
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0; // 数组无序 ----> 说明数组在当前轮次中发生了交换，不是有序的
            }
        }

        if (flag == 1) {
            break; // 数组有序，提前结束排序
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
