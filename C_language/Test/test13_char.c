/* 
多组输入：每一行一个字符
判断该字符是否为字母
*/
#include <stdio.h>
int main() {

    /* 
    可以使用库函数 isalpha() 来判断一个字符是否为字母
    该函数在 <ctype.h> 头文件中定义，返回值为非零值表示是字母，零值表示不是字母

    char c;

    while(scanf(" %c", &c) != EOF) // 注意：%c前有一个空格，用于清除输入缓冲区中的换行符，跳过空白字符，只读取一个字符
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            printf(" %c 为字母\n", c);
        }
        else
        {
        printf(" %c 不为字母\n", c);
        }
    }
    */
    
    char c;

    while(scanf("%c", &c) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            printf(" %c 为字母\n", c);
        }
        else
        {
        printf(" %c 不为字母\n", c);
        }

        getchar(); // 用于清除输入缓冲区中的换行符
    }

    return 0;
}