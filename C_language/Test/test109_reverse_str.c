#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *a) {
    char *t = (char *) malloc(sizeof(char) * (strlen(a) + 1));
    for (int i = strlen(a) - 1; i >= 0; i--)
        *(t + strlen(a) - 1 - i) = a[i];
    *(t + strlen(a)) = '\0';
    return t;
}

int main() {
    char s[] = "Hello";
    char *r = reverse(s);
    printf("%s\n", r);
    return 0;
}
