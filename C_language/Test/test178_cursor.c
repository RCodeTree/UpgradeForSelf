#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    printf("%d ", *p++);
    printf("%d ", (*p)++);
    printf("%d ", *p);
    printf("%d ", *++p);
    printf("%d\n", ++*p);
    return 0;
}