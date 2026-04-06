#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[10];
    int age;
} Stu;

int cmp(const void* a, const void* b);

int main()
{
    Stu ss[5] = {
        {1, "张三", 14},
        {2, "李四", 14},
        {3, "王五", 22},
        {4, "赵六", 20},
        {5, "钱七", 21}
    };
    for (int i = 0; i < 5; i++) printf("%d %s %d\n", ss[i].id, ss[i].name, ss[i].age);
    printf("\n");

    qsort(ss, 5, sizeof(Stu), cmp);

    for (int i = 0; i < 5; i++) printf("%d %s %d\n", ss[i].id, ss[i].name, ss[i].age);
    return 0;
}


int cmp(const void* a, const void* b)
{
    if (((Stu*)a)->age == ((Stu*)b)->age)
    {
        return ((Stu*)b)->id - ((Stu*)a)->id;
    }
    return ((Stu*)a)->age - ((Stu*)b)->age;
}
