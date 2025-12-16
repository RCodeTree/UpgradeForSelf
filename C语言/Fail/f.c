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

    /* 
    为什么要使用二级指针 char **p ？
    - a 是一个 指针数组 。
    - 它的每个元素 a[0] , a[1] ... 都是 char* 类型（即指向字符串首字符的指针）。
    - 在表达式中，数组名 a 会退化为 指向数组首元素的指针 。
    - a 的首元素是 char* 类型。
    - 所以指向首元素的指针就是 char** 类型（指向指针的指针）。
    结论 ：
    为了存储数组名 a （即指向 char* 元素的指针），变量 p 必须定义为二级指针 char **p 。
    

    为什么 printf("%s", *(p--)) 只解引用一次？
    这里确实只解引用一次，这正是关键所在。我们来逐层拆解：
    1. p 是什么？
    - p 是 char** 类型。
    - 它指向数组 a 中的某个元素（比如 a[3] ）。
    - a[3] 本身是一个 char* ，指向字符串 "Java" 。
    
    2. *p （一次解引用）得到了什么？
    - 对二级指针 p 进行一次解引用 *p ，我们拿到了它指向的内容。
    - 它指向的内容就是 a[3] ，即字符串 "Java" 的首地址（ char* 类型）。
    
    3. %s 需要什么参数？
    - printf 的 %s 格式符要求提供一个 字符串的首地址 （即 char* 类型）。
    - 它会自己负责从这个地址开始，一个字符一个字符地打印，直到遇到 \0 。
    
    推导过程 ：
    - p (类型 char** )
    - *p (类型 char* ，指向 "Java")
    - printf("%s", *p) -> 传入了 "Java" 的地址 -> 打印出 "Java"。
    如果解引用两次 **p 会发生什么？

    - **p 得到的是 char 类型（即字符 'J' ）。
    - 如果写 printf("%s", **p) ，那是把字符 'J' 的 ASCII 码值当成了地址传给 %s ，程序会直接崩溃（Segmentation Fault）。
    */
    char *a[] = {"Pascal", "C Language", "dBase", "Java"};
    char **p;
    int j;
    p = a;
    p = p + 3;
    for (j = 3; j >= 0; j--)
        printf("%s,", *(p--));
    printf("\n");

    return 0;
}
