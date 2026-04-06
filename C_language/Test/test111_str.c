#include <stdio.h>
#include <string.h>

/**
 * 找到字符串数组中每个字符串的ASCII码之和最大的字符串
 * @return 0
 */
int main() {
    char str[3][10] = {"abcd", "abqe", "abed"};
    int len = strlen(str[0]);
    int arr[3] = {0};
    for (int i = 0; i < 3; i++) {
        int tmp = 0;
        for (int j = 0; j < len; j++) {
            tmp += str[i][j];
        }
        arr[i] = tmp;
    }
    int k = 0;
    for (int i = 0; i < 3; i++) {
        if (arr[i] > arr[k]) {
            k = i;
        }
    }
    printf("最大字符串：%s\n", str[k]);
    printf("行号：%d\n", k);
    return 0;
}
