#include <stdio.h>
#include <math.h>

void main() {
    double e = 1.0f, num = 1; // e的初始值为1.0f，因为e的第0项为1.0f
    double multiple = 1;
    for (int i = 1; i < 1000; i++) {
        for (int j = 1; j <= i; j++) {
            multiple *= j;
        }
        e += num / multiple;
        if (multiple > pow(10, 6)) {
            printf("e = %f\n", e);
            break;
        }
        multiple = 1;
    }
}
