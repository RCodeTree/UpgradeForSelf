#include <stdio.h>
#include <string.h>

/***
 * @brief 优化冒泡排序，设置排序标记flag
 * 如果在某轮排序中没有发生交换，说明数组已经有序，直接跳出循环
 */
/*int main()
{
    int arr[5] = {6, 3, 8, 2, 1};
    int i, j, temp, n = 5, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
    printf("count = %d\n", count);
    return 0;
}*/

/*
int main()
{
    int a = 15, b = 8;
    int c = a ^ b;
    c = c & b;
    printf("%d\n", c);
    return 0;
}
*/

// 编程题
/*
void f(unsigned int num)
{
	if (num == 0) return;
	f(num / 2);
	printf("%d", num % 2);
}
int main()
{
	unsigned int num;
	scanf("%u", &num);
	f(num);
	return 0;
}
*/

void reverse(char* s)
{
    char *p1 = s, *p2 = s + strlen(s) - 1;
    while (p1 < p2)
    {
        char t = *p1;
        *p1 = *p2;
        *p2 = t;
        p1++;
        p2--;
    }
}
int main()
{
    char str[100];
    scanf("%s", str);
    reverse(str);
    printf("%s", str);
    return 0;
}
