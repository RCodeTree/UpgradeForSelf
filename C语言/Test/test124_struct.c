#include <stdio.h>

struct Student {
    char stu_num[7];
    char name[9];
    float score[3];
    float avr;
} stus[3];

int main() {
    for (int i = 0; i < 3; i++) {
        float avg = 0.0f;
        printf("输入第%d个学生的学号、姓名: ", i + 1);
        scanf("%s %s", stus[i].stu_num, stus[i].name);
        for (int j = 0; j < 3; j++) {
            printf("输入第%d个学生的第%d门成绩: ", i + 1, j + 1);
            scanf("%f", &stus[i].score[j]);
            avg += stus[i].score[j];
        }
        stus[i].avr = avg / 3;
    }
    printf("第3号学生的信息: \n");
    printf("%s %s\n", stus[2].stu_num, stus[2].name);
    for (int j = 0; j < 3; j++) {
        printf("%f\n", stus[2].score[j]);
    }
    return 0;
}
