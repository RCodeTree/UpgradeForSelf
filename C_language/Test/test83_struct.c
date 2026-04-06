#include <stdio.h>
#include <string.h>

/*
 * @brief 输入3个学生的信息(学号 姓名 成绩)，输出成绩最高的学生的信息
 */
struct Student {
    int id;
    char name[20];
    float score;
};

int main() {
    int id;
    char name[20];
    float score;
    struct Student stus[3];
    for (int i = 0; i < 3; i++) {
        printf("请输入第%d个学生的信息(学号 姓名 成绩):", i + 1);
        scanf("%d %s %f", &id, name, &score);
        struct Student s = {.id = id, .score = score};
        strcpy(s.name, name);
        stus[i] = s;
    }
    float max = 0;
    for (int i = 0; i < 3; i++) {
        if (stus[i].score > max)
            max = stus[i].score;
    }
    for (int i = 0; i < 3; i++) {
        if (stus[i].score == max)
            printf("%d %s %f\n", stus[i].id, stus[i].name, stus[i].score);
    }
    return 0;
}
