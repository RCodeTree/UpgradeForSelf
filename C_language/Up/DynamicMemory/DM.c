#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    // 初始化数组
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    // 扩大数组
    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("内存重分配失败\n");
        return 1;
    }
    
    // 使用新分配的内存
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }
    
    // 输出数组
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    // 释放内存
    free(arr);
    arr = NULL;
    
    return 0;
}