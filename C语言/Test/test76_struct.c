#include <stdio.h>
#include <string.h>
/*
 * @brief 结构体的应用
 * 输入3个学生的姓名、学号、成绩，计算平均成绩并输出低于60分的学生的姓名、学号、成绩。
 */
struct Student {
    char name[20];
    int id;
    float score;
};

int main() {
    struct Student stus[20];
    int id;
    char name[20];
    float score;
    for (int i = 0; i < 3; i++) {
        printf("输入第%d个学生的姓名、学号、成绩：", i + 1);
        scanf("%s %d %f", name, &id, &score);
        struct Student s = {.id = id, .score = score};
        strcpy(s.name, name);
        stus[i] = s;
    }
    float avg = 0;
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += stus[i].score;
    }
    avg = sum / 3;
    printf("平均成绩为：%f\n", avg);
    for (int i = 0; i < 3; i++)
        if (stus[i].score < 60)
            printf("%s %d %.3f\n", stus[i].name, stus[i].id, stus[i].score);


    return 0;
}
