#include <stdio.h>
/* int main(){
    char ch;
    while ((ch = getchar()) != '#'){
        putchar(ch);
    }

    printf("\n");
    return 0;
} */

int main(){
    char ch;
    while (scanf("%c", &ch) && ch != '#'){
        printf("%c", ch);
    }
    printf("\n");
    return 0;
}

