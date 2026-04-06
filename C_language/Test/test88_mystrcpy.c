#include <stdio.h>

/*
 * @brief 复制字符串p2到字符串p1
 */
int Mystery(char *p1, char *p2) {
    int count = 0;
    while (*p2) {
        *p1 = *p2;
        p1++;
        p2++;
        count++;
    }
    *p1 = '\0';

    return count;
}

/*
 * @brief 主函数，测试Mystery函数
 */
int main() {
    char str1[100];
    char str2[100];
    printf("输入第一个字符串：");
    scanf("%s", str1);
    getchar();
    printf("输入第二个字符串：");
    scanf("%s", str2);
    printf("%d\n", Mystery(str1, str2));
    printf("%s\n", str1);
    return 0;
}
