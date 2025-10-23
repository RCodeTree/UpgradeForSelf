// 库函数
#include <stdio.h>
#include <string.h>
int main()
{
	/*
	strcpy() 函数，用于字符串的复制
	函数原型：char *strcpy(char *dest, const char *src);
	参数：
		dest：目标字符串，即要复制到的字符串
		src：源字符串，即要复制的字符串
	返回值：
		返回指向目标字符串的指针 ---> 就是参数dest指向的内存地址

	char arr1[] = { 0 };
	char arr2[] = "hello world";

	strcpy(arr1, arr2);

	printf("arr1的值为：%s\n", arr1);
	*/


	/*
	 * memset() 函数，用于内存设置
	 * 函数原型：void *memset(void *s, int c, size_t n);
	 * 参数：
	 * 	s：要设置的内存地址 ---> 要设置的内存空间的开始地址
	 * 	c：要设置的值，以int类型传递，会自动转换为char类型
	 * 	n：要设置的字节数
	 * 返回值：
	 * 	返回指向目标内存地址的指针 ---> 就是参数s指向的内存地址
	 */
	char arr[] = "hello world";

	memset(arr, 'x', 3);

	printf("arr的值为：%s\n", arr);



	return 0;
}
