#include <stdio.h>
// 定义判断闰年的宏
#define IS_LEAP_YEAR(year) ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))

int main()
{
    int i = 2023;

    // 测试闰年判断
    int years[] = {2000, 2004, 2008, 2012, 2016, 2020, 2024, 2028, 2032, 1900, 2001, 2023};
    int count = sizeof(years) / sizeof(years[0]);

    for (int j = 0; j < count; j++)
    {
        int year = years[j];
        if (IS_LEAP_YEAR(year))
        {
            printf("%d 是闰年\n", year);
        }
        else
        {
            printf("%d 不是闰年\n", year);
        }
    }

    return 0;
}
