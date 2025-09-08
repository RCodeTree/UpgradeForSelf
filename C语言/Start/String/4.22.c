#include <stdio.h>
#include <string.h>
/*
    字符串
    转义字符
    注释
*/
/*
字符串
*/
// int main()
// {
//     // 在C语言中没有字符串类型
//     "abcd";
//     // 在字符数组中，会开辟一个地址空间存放字符或字符串，会在任意的位置开辟'\0'标识符用于标识结束，这样能正确得出字符串长度
//     char arr[] = "efg"; // 以这样的形式定义 ---> 使用字符数组定义字符串，最后一个元素是'\0'，这是C语言一个结束的标识符
//     char arr2[] = {'a', 'b', 'c'};
//     printf("arr=%s\n", arr);
//     printf("arr2=%s\n", arr2);
//     printf("%d\n", strlen(arr));  // 3
//     printf("%d\n", strlen(arr2)); // 6 ---> 由于以这种方式创建字符串数组没有像 arr 那样有一个特定的'\0'结束标识符，当程序运行时，它会在空间中一直执行，直到找到'\0'标识符，才会结束返回
//     printf("arr[]=%s\n", arr);
//     printf("arr[]=%d", arr);
//     /*
//     printf("arr[]=%s\n", arr);这个输出的是字符串内容。在 C 语言中，%s 格式说明符用于输出字符串。这里 arr 是一个字符数组，被初始化为 "efg"。所以输出结果是 arr[]=efg。
//     printf("arr[]=%d", arr);这个输出的是字符数组 arr 的首地址的整数值形式。因为 %d 格式说明符用于输出整数，在这里它会将字符数组 arr 的首地址（一个内存地址值）以十进制整数的形式输出。从运行结果来看，输出的是一个看似随机的整数，如 6422044（这个值取决于程序运行时 arr 被分配的内存地址）。
//     */
// }

/*
转义字符
*/
// 三字母词
// ??) ---> ]
// ??( ---> [
int main()
{
    printf("?????\?");
    printf("\n");
    printf("\"");
    printf("\n");
    printf("\'");
    printf("\n");
    printf("\\");
    printf("\n");
    printf("\a");
    printf("\n");
    printf(" 退格符\b");
    printf("\n");
    printf("进纸符\f");
    printf("\n");
    printf("换行符\n");
    printf("回车\r");
    printf("水平制表符\t水平制表符\t水平制表符");
    printf("垂直制表符\v垂直制表符\v垂直制表符");
    printf("\120"); // \ddd 表示1-3个八进制的数字 这里的 \120 就是一个八进制数
    printf("\x23"); // \xdd 表示2个十六进制数字，如：\x30
    return 0;
}