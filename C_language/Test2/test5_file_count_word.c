#include <stdio.h>
#include <ctype.h>

/**
 * 统计文件test.txt里的单词数
 * @return 0
 */

/*
 注意：在 Linux 下，文本模式与二进制模式无区别，fgets 会原样读入 "\r\n"。 ---> 会比 Windows 下多读取 2 个字符
 而在 Windows 下，fgets 会将 "\r\n" 转换为 "\n"。
 */
int main()
{
    FILE* fp = fopen("test.txt", "r");
    char buf[200];
    int c = 0;
    char* str = fgets(buf, sizeof(buf), fp);
    while (str != NULL)
    {
        int flag = 0;
        while (*str)
        {
            if (*str != ' ' && *str != '\n' && !ispunct(*str))
            {
                if (flag == 0)
                {
                    c++;
                    flag = 1;
                }
            }
            else
            {
                flag = 0;
            }
            str++;
        }
        str = fgets(buf, sizeof(buf), fp);
    }
    printf("%d\n", c);
    return 0;
}
