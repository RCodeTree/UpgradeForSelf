#include <stdio.h>

/**
 * @brief 统计字符串中每个字符连续出现的次数
 *
 * @param s 输入的字符串
 */
void fun(char s[]) {
    int arr[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        arr[(unsigned int) s[i]]++;
    }

    printf("%s\n", s);
    for (int i = 0; i < 256; i++) {
        if (arr[i] != 0) {
            printf("%c-%d\n", i, arr[i]);
        }
    }
}

int main() {
    char ch[] = "AABB%%$$!!oo09912MMM;;1@@,,,!!";
    fun(ch);
    return 0;
}
