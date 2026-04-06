#include <stdio.h>

/**
 * 输出所有满足条件的abc + cba = 1333的数
 * @return 0
 */
int main() {
    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++)
            for (int c = 1; c <= 9; c++)
                if ((a * 100 + b * 10 + c) + (c * 100 + b * 10 + a) == 1333)
                    printf("a=%d, b=%d, c=%d\n", a, b, c);
    return 0;
}
