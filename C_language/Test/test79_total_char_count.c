#include <stdio.h>
// @brief 统计字符串中数字的个数
int main() {
    char str[100];
    int count = 0;
    int i = 0;
    printf("请输入一个字符串：");
    scanf("%s", str);
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            count++;
        i++;
    }
    printf("字符串中数字的个数为：%d\n", count);

    return 0;
}
