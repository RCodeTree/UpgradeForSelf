/* 
结构体
结构体是一种用户自定义的数据类型，用来存储不同类型的数据
*/
#include <stdio.h>
/*
struct Student
{
    char name[20];
    int age;
    float score;
} stu1, stu2; // stu1, stu2 是结构体变量，定义结构体的同时创建变量，但是 stu1, stu2 是全局变量
*/

// 定义结构体
struct Student
{
    char name[20];
    int age;
    float score;
};

// 定义打印结构体的函数
void printStudent1(struct Student stu)
{
    printf("%s %d %.2f\n", stu.name, stu.age, stu.score);
}

void printStudent2(struct Student* stu)
{
    printf("%s %d %.2f\n", stu->name, stu->age, stu->score);
}

void printStudent3(struct Student* stu)
{
    printf("%s %d %.2f\n", (*stu).name, (*stu).age, (*stu).score);
}

int main()
{
    // 初始化结构体变量
    struct Student stu1 = { "李四", 19, 80.0f }; // 在初始化的时候，也可以不完整初始化，但是必须按照顺序初始化，不能跳过某个成员初始化(不初始化的成员默认值为0)
    printf("%s %d %.2f\n", stu1.name, stu1.age, stu1.score);
    
    // 调用打印结构体的函数
    printStudent1(stu1);
    printStudent2(&stu1);
    printStudent3(&stu1);
}