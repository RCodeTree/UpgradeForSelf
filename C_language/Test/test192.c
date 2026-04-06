#include <stdio.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int originalToComplement(int original) {
    if (original >= 0) {
        return original;
    }
    
    // 负数的补码转换
    unsigned int absValue = (unsigned int)(-original);
    unsigned int complement = ~absValue + 1;
    return (int)complement;
}

int main()
{
    int n;
    scanf("%d", &n);
    int complement = originalToComplement(n);
    printf("%d\n", complement);
    printBinary(complement);
    return 0;
}
