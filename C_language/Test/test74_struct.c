#include <stdio.h>

struct Student {
    char name[20];
    int id;
    float score;
};

int main() {
    struct Student s1 = {"zhangsan", 1, 94.0f};
    struct Student s2 = {"lisi", 2, 32.2f};
    struct Student s3 = {"wangwu", 3, 41.1f};
    struct Student s4 = {"zhaoliu", 4, 71.3f};
    struct Student s5 = {"qianqi", 5, 98.4f};
    struct Student arr[5] = {s1, s2, s3, s4, s5};

    printf("before sort:\n");
    for (int i = 0; i < 5; i++)
        printf("%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].score);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4 - i; j++)
            if (arr[j].score > arr[j + 1].score) {
                struct Student s = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = s;
            }
    printf("\n");
    printf("after sort:\n");
    for (int i = 0; i < 5; i++)
        printf("%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].score);

    return 0;
}
