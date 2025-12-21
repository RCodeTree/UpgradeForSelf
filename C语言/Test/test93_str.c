#include <stdio.h>

/**
 * @brief 统计字符串中每个字符连续出现的次数
 *
 * @param s 输入的字符串
 */
void fun(char s[]) {
    int sum = 0;
    int count = 1;
    int i = 0;
    int arr[30];
    char *p = s;
    while (*p != '\0') {
        char *q = p + 1;
        while (*q != '\0') {
            if (*p == *q)
                count++;
            q++;
        }
        printf("\n");
        arr[i++] = count;
        count = 1;
        sum++;
        p++;
    }

    printf("%s\n", s);

    for (int i = 0; i < sum; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    char ch[] = "AABB%%$$!!oo09912MMM;;1@@,,,!!";
    fun(ch);
    return 0;
}
