#include <stdio.h>

struct Stu {
	char name[20];
	int age;
};


// 打印结构体属性值
void printStruct(struct Stu *s)
{
	printf("s2的属性值分别为：%s, %d\n", (*s).name, (*s).age);

	/*
	 使用 “->” 操作符的前提是，该变量必须为一个结构体指针变量
	 下方通过 “->” 访问了该指针(*s)内部的属性值
	 */
	printf("s2的属性值分别为(通过结构体操作符 “->” 实现)：%s, %d\n", s->name, s->age);
	return;
}


int main()
{
	struct Stu s1 = {"zhangsan", 18};
	printf("s1的属性值分别为：%s, %d\n", s1.name, s1.age);

	struct Stu s2 = {"lisi", 19};
	printStruct(&s2);


	return 0;
}
