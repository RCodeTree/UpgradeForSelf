### 字符串函数

- strlen(str) 计算字符串长度, str 为字符串, 返回值为size_t类型(无符号整数类型), 表示字符串的长度(不包括'\0')
- strcpy(dest, src) 复制字符串(包括'\0'), dest 为目标字符串, src 为源字符串, 复制的是 src 字符串到 dest 字符串的末尾, 并在末尾添加 '\0'
- strcat(str, catStr) 连接字符串, str 为目标字符串, catStr 为源字符串, 连接的是 catStr 字符串到 str 的末尾, 并在末尾添加 '\0'
- strcmp(str1, str2) 比较字符串(返回值为int类型, 相等返回0, 不相等返回非0值, 比较的是字符串的每个字符的ASCII码值), str1 为源字符串, str2 为子字符串, 比较的是 str1 字符串和 str2 字符串的每个字符的 ASCII 码值, 如果相等, 则返回 0, 否则返回非 0 值.
- strstr(str1, str2) 查找子字符串(返回值为char*类型, 找到返回子字符串的地址, 未找到返回NULL), str1 为源字符串, str2 为子字符串, 查找的是 str1 中第一次出现 str2 的位置, 并返回该位置的地址, 如果未找到, 则返回 NULL.

### 以下是对各个函数的自我实现

#### strlen

``` c
#include <stdio.h>
int my_strlen(char* str)
{
    int count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return count;
}
```

#### strcpy

``` c
#include <stdio.h>
void my_strcpy(char* dest, char* src)
{
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // 或者 *dest = *src; ----> 此时 *src 为 '\0'
}
```

#### strcat

``` c
#include <stdio.h>
void my_strcat(char* dest, char* src)
{
    // 先找到 dest 字符串的 '\0'
    while (*dest)
    {
        dest++;
    }
    // 再连接 src 字符串
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // 或者 *dest = *src; ----> 此时 *src 为 '\0'
}
```

#### strcmp

``` c
#include <stdio.h>
int my_strcmp(char* str1, char* str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2; // 不相等时, 返回的是两个字符的ASCII码值的差
}
```
