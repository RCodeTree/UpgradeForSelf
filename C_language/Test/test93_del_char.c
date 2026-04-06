#include <stdio.h>
/*
 * @brief 删除字符串中的指定字符
 * @param s 字符串指针
 * @param c 要删除的字符
 */
void del(char *s, char c) {
    char *p = s;
    while (*p != '\0') {
        if (*p != c) {
            *s = *p;
            s++;
        }
        p++;
    }
    *s = '\0';
}

int main() {
    char c;
    printf("输入要删除的字符: ");
    scanf(" %c", &c);
    char str[100];
    printf("输入字符串: ");
    scanf("%s", str);
    del(str, c);
    printf("删除后的字符串为: %s\n", str);
    return 0;
}
