#define _CRT_SECURE_NO_WARNINGS // 忽略不兼容的警告
#include <stdio.h>
/*
	变量和常量：
		变量

		作用域

		常量
*/

/*
		变量：
			输入两个数，求两数之和
*/
// int main()
// {
// 	int num1 = 0;
// 	int num2 = 0;
// 	printf("请输入两个整数：");
// 	scanf("%d %d", &num1, &num2); // 接收用户输入的两个整数并存储到变量中 ---> 这里是将分别输入的两个数分别存入num1、num2的地址值中
// 	int sum = num1 + num2;
// 	printf("它们的和为：%d", sum);
// 	return 0;
// }

/*
		变量作用域：
			全局变量和局部变量的区别
			在函数内部声明的变量只能在该函数内部使用（作用域问题）
*/
// int a = 2; // 全局变量
// extern b; // 外部变量声明，实际定义在另一个文件中 ---> 使用 extern 引入外部变量
// int main() {
//	{
//		int a = 1; // 局部变量，作用域为当前代码块
//		printf("a=%d\n", a);
//	}
//	printf("a=%d\n", a);
//	printf("b=%d", b);
//	return 0;
// }

// int a = 2;
// int main() {
//	{
//		int a = 1;
//		printf("a=%d\n", a); // 输出局部变量的值 ---> 当全局变量和局部变量相同时，局部优先
//	} // 但是建议全局变量名和局部变量名不要相同
//	return 0;
// }

// int a = 2; // 全局变量，在整个文件范围内有效
// void test() {
//	printf("test--->%d\n", a);
// }
//
// int main() {
//	test(); // 2
//	{
//		printf("a=%d\n", a); // 2
//	}
//	printf("a=%d\n", a); // 2
//	return 0;
// }

/*
	常量：
		字面常量
		const修饰的常变量
		define定义的标识符常量
*/
// #define MAX 1
// #define STRING "hello world"
// #define CHAR 'A'
// int main()
// {
// 	/*
// 	字面常量
// 	'a';
// 	"abc";
// 	1;
// 	666;
// 	*/

// 	/*
// 	const修饰的常变量
// 	*/
// 	// const int a = 1;   // 在C语言中，const修饰的a，本质是变量，但是不能直接修改，有常量的属性
// 	// printf("a=%d", a); // 1
// 	// // 例如：
// 	// // a = 2; // err
// 	// const int b = 10;
// 	// int arr[10] = {0};
// 	// // int arr[b] = {0};  // err

// 	/*
// 	define定义的标识符常量
// 	 */
// 	// int a = MAX; // define定义的标识符常量要先赋值给变量才能输出
// 	// char b[] = STRING;
// 	// char c = CHAR;
// 	// // MAX = 2;				  // err
// 	// printf("MAX=%d\n", a);	  // MAX=1
// 	// printf("STRING=%s\n", b); // STRING=hello world
// 	// printf("CHAR=%d", c);	  // CHAR=65  // 这里的字符是以ASCII码表进行对应的值输出
// 	return 0;
// }
/*
枚举常量
*/
enum Color
{
	RED,
	GREEN,
	BLUE
};
int main()
{
	int num = 10;
	enum Color c = RED;
	// printf("c=%d\n", c); // c=0
	c = num;
	printf("c=%d", c); // c=10
}