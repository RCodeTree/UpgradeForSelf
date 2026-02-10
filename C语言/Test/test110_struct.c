#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	char id[100];
	char name[100];
	float score;
};

typedef struct
{
	struct Student* array;
	int len;
	int capacity;
} DynamicArr;

DynamicArr* createArr(int size)
{
	DynamicArr* arr = (DynamicArr*)malloc(sizeof(DynamicArr));
	arr -> array = (struct Student*)malloc(sizeof(struct Student) * size);
	arr -> len = 0;
	arr -> capacity = size;
	return arr;
}

void addStudent(DynamicArr* arr, struct Student* s)
{
	assert(arr != NULL);
	assert(s != NULL);
	if (arr -> len == arr -> capacity)
	{
		arr -> capacity *= 2;
		arr -> array = (struct Student*)realloc(arr -> array,sizeof(struct Student) * arr -> capacity);
	}
	arr -> array[arr -> len++] = *s;
}

void queryStudent(DynamicArr* arr, char* id)
{
	assert(arr != NULL);
	assert(id != NULL);
	for (int i = 0; i < arr -> len; i++)
	{
		if (strcmp(arr -> array[i].id, id) == 0)
		{
			printf("查询学生信息为 => 学号：%s，姓名：%s，成绩：%f\n", arr -> array[i].id, arr -> array[i].name, arr -> array[i].score);
			return;
		}
	}
	printf("该学号不存在！\n");
}

DynamicArr* removeStudent(DynamicArr* arr, char* id)
{
	assert(arr != NULL);
	assert(id != NULL);
	DynamicArr* a = arr;
	for (int i = 0; i < arr -> len; i++)
	{
		if (strcmp(arr -> array[i].id, id) == 0)
		{
			for (int j = i; j < (arr -> len - 1); j++)
				arr -> array[j] =  arr -> array[j + 1];
			arr -> len--;
			arr -> capacity--;
			break;
		}
	}
	return a;
}

DynamicArr* sortStudent(DynamicArr* arr)
{
	assert(arr != NULL);
	DynamicArr* a = arr;
	for (int i = 0; i < (arr -> len - 1); i++)
		for (int j = 0; j < (arr -> len - 1 - i); j++)
			if (arr -> array[j].score < arr -> array[j + 1].score)
			{
				struct Student tmp = arr -> array[j];
				arr -> array[j] = arr -> array[j + 1];
				arr -> array[j + 1] = tmp;
			}
	return a;
}

void printStudent(DynamicArr* arr)
{
	assert(arr != NULL);
	for (int i = 0; i < arr -> len; i++)
		printf("学生信息 => 学号：%s，姓名：%s，成绩：%f\n", arr -> array[i].id, arr -> array[i].name, arr -> array[i].score);
	printf("len: %d, capacity: %d\n", arr -> len, arr -> capacity);
	printf("---------------------------------\n");
}

int main()
{
	// 初始化动态数组
	int size;
	printf("请输入动态数组的初始容量：");
	scanf("%d", &size);
	DynamicArr* arr = createArr(size);

	// 添加学生信息
	struct Student s1 = {"001", "张三", 80.0};
	struct Student s2 = {"002", "李四", 90.0};
	struct Student s3 = {"003", "王五", 70.0};
	addStudent(arr, &s1);
	addStudent(arr, &s2);
	addStudent(arr, &s3);
	printf("添加学生信息后, 未排序：\n");
	printStudent(arr);

	// 排序学生信息
	DynamicArr* arr_sorted = sortStudent(arr);
	printf("排序学生信息后, 按成绩从高到低排序：\n");
	printStudent(arr_sorted);

	// 查询学生信息
	char id[100];
	printf("请输入要查询的学号：");
	scanf("%s", id);
	queryStudent(arr_sorted, id);

	// 删除学生信息
	printf("删除学号为 %s\n", id);
	removeStudent(arr_sorted, id);
	printStudent(arr_sorted);

	free(arr);
	return 0;
}

