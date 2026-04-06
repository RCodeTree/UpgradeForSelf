#include <stdio.h>
struct Stu{
    char name[20];
    int age;
};

void set_stu(struct Stu* stu)
{
    /* 
    strcpy() 函数：用于将一个字符串复制到另一个字符串
    函数原型：char* strcpy(char* dest, const char* src)
    dest：目标字符串，用于存储复制后的字符串
    src：源字符串，要被复制的字符串
    返回值：指向目标字符串的指针
    */

    /* 
    // 使用 * 解引用操作符是对指针进行解引用，获取指针指向的内存中的值
    strcpy((*stu).name, "张三");
    (*stu).age = 18; 
    */

    // 使用 -> 结构成员访问操作符是对指针进行解引用，获取指针指向的内存中的值，这种方式效率更高
    strcpy(stu->name, "张三");
    stu->age = 18;
}

void printStu(struct Stu* stu)
{
    printf("姓名：%s\n", stu->name);
    printf("年龄：%d\n", stu->age);
}



int main()
{
   /* 
   下标、函数调用、结构成员访问操作符：
   [] 下标操作符
   () 函数调用操作符
   .  结构成员访问操作符
   -> 结构成员访问操作符(指针)
   */

   // [] 下标操作符：用于访问数组元素
   // arr[5] ----> *(arr + 5) ----> *(5 + arr) ----> 6
   // 可以用 *(arr + 5) 来理解 arr[5]，就是跳过 5 个元素，到达第 6 个元素
   // *(arr + 5) 就是解引用操作符，用于访问指针指向的内存中的值，就是第 6 个元素的值
   int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   printf("%d\n", a[5]); // 输出结果为 6
   printf("%d\n", *(a + 5)); // 输出结果为 6
   printf("%d\n", 5[a]); // 输出结果为 6

   printf("-----------------\n");

   // . -> 结构成员访问操作符：用于访问结构体变量的成员
   struct Stu stu = { 0 };
   
   set_stu(&stu);

   printStu(&stu);

   return 0;
}