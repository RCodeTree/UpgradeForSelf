// 归并排序：将两个有序数组合并成一个有序数组(升序)
#include <stdio.h>
int main()
{
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6,8,10};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    int i = 0;
    int j = 0;
    int k = 0;
    int temp[len1 + len2];

    // 合并两个有序数组
    while(i < len1 && j < len2)
    {
        if(arr1[i] < arr2[j])
        {
            temp[k++] = arr1[i++];
        }
        else
        {
            temp[k++] = arr2[j++];
        }
    }

    // 处理剩余元素(可能剩余在arr1或arr2，也可能剩余的不止一个)
    while(i < len1)
    {
        temp[k++] = arr1[i++];
    }
    while(j < len2)
    {
        temp[k++] = arr2[j++];
    }

    // 打印合并后的数组
    for(i = 0; i < len1 + len2; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}