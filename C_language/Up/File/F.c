#include <ctype.h>
#include <stdio.h>

int main()
{
    FILE* fp = fopen("test.txt", "rb+");

    // 单个字符读取、写入
    /*
    fputc('c', fp);
    char ch = fgetc(fp);
    printf("%c", ch);*/

    // 单行读取、写入
    /*char a[100];
    fputs("hello", fp);
    char* str = fgets(a, 5, fp); // 读取4个字符，包括'\0'，一共5个字符
    printf("%s", str);*/
    // 多行读取
    /*char a[100];
    int c = 0;
    char* str = fgets(a, sizeof(a), fp);
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
        str = fgets(a, sizeof(a), fp);
    }
    printf("%d\n", c);*/

    // 格式化读取、写入
    /*typedef struct
    {
        int age;
        char gender[3];
    } Person;
    Person p = {18, "男"};
    fprintf(fp, "%d %s", p.age, p.gender);
    fscanf(fp, "%d %s", &p.age, p.gender);
    printf("%d %s", p.age, p.gender);*/

    // 二进制读取、写入
    /*typedef struct
    {
        int age;
        char gender[3];
    } Person;
    // Person p = {18, "男"};
    // fwrite(&p, sizeof(Person), 1, fp);
    Person p2 = {0};
    fread(&p2, sizeof(Person), 1, fp);
    printf("%d %s", p2.age, p2.gender);*/


    // 文件随机读取、写入
    printf("当前位置：%ld\n", ftell(fp)); // ftell(fp)返回当前位置 0
    fseek(fp, 2, SEEK_SET); // 从文件开头偏移2个字节 SEEK_SET表示文件开头
    printf("当前位置：%ld\n", ftell(fp)); // ftell(fp)返回当前位置 2
    char ch = fgetc(fp);
    printf("字符: %c\n", ch);
    printf("当前位置：%ld\n", ftell(fp)); // ftell(fp)返回当前位置 3(在偏移读取后，文件指针指向下一个位置)
    // fseek(fp, 1, SEEK_CUR); // 从当前位置偏移1个字节 SEEK_CUR表示当前位置(即，在偏移读取后，文件指针指向下一个位置)
    // char ch2 = fgetc(fp);
    // printf("%c", ch2);
    // char ch3 = fgetc(fp);
    // printf("%c", ch3);
    rewind(fp); // 把文件指针重新指向文件开头
    printf("当前位置：%ld\n", ftell(fp)); // ftell(fp)返回当前位置 0

    return 0;
}
