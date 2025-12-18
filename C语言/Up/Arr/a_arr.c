#include <stdio.h>
#include <string.h>

int main() {
    /* 
    与字符串初始化的区别：
    - char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f'}; 的大小是 6 ，因为它不包含隐式的结束符 \0 。
    - char arr[] = "abcdef"; 的大小是 7 ，因为它自动包含了 \0 。

    
    */

    /*
    strlen 和 sizeof 的区别：
    1. strlen 是求字符串长度的，关注的是字符串中的 \0，计算的是 \0 之前出现的字符的个数。
    2. strlen 是库函数，只针对字符串。
    3. sizeof 只关注占用内存空间的大小，不在乎内存中放的是什么。
    4. sizeof 是操作符。
    */

    int a[] = {1, 2, 3, 4};

    printf("%d\n", sizeof(a)); // 16 ----> 当存放的是数组名时，sizeof()计算的是数组占用的内存空间大小
    printf("%d\n", sizeof(a + 0)); // 8 或者 4 ----> 当存放的不单独是数组名时，a+0表示数组首元素的地址，所以sizeof(a+0)的结果是8 或者 4
    printf("%d\n", sizeof(*a)); // 4 ----> *a 对首元素地址的解引用，表示数组首元素，所以sizeof(*a)的结果是4
    printf("%d\n", sizeof(a + 1)); // 8 或者 4 ----> a+1表示数组第二个元素的地址，所以sizeof(a+1)的结果是8 或者 4
    printf("%d\n", sizeof(a[1])); // 4 ----> a[1]表示数组第二个元素，所以sizeof(a[1])的结果是4
    printf("%d\n", sizeof(&a)); // 8 ----> &a表示数组的地址，本质上也是地址(指针)，所以sizeof(&a)的结果是8
    printf("%d\n", sizeof(*&a)); // 16 ----> *&a 对数组地址的解引用，表示数组本身，所以sizeof(*&a)的结果是16
    printf("%d\n", sizeof(&a + 1)); // 8 或者 4 ----> &a+1跳过一整个数组的大小，其实本质上还是一个地址(指针)，所以sizeof(&a+1)的结果是8 或者 4
    printf("%d\n", sizeof(&a[0])); // 8 或者 4 ----> &a[0]表示数组第一个元素的地址(指针)，所以sizeof(&a[0])的结果是8 或者 4
    printf("%d\n", sizeof(&a[0] + 1)); // 8 或者 4 ----> &a[0]+1表示数组第二个元素的地址(指针)，所以sizeof(&a[0]+1)的结果是8 或者 4

    printf("------------------------------------\n");

    char b[] = {'a', 'b', 'c', 'd', 'e', 'f'}; // 该种显示声明的，后面是没有 '\0' 结束符的
    printf("%d\n", sizeof(b)); // 6 ----> sizeof计算的是数组分配的内存大小，这里明确是6个字符，所以是6。不会因为没有'\0'而变成随机值！
    printf("%d\n", sizeof(b + 0)); // 8 或者 4 ----> 当存放的不单独是数组名时，b+0表示数组首元素的地址，所以sizeof(b+0)的结果是8 或者 4
    printf("%d\n", sizeof(*b)); // 1
    printf("%d\n", sizeof(b[1])); // 1
    printf("%d\n", sizeof(&b)); // 8 或者 4
    printf("%d\n", sizeof(&b + 1)); // 8 或者 4
    printf("%d\n", sizeof(&b[0] + 1)); // 8 或者 4

    printf("------------------------------------\n");

    char arr[] = "abcdef";
    printf("%d\n", sizeof(arr)); // 7 ----> arr单独放在sizeof内部，计算的是整个数组的大小，"abcdef"包含6个字符加上1个\0结束符，共7个字节
    printf("%d\n", sizeof(arr + 0)); // 8 或者 4 ----> arr + 0 是数组首元素的地址，本质是指针，所以结果是8(64位)或者4(32位)
    printf("%d\n", sizeof(*arr)); // 1 ----> *arr 是对数组首元素的解引用，即 arr[0] ('a')，类型是 char，大小为1字节
    printf("%d\n", sizeof(arr[1])); // 1 ----> arr[1] 是数组的第二个元素 ('b')，类型是 char，大小为1字节
    printf("%d\n", sizeof(&arr)); // 8 或者 4 ----> &arr 是整个数组的地址，本质是指针，所以结果是8(64位)或者4(32位)
    printf("%d\n", sizeof(&arr + 1)); // 8 或者 4 ----> &arr + 1 是跳过整个数组后的地址，本质仍然是指针，所以结果是8(64位)或者4(32位)
    printf("%d\n", sizeof(&arr[0] + 1)); // 8 或者 4 ----> &arr[0] + 1 是数组第二个元素的地址，本质是指针，所以结果是8(64位)或者4(32位)

    printf("------------------------------------\n");

    /* strlen 的陷阱：针对没有 \0 结束符的字符数组 */
    char c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%d\n", strlen(c)); // 随机值 ----> c是数组首地址，strlen从这里开始找\0，因为数组中没有\0，所以会越界访问直到找到\0为止
    printf("%d\n", strlen(c + 0)); // 随机值 ----> c+0 等同于 c，也是首元素地址，结果同上
    // printf("%d\n", strlen(*c)); // error ----> *c 是字符 'a' (ASCII 97)，strlen 把 97 当作内存地址去访问，会导致非法访问 (Segmentation Fault)
    // printf("%d\n", strlen(c[1])); // error ----> c[1] 是字符 'b' (ASCII 98)，同上，会导致非法访问
    // printf("%d\n", strlen(&c)); // 随机值 ----> &c 是数组的地址，值与首元素地址相同，所以 strlen 依然能正常读取（虽然会有类型警告），结果同上
    // printf("%d\n", strlen(&c + 1)); // 随机值 - 6 (或者全新的随机值) ----> &c+1 跳过了整个数组(6字节)，从数组后面开始找\0，所以结果是随机的
    printf("%d\n", strlen(&c[0] + 1)); // 随机值 - 1 ----> 从数组第二个元素开始找\0，比从首元素开始找少 1

    printf("------------------------------------\n");

    /* strlen 的正常情况：针对有 \0 结束符的字符数组 */
    char d[] = "abcdef";
    printf("%d\n", strlen(d)); // 6 ----> 正常情况，strlen 计算到 \0 为止，不包含 \0，所以长度是 6
    printf("%d\n", strlen(d + 0)); // 6 ----> 同上，d+0 是首元素地址
    // printf("%d\n", strlen(*d)); // error ----> 同上，*d 是字符 'a'，不是地址
    // printf("%d\n", strlen(d[1])); // error ----> 同上，d[1] 是字符 'b'，不是地址
    // printf("%d\n", strlen(&d)); // 6 ----> &d 是数组地址，值等于首元素地址，虽然类型不匹配但能工作
    // printf("%d\n", strlen(&d + 1)); // 随机值 ----> &d+1 跳过了整个数组(包含\0)，指向了未知的内存区域
    printf("%d\n", strlen(&d[0] + 1)); // 5 ----> 从第二个字符 'b' 开始计算，"bcdef" 长度为 5

    printf("------------------------------------\n");

    /* 指针变量：sizeof 和 strlen 的区别 */
    char *p = "abcdef";

    // sizeof 计算指针变量或其指向类型的大小
    printf("%d\n", sizeof(p)); // 8 或者 4 ----> p 是一个指针变量，计算的是指针变量本身的大小
    printf("%d\n", sizeof(p + 1)); // 8 或者 4 ----> p+1 是指向 'b' 的指针，依然是指针
    printf("%d\n", sizeof(*p)); // 1 ----> *p 是 'a'，是 char 类型，大小为 1
    printf("%d\n", sizeof(p[0])); // 1 ----> p[0] 等价于 *p，是 'a'，大小为 1
    printf("%d\n", sizeof(&p)); // 8 或者 4 ----> &p 是指针变量 p 的地址（二级指针），依然是指针
    printf("%d\n", sizeof(&p + 1)); // 8 或者 4 ----> &p+1 是跳过 p 变量后的地址，依然是指针
    printf("%d\n", sizeof(&p[0] + 1)); // 8 或者 4 ----> &p[0]+1 指向 'b'，依然是指针

    printf("------------------------------------\n");

    // strlen 计算字符串长度
    printf("%d\n", strlen(p)); // 6 ----> p 指向 "abcdef"，strlen 计算到 \0 为止
    printf("%d\n", strlen(p + 1)); // 5 ----> p+1 指向 "bcdef"，长度为 5
    // printf("%d\n", strlen(*p)); // error ----> *p 是 'a' (97)，strlen 把 97 当地址，非法访问
    // printf("%d\n", strlen(p[0])); // error ----> 同上
    // printf("%d\n", strlen(&p)); // 随机值 ----> &p 是指针 p 的地址，strlen 从 p 的地址开始找 \0，结果随机
    // printf("%d\n", strlen(&p + 1)); // 随机值 ----> &p+1 是跳过 p 后的地址，结果随机
    printf("%d\n", strlen(&p[0] + 1)); // 5 ----> &p[0]+1 等价于 p+1，指向 "bcdef"，长度为 5

    printf("------------------------------------\n");


    printf("------------------------------------\n");

    /* 二维数组 sizeof */
    int aspect[3][4] = {0};

    printf("%d\n", sizeof(aspect)); // 48 ----> 3行4列的int数组，总大小 3*4*4 = 48 字节
    printf("%d\n", sizeof(aspect[0][0])); // 4 ----> 第一行第一列的元素，int类型，大小为 4
    printf("%d\n", sizeof(aspect[0])); // 16 ----> aspect[0] 表示第一行数组名，sizeof(数组名)计算整个数组大小，4*4 = 16
    printf("%d\n", sizeof(aspect[0] + 1));
    // 8 或者 4 ----> aspect[0] 作为数组名参与运算退化为首元素地址(&aspect[0][0])，+1 指向 &aspect[0][1]，是指针
    printf("%d\n", sizeof(*(aspect[0] + 1))); // 4 ----> 解引用得到 aspect[0][1] 元素，int类型，大小为 4
    printf("%d\n", sizeof(aspect + 1));
    // 8 或者 4 ----> aspect 是二维数组名，参与运算退化为首行地址(&aspect[0])，+1 指向第二行(&aspect[1])，是指针(数组指针)
    printf("%d\n", sizeof(*(aspect + 1))); // 16 ----> 解引用得到第二行数组 aspect[1]，sizeof计算整个第二行大小，16
    printf("%d\n", sizeof(&aspect[0] + 1)); // 8 或者 4 ----> &aspect[0] 是第一行地址，+1 指向第二行地址，是指针
    printf("%d\n", sizeof(*(&aspect[0] + 1))); // 16 ----> 解引用得到第二行数组，大小 16
    printf("%d\n", sizeof(*aspect)); // 16 ----> aspect 是首行地址，解引用得到第一行数组，大小 16
    printf("%d\n", sizeof(aspect[3])); // 16 ----> 虽然越界(只有0,1,2行)，但 sizeof 只推断类型。aspect[3] 类型是 int[4]，大小 16。不会真正访问内存。

    return 0;
}
