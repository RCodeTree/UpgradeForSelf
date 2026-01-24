#include <stdio.h>

int main() {
    char c = '0';
    char str[80];
    printf("请输入一个字符串: ");
    scanf("%s", str);
    getchar(); // 消耗换行符
    printf("请输入要统计的字符: ");
    scanf("%c", &c);
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == c) count++;
        p++;
    }
    printf("字符'%c'在字符串中出现了%d次\n", c, count);
}
