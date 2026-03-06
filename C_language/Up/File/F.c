#include <ctype.h>
#include <stdio.h>

int main()
{
    FILE* fp = fopen("test.txt", "r");

    // 单个字符读取
    // char ch = fgetc(fp);
    // printf("%c", ch);

    // 单行读取
    // char a[100];
    // char* str = fgets(a, 5, fp); // 读取4个字符，包括'\0'，一共5个字符
    // printf("%s", str);

    // 多行读取
    char a[100];
    int c = 0;
    char* str = fgets(a, sizeof(a), fp);
    while (str != NULL)
    {
        while (*str)
        {
            int flag = 0;
            if (!ispunct(*str) && *str != ' ' && *str != '\n' && flag == 0)
            {
                printf("%c", *str);
                c++;
            }
            else
            {
                flag = 1;
            }
            str++;
        }
        str = fgets(a, sizeof(a), fp);
    }

    printf("%d\n", c);


    return 0;
}
