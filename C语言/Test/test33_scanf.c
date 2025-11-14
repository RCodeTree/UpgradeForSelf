#include <stdio.h>
int main()
{
    /* 
    scanf() 格式化输入
    %d 读整数，跳过前导空白（空格、制表符、换行等）。

    %c 读一个字符（包括空白字符，不会跳过空白）。

    %d 读整数，跳过前导空白。

    %c 读一个字符（同样不会跳过空白）。
    */
    int a1, a2;
    char c1, c2;
    scanf("%d%c%d%c", &a1, &c1, &a2, &c2);
    printf("%d%c%d%c\n", a1, c1, a2, c2);
    
    return 0;

}