#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* s = (char*)malloc(100);
    printf("请输入一个字符串：");
    gets(s);
    int c = 0;
    int flag = 1;
    while (*s)
    {
        if (*s != ' ' && flag == 1)
        {
            c++;
            flag = 0;
        }
        if (*s == ' ')
        {
            flag = 1;
        }
        s++;
    }

    printf("单词数为：%d\n", c);

    return 0;
}
