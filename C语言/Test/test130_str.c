#include  <stdio.h>
#include <string.h>

/**
 * 连接两个字符串，最多连接count个字符
 * @return 0
 */
int main() {
    char a[100], b[100];
    printf("输入a字符串：");
    scanf("%s", a);
    printf("输入b字符串：");
    scanf("%s", b);
    int count = 5;
    int len_b = strlen(b);
    int tmp = strlen(a);
    if (len_b <= count) {
        for (int i = 0; i < len_b; i++)
            a[tmp++] = b[i];
    } else {
        for (int i = 0; i < count; i++)
            a[tmp++] = b[i];
    }
    a[tmp] = '\0';
    printf("连接后：%s\n", a);


    return 0;
}
