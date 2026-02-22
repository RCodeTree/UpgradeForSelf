#include <stdio.h>
#include <stdlib.h>

/*
 * 动态数组的设计
 */
int main() {
    int *arr = (int *) malloc(sizeof(int) * 5);
    int *t = arr;
    *t = 1;
    for (int i = 1; i < 5; i++)
        *(t + i) = i + 1;
    for (int i = 0; i < 5; i++)
        printf("%d ", *(t + i));
    printf("\n");
    return 0;
}
