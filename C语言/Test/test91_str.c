#include <stdio.h>

/**
 * @brief 统计字符串中每个字符连续出现的次数
 *
 * @param s 输入的字符串
 */
void fun(char s[]) {
    int arr[20];
    int count = 1;
    int i = 0;
    char *previous = s;
    char *next = s + 1;
    int len = 0;
    int sum = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    s = previous;
    for (int i = 0; i < len - 1; i++)
        for (int j = 1; j < len - 1 - i; j++)
            if (s[j] > s[j + 1]) {
                char c = s[j];
                s[j] = s[j + 1];
                s[j + 1] = c;
            }
    while (*previous != '\0' || *next != '\0') {
        if (*previous == *next) {
            count++;
            previous++;
            next++;
            continue;
        }
        sum++;
        arr[i] = count;
        count = 1;
        i++;
        previous++;
        next++;
    }
    for (int i = 0; i < sum; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    char ch[] = "AABB%%$$!!oo09912MMM;;1@@,,,!!";
    fun(ch);
    return 0;
}
