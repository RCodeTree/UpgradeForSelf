/* 
二级指针
二级指针变量是用来存放一级指针变量的地址的
数组中的 [] 相当于 解引用操作符 *
*/
/* 
#include <stdio.h>
int main()
{
    int a = 10;

    int *p = &a;

    int **pp = &p;


    ### 二级指针的解引用（Dereferencing）
    解引用操作符 * 用于访问指针所指向的值。对于二级指针，你需要使用两次 * 来访问最终的值。
    - pp ：存储的是 p 的地址。
    - *pp ：解引用 pp ，得到 pp 所指向的值，也就是 p 的值（ a 的地址）。所以 *pp 等同于 p 。
    - **pp ：解引用 *pp ，得到 *pp 所指向的值，也就是 a 的值（ 10 ）。所以 **pp 等同于 *p ，也等同于 a 。

    printf("%p\n", p); // 0x7ffdd376b364 --- a的地址
    printf("%p\n", *pp); // 0x7ffdd376b364 --- a的地址

    printf("%p\n", pp); // 0x7ffdd376b368 --- p的地址
    printf("%d\n", **pp); // 10
    printf("%d\n", *p); // 10

    return 0;
}
*/



#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    int* parr[3] = {&a, &b, &c}; // 指针数组，每个元素都是一个指针，指向一个整数

    int** pparr = parr; // 二级指针，用来存放一级指针变量的地址

    for(int i = 0; i < 3; i++)
    {
        // printf("%p ", parr[i]); // 0x7ffd69d12578 0x7ffd69d1257c 0x7ffd69d12580 ---> 指针数组里的地址
        // printf("%p ", *(pparr + i)); // 0x7ffd69d12578 0x7ffd69d1257c 0x7ffd69d12580 ---> 指针数组里的地址
        // printf("%d ", *parr[i]); // 10 20 30
        // printf("%d ", **(pparr + i)); // 10 20 30
        // printf("%d ", *pparr[i]); // 10 20 30
    }
    printf("\n");

    return 0;
} 
