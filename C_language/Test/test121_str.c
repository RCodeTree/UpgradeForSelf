#include <stdio.h>

/**
 * 从键盘输入一个字符串，将其中的所有字母a替换为*
 * @return 0
 */
int main() {
    char s[100];
    printf("请输入一个字符串：");
    scanf("%s", s);
    printf("替换前：%s\n", s);
    char *p = s;
    while (*p) {
        if (*p == 'a') {
            *p = '*';
        }
        p++;
    }
    printf("替换后：%s\n", s);
    return 0;
}
