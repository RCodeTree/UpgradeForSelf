# 定义与声明规则
- [] 比 * 结合更紧： int *a[10] 是“数组的每个元素都是指针”； int (*a)[10] 是“指向 10 个 int 数组的指针”
- 读取声明时，从标识符出发，按“优先级：括号 > [] > * ”绕圈理解


# 字符指针
``` c
#include <stdio.h>
int main()
{
	char ch = 'w';
	char *p = &ch;
	*p = 'a';
	printf("%c", *p); // a

	return 0;
}
```
``` c
/* 
- 这里的字符指针ch指向的是一个字符串常量"hello world"，实际上指向的是字符串常量的第一个字符'h'的地址，即指向的是该字符串的首地址
- 当使用%s格式化输出时，会从该地址开始输出，直到遇到字符串结束符'\0'为止
*/
#include <stdio.h>
int main()
{
	char* ch = "hello world";
    printf("%c\n", *ch); // h
    printf("%c\n", *(ch + 1)); // e
	printf("%s\n", ch); // hello world 
    printf("%s\n", ch + 1); // ello world ----> 调整char指针，指向字符串常量的第二个字符'e'的地址
	return 0;
}
```


# 指针数组 ---- 指针数组是一个数组，数组的每个元素都是指针
``` c
/* 
主要作用：
- 可以将多个字符串存储在一个数组中
- 可以将多个指针存储在一个数组中
*/
#include <stdio.h>
int main()
{
	char* ch[3];
	ch[0] = "hello";
	ch[1] = "world";
	ch[2] = "!";
	printf("%s\n", ch[0]); // hello
	printf("%s\n", ch[1]); // world
	printf("%s\n", ch[2]); // !

	return 0;
}
```
``` c
// 可以模拟二维数组
#include <stdio.h>
int main()
{
	int arr1[3] = {1, 2, 3};
	int arr2[3] = {4, 5, 6};
	int arr3[3] = {7, 8, 9};

	int* parr[3] = {arr1, arr2, arr3};

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
            // *(arr + i) <----> arr[i]
			// printf("%d ", parr[i][j]);
            // printf("%d ", *(parr[i] + j));
			printf("%d ", *(*(parr + i) + j));
		}
		printf("\n");
	}

    /* 
    输出结果：
    1 2 3
    4 5 6
    7 8 9
    */
	
	return 0;
}
```


# 数组指针 ---- 数组指针是一个指针，指针指向的是一个数组(即指向数组的指针)
- 数组名通常表示的都是数组首元素的地址
	- 但是有两个例外：
		- sizeof(数组名)：表示的是整个数组的大小，单位是字节
		- &数组名：表示的是数组的地址
``` c
#include <stdio.h>
int main()
{
	int arr[3] = {1, 2, 3};
	int(*parr)[3] = &arr; // 数组指针parr指向数组arr的地址

	printf("%d\n", *(*parr + 1)); // 2
	printf("%d\n", (*parr)[1]); // 2

	return 0;
}
```
## 实际上，数组指针的应用场景多是二维数组
``` c
#include <stdio.h>
void printArray(int (*arrp)[4], int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%d ", *(*(arrp + i) + j));
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	printArray(arr, 3, 4);

	return 0;
}
```
## 一个例子
- int* parr[10] ----> 指针数组，每个元素都是指向 int 类型的指针(地址)
- int (*arrp)[10] ----> 数组指针，指向 10 个 int 数组的指针(地址)
- int (*arrp[10])[5] ----> 数组指针的数组，每个元素都是指向 5 个 int 数组的指针(地址)


# 数组参数、指针参数
- 数组参数：在函数参数中传递数组时，数组会退化为指针
- 指针参数：在函数参数中传递指针时，指针会保持指向的地址不变
- 一级指针存储的是变量的地址
- 二级指针存储的是一级指针的地址
``` c
/* 
反过来思考，如果函数的参数部分是一级指针，实际参数可以传递什么过来？
void print(int* p) {}
int a = 10;
int* p = &a;
int arr[10];

print(p);
print(&a);
print(arr);
*/
// 一级指针传参
#include <stdio.h>
void print(int* p, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	print(arr, 5); // 1 2 3 4 5

	return 0;
}
```
``` c
/*
反过来思考，如果函数的参数部分是二级指针，实际参数可以传递什么过来？
？？？？
*/
// 二级指针传参
#include <stdio.h>
void test(int** p)
{
	printf("num = %d\n", **p);
}

int main()
{
	int a = 10;
	int* p = &a;
	int** pp = &p;
	int* arr[10];

	test(pp);
	test(&p);
	test(arr);
```


# 函数指针 ---- 函数指针是一个指针，指针指向的是一个函数(即指向函数的指针)
``` c
#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}

int main()
{
	// 使用 & 和 不使用 & 都可以
	// int(*p)(int, int) = &add; // 函数指针p指向函数add的地址
	int(*p)(int, int) = add; // 函数指针p指向函数add的地址

	// 使用 * 和 不使用 * 都可以
	// printf("%d\n", (*p)(1, 2)); // 3
	printf("%d\n", p(1, 2)); // 3

	return 0;
}
```
