#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    // char *a[] = {"Pascal", "C Language", "dBase", "Java"};
    // char **p;
    // int j;
    // p = a;
    // p = p + 3;
    // for (j = 3; j >= 0; j--)
    //     printf("%s,", *(p--));
    // printf("\n");


    /*
    fun:
    void fun(int b[], int n, int k) {
        int i, t;
        for (i = 0; i < k; i++) {
            t = b[0];
            for (int j = 0; j < n - 1; j++)
                b[j] = b[j + 1];
            b[n - 1] = t;
        }
    }
    */

    /*
    // while (*(a++) != '\0');这是一个非常经典的 C 语言“陷阱”。关键在于 后置 ++ 的生效时机 。
    // 第一轮循环：
    // 1. 当前 a = 100 ( 'H' )。
    // 2. 执行 *(a++) ：
    // - 先取值：取到 'H' 。
    // - 副作用生效 ： a 变为 101 。
    // 3. 判断 ： 'H' != '\0' ？ 真 。
    // 4. 继续循环 。 第二轮循环：
    // 1. 当前 a = 101 ( 'i' )。
    // 2. 执行 *(a++) ：
    // - 先取值：取到 'i' 。
    // - 副作用生效 ： a 变为 102 。
    // 3. 判断 ： 'i' != '\0' ？ 真 。
    // 4. 继续循环 。 第三轮循环（关键）：
    // 1. 当前 a = 102 ( '\0' )。
    // 2. 执行 *(a++) ：
    // - 先取值：取到 '\0' 。
    // - 副作用生效 ： a 变为 103 （这就是为什么它指向了 \0 的后面！）。
    // 3. 判断 ： '\0' != '\0' ？ 假 。
    // 4. 退出循环 。
    // ### 结论
    // 当循环条件 失败 （遇到 \0 ）从而退出循环时， a++ 这个动作 已经发生过了 。

    // 所以：

    // - 我们取到了 \0 来做判断。
    // - 但指针 a 已经无情地迈过了 \0 ，指向了它的下一位。
    
    sub:
    void sub(char *a, char b)
    {
        while (*(a++) != '\0');
        while (*(a - 1) < b)
            *(--a) = *(a - 1);
        *(a--) = b;
    }

    main:
    char s[] = "97531", c;
    c = '6';
    sub(s, c);
    s[6] = '\0';
    puts(s);
    */


    /*
    // 将数组循环左移k个元素，结果输出 4 5 6 7 8 1 2 3
    fun:
    void fun(int *a, int n, int k)
    {
        int i, j, t;
        for (i = 0; i < k; i++) {
            t = a[i]; // ①
            for (j = 3 + i; j > i; j--) a[j - 1] = a[j]; // ②
            a[n - 1] = t;
        }
    }

    main:
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8}, i;
    fun(b, 8, 3);
    for (i = 0; i < 8; i++)
        printf("%2d", b[i]);
    printf("\n");
    */

    // 编写一个函数 fun ，它的功能是：
    // 对一个浮点数数组 d 中的 n 个元素进行查找，返回其中的最大（或最小）元素。
    // 最终计算 a数组的最大值 和 b数组的最小值 的 差 。
    /*
    fun:
    float fun(float *d, int n, int flag) {
        float y;
        int i;
        y = d[0];
        for (i = 1; i < n; i++) {
            if (flag * d[i] > flag * y) y = d[i];
        }
        return y;
    }


    main:
    float a[6] = {3, 5, 9, 4, 2.5f, 1}, b[5] = {3, -2, 6, 9, 1};
    printf("%.2f\n", fun(a, 6, 1) - fun(b, 5, -1));
    */

    /*
    // 查找数组中最大、最小值
    find:
    int max, min; // 全局变量

    void find(int *p, int n)
    {
        int *q;
        max = min = *p;
        for (q = p; q - p < n; q++) {
            if (*q > max)
                max = *q;
            else if (*q < min)
                min = *q;
        }
    }

    main:
    int i, num[10];
    printf("Input 10 numbers:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    find(num, 10);
    printf("max=%d,min=%d\n", max, min);
    */

    // 程序功能：输入一个字符串，然后按照由小到大的顺序进行排序，并删除重复的字符
    // char str[100], *p, *q, *r, t;
    // printf("please input a string: ");
    // gets(str);
    // for (p = str; *p != '\0'; p++) {
    //     for (q = p, r = p; *q != '\0'; q++) if (*q < *r) r = q;
    //     if (r != p) {
    //         t = *p;
    //         *p = *r;
    //         *r = t;
    //     }
    // }

    /* 
    假设 str 为 "aaabbc" 。
    1. 第一轮外层循环
    - 初始状态 ： p 指向 str[0] ('a')。
    - 内层循环 for (q = p; *p == *q; q++); ：
    - q 从 p 开始往后找。
    - q 指向 str[0] ('a') -> 相等， q++
    - q 指向 str[1] ('a') -> 相等， q++
    - q 指向 str[2] ('a') -> 相等， q++
    - q 指向 str[3] ('b') -> 不相等 ，循环停止。
    - 结果 ：此时 p 指向第一个 'a'， q 指向第一个非 'a' 的字符（即 'b'）。
    - 执行 strcpy(p + 1, q) ：
    - 把 q 开始的字符串（ "bbc\0" ）拷贝到 p + 1 的位置。
    - 内存变化 ：
        - 原： a a a b b c \0
        - 变： a b b c \0 b c \0 (后面的不管了，字符串以第一个 \0 结束)
        - 现字符串： "abbc"
    - 外层循环 p++ ： p 指向下一个字符（现在是 str[1] ，即 'b'）。 2. 第二轮外层循环
    - 状态 ： p 指向 str[1] ('b')。字符串是 "abbc" 。
    - 内层循环 ：
    - q 从 p 开始。
    - q 指向 'b' -> 相等， q++
    - q 指向下一个 'b' -> 相等， q++
    - q 指向 'c' -> 不相等，停。
    - 执行 strcpy(p + 1, q) ：
    - 把 q 开始的 "c\0" 拷贝到 p + 1 。
    - 内存变化 ：
        - 原： a b b c \0
        - 变： a b c \0
        - 现字符串： "abc"
    - 外层循环 p++ ： p 指向 str[2] ('c')。 3. 第三轮外层循环
    - 状态 ： p 指向 str[2] ('c')。
    - 内层循环 ：
    - q 往后找，发现后面是 \0 ，不相等，停（ q 指向 \0 ）。
    - 执行 strcpy(p + 1, q) ：
    - 把 \0 拷贝到 p + 1 。
    - 字符串还是 "abc" ，没变。
    */
    // for (p = str; *p != '\0'; p++) {
    //     for (q = p; *p == *q; q++);
    //     strcpy(p + 1, q);
    // }
    //
    // printf("Result: %s\n", str);

    // printf("%d\n", (int) strlen("ab\xcd\t\\\023")); // 6

    // int m[3][4] = {1, 4, 3, 2, 6, 5, 9, 3, 4, 7, 1, -9};
    // printf("%d\n", *(*(m + 2) + 2) + 1); // 2


    // f:
    // int b; // 全局变量
    // void f(int a) {
    //     int b = 2;
    //     printf("b=%d,", b);
    //     b = 3;
    // }
    // main:
    // int a = 100;
    // f(a);
    // printf("%d,%d\n", a, b);

    // int a, b;
    // scanf("%d %d", &a, &b);
    // printf("%d\n", a > b ? a : b);

    return 0;
}
