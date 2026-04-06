/*#include <stdio.h>
int calc(int n) {
	static int s = 1;
	if(n == 0) return s = 1;
	s = s * n + calc(n-1);
	return s;
}
int main() {
	int i, res;
	for(i=1; i<=4; i++) { res = calc(i); printf("%d ", res); }
	return 0;
}*/

/*void main() {
	int a = 5, b = 3, c = 8, d = 2;
	a <<= 1;
	b ^= a & c;
	d = ++a + b-- > c ? a : c;
	printf("%d %d %d %d\n", a, b, c, d);
}*/


/*void strCat(char* s, char* t)
{
    while (*s != '\0')
    {
        s++;
    }
    while ((*s = *t) && *t != '\0')
    {
        s++;
        t++;
    }
    *s = '\0';
}

int main()
{
    char s[50] = "Hello ", t[] = "World!";
    strCat(s, t);
    printf("拼接后的字符串：%s\n", s);
    return 0;
}*/

/*#include <stdio.h>

int countCall()
{
    static int num = 0; // 1
    num++;
    return num;
}

void printCount()
{
    static int total = 0; // 2
    total++;
    printf("当前调用累计次数：%d\n", total);
}

int main()
{
    printf("第 1 次调用：");
    printCount();
    printf("第 2 次调用：");
    printCount(); // 3
    printf("第 3 次调用：");
    printCount();
    return 0;
}*/

/*#include <stdio.h>

int countCall()
{
    int num = 0;
    num++;
    return num;
}

void printCount()
{
    static int total = 0;
    total += countCall(); // 2
    printf("当前调用累计次数：%d\n", total); // 3
}

int main()
{
    printf("第 1 次调用：");
    printCount();
    printf("第 2 次调用：");
    printCount(); // 1
    printf("第 3 次调用：");
    printCount();
    return 0;
}*/


// 编程题

/***
@brief
1. 编写一个函数 f(int u)，判断一个整数 u 是否同时是 3 的倍数和 5 的倍数。
2. 编写一个主函数，输入一个整数 n，输出 1 到 n 中所有同时是 3 的倍数和 5 的倍数的整数的累加和。
*/
/*#include <stdio.h>

int f(int u)
{
    int flag = 0;
    if (u % 3 == 0)
    {
        if (u % 5 == 0)
        {
            flag = 1;
        }
    }
    return flag;
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (f(i))
        {
            printf("%d ", i);
            sum += i;
        }
    }
    printf("\n");
    printf("累加和结果为：%d\n", sum);
    return 0;
}*/

#include <stdio.h>

int search(int* arr, int flag, int len)
{
    if (flag == 1) flag = 1;
    else if (flag < 0) flag = -1;
    int res = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (res * flag < arr[i] * flag) res = arr[i];
    }
    return res;
}

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("请输入第 %d 个整数：", i + 1);
        scanf("%d", &arr[i]);
    }
    int min = search(arr, -1, 5);
    int max = search(arr, 1, 5);
    printf("最小值：%d\n", min);
    printf("最大值：%d\n", max);
    int diff = max - min;
    printf("差值：%d\n", diff);
    return 0;
}
