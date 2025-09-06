#include <stdio.h>
/*
数组
*/
int main()
{
    // 数组的下标是从0开始的
    // 在整型的数组中，是没有‘ \0 ’作为结束符的，只有在字符串里才有
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", arr); // 地址值：6422000
    int i = 0;
    while (i < 10)
    {
        printf("元素：%d\n", arr[i]);
        i++;
    }
    return 0;
}