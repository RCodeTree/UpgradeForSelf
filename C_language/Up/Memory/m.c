#include <stdio.h>
#include <string.h>
#include <assert.h>

void *my_memcpy(void *dest, const void *src, size_t n) {
    void *ret = dest;
    char *pdest = (char *) dest;
    const char *psrc = (const char *) src;
    while (n--) {
        *pdest++ = *psrc++;
    }
    return ret;
}

void *my_memmove(void *dest, const void *src, size_t n) {
    void *ret = dest;
    char *pdest = (char *) dest;
    const char *psrc = (const char *) src;

    if (pdest < psrc) {
        // 情况1：dest 在 src 前面，从前向后拷贝（同 memcpy）
        while (n--) {
            *pdest++ = *psrc++;
        }
    } else {
        // 情况2：dest 在 src 后面（含重叠），从后向前拷贝
        while (n--) {
            pdest[n] = psrc[n]; // 或者：*(pdest + n) = *(psrc + n);
        }
    }
    return ret;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[10] = {0};

    // memcpy(b, a, 12);
    my_memcpy(b, a, 12);
    my_memmove(a + 1, a, sizeof(int) * 2);
    for (int i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);
    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");


    printf("---------------------------------\n");


    int c[3] = {1, 2, 3};
    int d[3] = {1, 2, 3};
    int e[3] = {1, 3, 2};
    int result1 = memcmp(c, e, sizeof(int) * 3);
    int result2 = memcmp(c, d, sizeof(int) * 3);
    printf("result1: %d\n", result1);
    printf("result2: %d\n", result2);

    char f[] = "hello world";
    memset(f, 'x', sizeof(char) * 3);
    for (int i = 0; i < strlen(f); i++) printf("%c ", f[i]);
    printf("\n");

    int g[3];
    memset(g, 1, sizeof(int) * 3); // 由于memset将内存设置为字节单位，所以这里每个int都被设置为0x01010101, 由此每一个元素的十进制是16843009
    for (int i = 0; i < 3; i++) printf("%d ", g[i]);
    printf("\n");
    return 0;
}
