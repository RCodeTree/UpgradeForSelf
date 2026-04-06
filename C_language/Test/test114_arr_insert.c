#include <stdio.h>

/**
 * 插入元素并保持原数组的有序性
 * @return 0
 */ 
int main() {
    int a[5] = {1, 7, 20, 30};
    int t;
    printf("输入t的值: ");
    scanf("%d", &t);
    int index = 0;
    for (int i = 0; i < 5; i++) {
        if (t < a[i]) {
            index = i;
            break;
        } else if (t > a[i]) {
            index = i;
        }
    }
    if (index < 4) {
        for (int i = 4; i > index; i--) {
            a[i] = a[i - 1];
        }
        a[index] = t;
    }
    else {
        a[index] = t;
    }
    printf("插入元素后的数组为：\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
