#include <stdio.h>
#include <stdlib.h>


int main() {
    // int m;
    // for (m = 1; m <= 50; m++) {
    //     if (m % 12 != 0)
    //         continue;
    //     printf("%4d", m); // 空格空格12空格空格24空格空格36空格空格48
    // }
    // printf("\n");

    // int *a, *b, *c;
    // a = (int *) malloc(sizeof(int));
    // b = c = a;
    // *a = 3;
    // *b = 4;
    // *c = 5;
    // printf("%d %d %d\n", *a, *b, *c); // 5 5 5

    /*
    fun:
    void fun(int a[]) {
        a[2] = a[0] + a[1];
    }

    main:
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun(&a[2]);
    printf("%d\n", a[4]);
    */


    /*
    fun:
    void fun(int b[]) {
        int k;
        for (k = 2; k < 6; k++)
            b[k] = b[k] * 2;
    }

    main:
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    fun(a);
    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);
    printf("\n");
    */

    /*
    fun:
    void fun(char *p, char t) {
        while (*p) {
            if (*p == t)
                *p = t - 'a' + 'A';
            p++;
        }
    }

    main:
    char s[20] = "abcdab", c = 'a';
    fun(s, c);
    printf("%s\n", s);
    */

    /*
    - 代码分析 ：

    - p 是一个包含3个指向 int 类型指针的数组 ( *p[3] )
    - 在循环中， p[i] = &a[2*i+1] 将 p 的每个元素设置为指向数组 a 中特定元素的地址
    - 等价关系 ：
    
    - p[i][0] 表示先获取 p[i] 指向的内存位置，然后访问该位置的第0个元素
    - *p[i] 表示对 p[i] 指向的内存位置进行解引用操作
    - 在C语言中，数组访问语法 array[index] 本质上等价于 *(array + index)
    - 因此 p[i][0] 等同于 *(p[i] + 0) ，而 *(p[i] + 0) 等同于 *p[i]
    */
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *p[3], i;
    // for (i = 0; i < 3; i++) {
    //     p[i] = &a[ 2 * i + 1];
    //     printf("%d ", p[i][0]);
    //     // printf("%d ", *p[i]);
    // }


    // int a[10], *p, *p1;
    // for (p = a; p - a < 10; p++)
    //     scanf("%d", p);
    //
    //
    // for (p = a, p1 = a; p - a < 10; p++)
    //     if (*p > *p1)
    //         p1 = p;
    // printf("max=%d\n", *p1);
    // printf("max=%d\n", a[p1 - a]); // 通过指针运算求数组索引

    /*
    sort:
    // 对数组的数据从大到小进行排序
    void sort(int a[], int n) {
        int i, j, t;
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
                if (a[i] < a[j]) {  // 修改为降序比较条件
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
    }

    main:
    int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort(&aa[3], 5);
    for (int i = 0; i < 10; i++)
        printf("%d,", aa[i]);
    printf("\n");
    */


    return 0;
}
