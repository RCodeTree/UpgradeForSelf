# 类型的意义：
## 1. 使用这个类型开辟内存空间的大小（大小决定了使用范围）。
## 2. 如何看待内存空间的视角。

# 字节序与存储：
## 假如有一个地址：0x 11 22 33 44 (二进制的每四位进制数表示一位十六进制数)
 ``` bash
 大端（Big-Endian）存储：把一个数据的高位字节存放在低地址处，把低位字节存放在高地址处 ----> 示例（从低地址到高地址）：`11 22 33 44`
 
 小端（Little-Endian）存储：把一个数据的低位字节存放在低地址处，把高位字节存放在高地址处 ----> 示例（从低地址到高地址）：`44 33 22 11`
```

# 整型在内存中的存储：
## 整型在内存中存储的是补码。

``` c
#include <stdio.h>
int main()
{
    char c = -128;
    printf("%d\n", c); // -128
    printf("%u\n", c); // 4294967168
    return 0;
}
```

``` c
#include <stdio.h>
int main()
{
    char c = 128;
    printf("%d\n", c); // 4294967168
    printf("%u\n", c); // -128
    return 0;
}
```

``` c
/* 
陷入死循环
*/
#include <stdio.h>
#include <windows.h>
int main()
{
    unsigned int i;
    for(i = 9; i >= 0; i--)
    {
        printf("%u\n", i); // 打印无符号整数
        Sleep(1000); // 暂停 1 秒
    }
    return 0;
}
```

``` c
/* 
'\0' 在ASCII码中是0，所以当数组中出现0时，strlen 函数就会认为字符串结束
strlen 函数的作用是计算字符串的长度，不包括字符串结束符 '\0'
由于 char 类型是有符号的，取值范围是 -128 ~ 127
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[1000];

    /* 
    arr[0] = -1;
    arr[1] = -2;
    arr[2] = -3;
    ......
    当数组存到的值为 -128 时，下一个数将会是 127....1，0
    */
    for(int i = 0; i < 1000; i++)
    {
        arr[i] = -1 - i;
    }

    printf("%d\n", strlen(arr)); // 255



    return 0;
}
```

``` c
/*
    无符号字符类型 unsigned char 取值范围是 0 ~ 255
    有符号字符类型 char 取值范围是 -128 ~ 127
    因此，下方的程序陷入死循环
 */
#include <stdio.h>
int main()
{
    unsigned char i;

    for(i = 0; i <= 255; i++)
    {
        printf("hello world\n");
    }
    return 0;
}
```

``` c
/* 
strlen 函数的作用是计算字符串的长度，不包括字符串结束符 '\0'
其返回值类型是 size_t，是一个无符号整数类型(unsigned int)
unsigned int 取值范围是 0 ~ 255
因此，下方的程序会打印 "<"
*/
#include <stdio.h>
#include <string.h>
int main()
{
    if (strlen("abc") - strlen("abcdef") > 0)
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }

    return 0;
}
```

