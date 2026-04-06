#include <stdio.h>

int main() {
    int num, index;
    int a[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
    printf("请输入要插入的数：");
    scanf("%d", &num);
    index = 0;
    printf("插入前的数组为：");
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < 10; i++) {
        if (num < a[i]) {
            index = i;
            break;
        }
    }
    for (int i = 10; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = num;
    printf("插入后的数组为：");
    for (int i = 0; i < 11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
