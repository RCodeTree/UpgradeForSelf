#include <stdio.h>

struct S1 {
    char c1;
    int i;
    char c2;
};

struct S2 {
    char c1;
    char c2;
    int i;
};

struct S3 {
    double d;
    char c;
    int i;
};

struct S4 {
    char c1;
    struct S3 s3;
    double d;
};

int main() {
    printf("%ld\n", sizeof(struct S1)); // 12
    printf("%ld\n", sizeof(struct S2)); // 8
    printf("%ld\n", sizeof(struct S3)); // 16
    printf("%ld\n", sizeof(struct S4)); // 32
    return 0;
}
