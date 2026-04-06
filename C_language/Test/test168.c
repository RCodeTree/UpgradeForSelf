#include <stdio.h>
#define PI 3.14159

/*int main()
{
    double r = 1 / 4;
    double area = PI * r * r;
    printf("%.2f\n", area); // 保留2位小数
    return 0;
}*/

/*int main()
{
    int arr[] = {3, 3 / 4, 5};
    int sum = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        sum += arr[i];
    printf("%d\n", sum);
    return 0;
}*/

void reverse_print(int arr[], int n)
{
    // TODO: 完成逆序输出数组元素的代码
    for (int i = 0; i < n / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse_print(arr, n);
    return 0;
}
