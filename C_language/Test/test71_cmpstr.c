#include <stdio.h>

/*
    a vs a → 相等，指针后移
    b vs b → 相等，指针后移
    c vs c → 相等，指针后移
    d vs d → 相等，指针后移
    \0 vs e → 不相等，循环结束
*/
int strcmp(char *s, char *s1) {
    while (*s == *s1) {
        printf("*s = %c, *s1 = %c\n", *s, *s1);
        if (*s == '\0') {
            return 0;
        }
        ++s;
        ++s1;
    }

    return *s - *s1;
}

int main() {
    char str1[] = "abcd";
    char str2[] = "abcde";
    int ret = strcmp(str1, str2);
    printf("%d\n", ret);
    return 0;
}
