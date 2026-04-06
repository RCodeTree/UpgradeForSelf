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
}
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
## 经典例子
``` c
#include <stdio.h>
int main()
{
	/* 
	以下代码是一次函数的调用，调用的是0作为地址处的函数
	1. 把0强制转换为：无参，返回类型是void的函数的地址
	2. 调用0地址处的这个函数

	- void(*)() 是函数指针类型
	- 0 是一个地址，指向的是一个无参数、无返回值的函数
	- (void(*)())0 是一个强制类型转换，将 0 转换为一个无参数、无返回值的函数指针
	- *(void(*)())0 是一个解引用操作，将 0 转换为一个无参数、无返回值的函数指针，然后调用该函数
	*/
	( *( void(*)() )0 )();
	return 0;
}
```
``` c
#include <stdio.h>
int main()
{
	/* 
	以下代码是一次函数的声明
	
	signal 是一个函数，它接受两个参数：

	1. 一个整型 ( int )
	2. 一个函数指针（指向一个接受 int 返回 void 的函数）
	并且， signal 函数的返回值也是一个函数指针（指向一个接受 int 返回 void 的函数） ----> 即 void(*)(int)
	*/
	void (* signal( int, void(*)(int) ) )(int);
	return 0;
}
```


# 函数指针数组
- 函数指针数组是一个数组，数组的每个元素都是一个函数指针
- 函数指针数组可以用来存储多个函数的地址
- 函数指针数组可以用来实现多态
``` c
#include <stdio.h>
int func1(int a)
{
	printf("func1: %d\n", a);
}

int func2(int a)
{
	printf("func2: %d\n", a);
}

int main()
{
	int (*pf)(int) = func1;
	int (*pfarr[])(int) = {func1, func2};
	for(int i = 0; i < 2; i++)
	{
		pfarr[i](i); 
        /* 
        result:
        func1: 0
        func2: 1
        */
	}

	return 0;
}
```
## 函数指针数组的应用场景
- 函数指针数组可以用来实现多态
- 函数指针数组可以用来存储多个函数的地址
- 函数指针数组可以用来实现回调函数


# 函数指针数组指针
- 函数指针数组指针是一个指针，指针指向的是一个函数指针数组
``` c
#include <stdio.h>
int func1(int a)
{
	printf("func1: %d\n", a);
}

int func2(int a)
{
	printf("func2: %d\n", a);
}

int main()
{
	int (*pfarr[])(int) = {func1, func2};
	int (*(*pfarrp)[2])(int) = &pfarr;
	for(int i = 0; i < 2; i++)
	{
		// (*pfarrp)[i](i);
		(**pfarrp + i)(i); 
        /* 
        result:
        func1: 0
        func2: 1
        */
	}
	return 0;
}
```


# 回调函数
- 经典例子：qsort函数
- qsort函数的参数：
    - void* base：指向要排序的数组的第一个元素的指针
    - size_t num：数组中元素的数量
    - size_t size：每个元素的大小（以字节为单位）
    - int (*cmp)(const void* a, const void* b)：比较函数的指针，用于确定元素的顺序  ----> 比较规则(如果第一个参数小于第二个参数，返回一个负数；如果第一个参数大于第二个参数，返回一个正数；如果两个参数相等，返回0)
	1. qsort比较函数规则
		- 返回值 < 0 ：a 排在 b 前面
		- 返回值 = 0 ：a 和 b 相等
		- 返回值 > 0 ：a 排在 b 后面
	2. 具体分析
	``` c
	return (*(int*)a - *(int*)b);
	```
	- 情况分析 ：
		- 如果 a < b ： a - b < 0 → a 排在 b 前面（升序）
		- 如果 a = b ： a - b = 0 → 顺序不变
		- 如果 a > b ： a - b > 0 → a 排在 b 后面（升序）
- qsort函数的实现：
    - 1. 对数组进行分区，将数组分为两个部分：小于等于基准值的部分和大于基准值的部分
    - 2. 对两个部分分别递归调用qsort函数
- qsort函数的应用场景：
    - 对数组进行排序
    - 对结构体数组进行排序
    - 对自定义类型的数组进行排序
``` c
#include <stdio.h>
#include <stdlib.h>

// 实现qsort函数中cmp函数的比较规则 ---- 即回调函数
int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	qsort(arr, 5, sizeof(int), cmp);
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
```


# void* 
- void* 是无具体类型的指针，可以接受任意类型的地址
- void* 是无具体类型的指针，所以不能解引用操作，也不能进行算术运算
