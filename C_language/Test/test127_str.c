#include <stdio.h>
/**
 * 将字符串中的所有大写字母转换为小写字母
 * @param a 输入字符串
 * @return 0 成功
 */ 
int main()
{
    char a[100] = {0};
    scanf("%s", a);
    char* p = a;
    while (*p)
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p + 32;
        }
        p++;
    }
    printf("转换后：%s\n", a);
    return 0;
}