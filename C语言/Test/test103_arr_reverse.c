#include <stdio.h>

/*
 * @brief 逆序数组元素
 * @param arr 数组指针
 * @param n 数组元素个数
 */
void swap(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = *(arr + i);
        *(arr + i) = *(arr + (n - 1 - i));
        *(arr + (n - 1 - i)) = tmp;
    }
}

int main() {
    int a[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 0;
    printf("请输入要逆序的元素个数：");
    scanf("%d", &n);
    printf("逆序前的数组元素为：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    swap(a, n);
    printf("逆序后的数组元素为：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
