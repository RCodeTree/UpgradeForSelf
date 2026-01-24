#include <stdio.h>

/*
 * @brief 比较两个字符串是否相同
 *
 * @param s1 第一个字符串
 * @param s2 第二个字符串
 */
void mystrcmp(char *s1, char *s2) {
    char *p = s1, *q = s2;
    int result = 0;
    while (*p && *q) {
        if (*p != *q) {
            result = *p - *q;
            break;
        }
        p++;
        q++;
    }
    /*
    该判断作用：
    ① 当两个字符串相同时，两个指针同时指向字符串的结束符'\0'，result=0 的值不变，正常走完
    ② 当两个字符串不同时，两个指针指向第一个不同的字符，由于 while 的循环条件为 *p && *q，必然有一个指针先指向结束符'\0'，这时循环会提前结束，这时的 result=0 的值不变，此时，这个判断就比较必要了，计算出两个指针指向的最后两个不同字符的 ASCII 码值的差值，作为结果返回
    ③ 当两个字符串不同时，两个指针指向各自第一个不同的字符，然后直接跳出循环，返回 result 的值 ----> 这个属于真正的正常走完
    */
    if (result == 0)
        result = *p - *q;
    if (result)
        printf("两个字符串不同\n");
    else
        printf("两个字符串相同\n");
}

int main() {
    char s1[20], s2[20];
    printf("请输入第一个字符串：");
    scanf("%s", s1);
    printf("请输入第二个字符串：");
    scanf("%s", s2);
    mystrcmp(s1, s2);
    return 0;
}
