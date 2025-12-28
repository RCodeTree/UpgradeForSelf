#include <stdio.h>

/*
 * @brief 将字符串转换为整数
 */
int main() {
    char str[16];
    int result = 0;
    printf("输入一个字符串：");
    scanf("%s", str);
    char *p = str;
    while (*p) {
        if (*p >= '0' && *p <= '9') {
            result = result * 10 + (*p - '0');
        }
        p++;
    }

    printf("转换后的整数为：%d\n", result);
    return 0;
}
