### 字符串函数

- strlen 计算字符串长度
- strcpy 复制字符串(包括'\0')
- strcat 连接字符串
- strcmp 比较字符串(返回值为int类型, 相等返回0, 不相等返回非0值, 比较的是字符串的每个字符的ASCII码值)

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
