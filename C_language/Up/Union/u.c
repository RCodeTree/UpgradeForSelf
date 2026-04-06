#include <stdio.h>

/* 
    联合体（union）是一种特殊的结构体，它的所有成员共享同一块内存空间。
    联合体的大小等于其最大成员的大小。
    联合体的每个成员可以是不同的类型，但是只能同时使用其中的一个成员，即多个成员共享同一块内存空间。
*/
union Un
{
    int a;
    char c;
};

int main()
{
    union Un u;
    printf("%ld\n", sizeof(u)); // 4
    printf("%p\n", &u); // 000000000061FE1C
    printf("%p\n", &u.a); // 000000000061FE1C
    printf("%p\n", &u.c); // 000000000061FE1C
    return 0;
}