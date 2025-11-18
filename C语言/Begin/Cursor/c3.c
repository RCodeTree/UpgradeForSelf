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

    printf("%p\n", p); // 0x7ffdd376b364
    printf("%p\n", *pp); // 0x7ffdd376b364
    printf("%d\n", **pp); // 10

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
        // printf("%d ", *parr[i]); // 10 20 30f
        // printf("%d ", **(pparr + i)); // 10 20 30
        printf("%d ", *pparr[i]); // 10 20 30
    }
    printf("\n");

    return 0;
} 
