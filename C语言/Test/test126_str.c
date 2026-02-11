#include <stdio.h>

/**
 * 从字符串中去掉所有字符'a'
 * @param a 输入字符串
 * @param p 指向字符串的指针
 * @param i 记录有效字符的索引
 * @return 0 成功
 */ 
// %s 格式符会自动跳过前导空白字符，并在遇到下一个空白字符（空格、换行等）时停止读取
int main() {
    char a[100];
    scanf("%s", a);
    printf("%s\n", a);
    char* p = a;
    int i = 0;
    while (*p)
    {
        if (*p != 'a')
        {
			a[i++] = *p;
        }
		p++;
    }
    a[i] = '\0';
    printf("去掉后：%s\n", a);
    return 0;
}
