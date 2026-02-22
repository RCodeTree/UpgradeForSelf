#include <stdio.h>
#include <stdlib.h>

struct DynamicArr
{
	int* array;
	int len;
	int capacity;
};

struct DynamicArr* createArr(int size)
{
	struct DynamicArr* arr = (struct DynamicArr*)malloc(sizeof(struct DynamicArr));
	arr -> array = (int*)malloc(sizeof(int) * size);
	arr -> len = 0;
	arr -> capacity = size;
	return arr;
}

struct DynamicArr* addElement(struct DynamicArr* arr, int element)
{
	struct DynamicArr* a = arr;
	if (arr -> len == arr -> capacity)
	{
		arr -> capacity *= 2;
		arr -> array = (int*)realloc(arr -> array, sizeof(int) * arr -> capacity);
	}
	arr -> array[arr -> len++] = element;
	return a;
}

void printArr(struct DynamicArr* arr)
{
	for (int i = 0; i < arr -> len; i++)
		printf("%d ", arr -> array[i]);
	printf("\n");
}

int main()
{
	int size;
	printf("输入数组大小: ");
	scanf("%d", &size);
	struct DynamicArr* c_arr = createArr(size);

	int element;
	printf("添加元素中，输入要添加的元素值: ");
	scanf("%d", &element);
	while(1)
	{
		if (element == 0) break;
		addElement(c_arr, element);
		scanf("%d", &element);
	}
	
	printArr(c_arr);

	/** test1
	printf("capacity为: %d\n", c_arr -> capacity);
	printf("len为: %d\n", c_arr -> len);
	*/

	/** test2
	printf("修改前：\n");
	printArr(c_arr);
	c_arr -> array[0] = 99;
	printf("修改后：\n");
	printArr(c_arr);
	*/

	return 0;
}
