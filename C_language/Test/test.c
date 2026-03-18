#include <stdio.h>
#include <string.h>

#define ROW 4
#define COL 4
#define A(a, b) ((a + b) * (a + b))
// #define n 3
// #define m 4

/*int fun(int a[][COL], int row, int* b)
{
    int k = 0;
    int s = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (a[i][j] > 0 && a[i][0] != 0)
            {
                b[k++] = a[i][j];
            }
        }
    }
    for (int i = 0; i < row * row; i++)
    {
        if (b[i] > 0)
        {
            printf("%d ", b[i]);
            s += b[i];
        }
    }
    printf("\n");
    return s;
}*/

/*void fun(char* s1, char* s2)
{
    char *p = s1, *q = s2, *t = s1;
    int len = strlen(s1);
    int i = 0;
    int len2 = len;
    while (*q)
    {
        p = s1;
        len = len2;
        while (len--)
        {
            if (*q == *p) *p = '1';
            p++;
        }
        q++;
    }
    printf("s1 = %s\n", s1);
    p = s1;
    while (len2--)
    {
        if (*t != '1')
        {
            *(p + i) = *t;
            i++;
        }
        t++;
    }
    *(p + i) = '\0';
}*/

/*long fun(char* p)
{
    long num = 0;
    char* s = p;
    if (*s == '-')
    {
        while (*(++s))
        {
            num = num * 10 + (*s - '0');
        }
        return -num;
    }
    else
    {
        while (*s)
        {
            num = num * 10 + (*s - '0');
            s++;
        }
        return num;
    }
}*/

/*void reveres(char* s)
{
    if (*s == '\0') return;
    reveres(s + 1);
    printf("%c", *s);
}*/

/*void fun(char* a)
{
    int b[26], i, n, max;
    for (i = 0; i < 26; i++)
        b[i] = 0;
    n = strlen(a);
    for (i = 0; i < n; i++)
        if (a[i] >= 'a' && a[i] <= 'z')
            b[a[i] - 'a']++;
        else if (a[i] >= 'A' && a[i] <= 'Z')
            b[a[i] - 'A']++;
    max = 0;
    for (i = 1; i < 26; i++)
        if (b[max] < b[i])
            max = b[i];
    printf("出现最多的字符是： %c\n", max + 'a');
}*/


/*int fun(int* a, int n, int x)
{
    int p = 0, i;
    a[n - 1] = x;
    while (x != a[p])
        p = p + 1;
    if (p == n) return -1; // if(p==n) return ‐1;
    else
    {
        for (i = p; i < n - 1; i++)
            a[i + 1] = a[i]; //a[i]=a[i+1];
        return p;
    }
}*/


/*enum Color
{
    RED,
    GREEN = 5,
    BLUE,
};*/


/*void invert(char s[])
{
    char *p = s, *q = (strlen(s) - 1) + s;
    while (p < q)
    {
        char c = *p;
        *p = *q;
        *q = c;
        p++;
        q--;
    }
}*/


/*int getNum(int* a, int n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (*(a + (i - 1)) > *(a + i)) c++;
    }
    return c;
}*/

/*void getNum(int* arr, int N, int* min, int* max)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}*/

/*
int* count(int (*a)[m], int N, int M)
{
    static int t[3], z = 0, f = 0, x = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] > 0) z++;
            if (a[i][j] < 0) f++;
            if (a[i][j] == 0) x++;
        }
    }
    t[0] = z;
    t[1] = f;
    t[2] = x;
    return t;
}
*/

/*void printWord(char* s)
{
    char *p = s, *q = s;
    int max = 0, l = 0;
    while (*q && *q != '.')
    {
        if (*q == ' ')
        {
            if (l > max)
            {
                max = l;
                p = q - l;
            }
            l = 0;
        }
        if (*q != ' ') l++;
        q++;
    }
    if (l > max)
    {
        max = l;
        p = q - l;
    }
    while (max--)
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
}

void find_longest_word(char* str)
{
    char* p = str;
    char* word_start = NULL;
    char* longest_start = NULL;
    int curr_len = 0;
    int max_len = 0;

    while (*p != '.')
    {
        if (*p != ' ')
        {
            // 非空格字符，属于单词部分
            if (curr_len == 0)
            {
                word_start = p; // 新单词开始
            }
            curr_len++;
        }
        else
        {
            // 遇到空格，表示当前单词结束
            if (curr_len > max_len)
            {
                max_len = curr_len;
                longest_start = word_start;
            }
            curr_len = 0;
            word_start = NULL;
        }
        p++;
    }
    // 循环结束后，检查最后一个单词（可能没有空格结尾，直接遇到'.'）
    if (curr_len > max_len)
    {
        max_len = curr_len;
        longest_start = word_start;
    }

    if (max_len > 0)
    {
        printf("最长的单词是：");
        for (int i = 0; i < max_len; i++)
        {
            putchar(longest_start[i]);
        }
        putchar('\n');
    }
    else
    {
        printf("没有单词。\n");
    }
}*/

/*typedef struct
{
    int num;
    char name[30];
    float score[3];
} stu;

void print(stu s[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("num = %d, name = %s, score = %f, %f, %f\n", s[i].num, s[i].name, s[i].score[0], s[i].score[1],
               s[i].score[2]);
    }
}*/

/*int fun(int x[], int n)
{
    static int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        sum += x[i];
    }
    return sum;
}*/

int main()
{
    /*int a[5] = {0};
    a[0] = 1;
    for (int i = 0; i < 5; i++)
    	printf("%d\n", a[i]);*/

    /*struct stud
    {
        char num[6];
        int s[4];
        double ave;
    };
    printf("%lu\n", sizeof(struct stud)); // 32*/

    /*struct
    {
        int x;
        int y;
    } s[2] = {{1, 2}, {3, 4}}, *p = s;
    printf("%d\n", ++p->x); // 2*/

    /*union data
    {
        int a[10];
        int b[2][5];
    };
    union data ab;
    int i, j;
    for (int i = 0; i < 10; i++)
        scanf("%d", &(ab.a[i]));*/

    /*int sss = 0, b[16] = {0};
    int a[ROW][COL] = {{1, 2, -3, -4}, {0, -12, -13, 14}, {-21, 23, 0, -24}, {-31, 32, -33, 0}};
    sss = fun(a, ROW, b);
    printf("sss = %d\n", sss);*/

    /*char s1[300] = "abcaa63akdfk", s2[300] = "ayk5";
    fun(s1, s2);
    printf("%s\n", s1);*/

    /*char s[10];
    long n;
    gets(s);
    n = fun(s);
    printf("%ld\n", n);*/

    /*char* s = "1234567890";
    reveres(s);
    printf("\n");*/


    /*char* s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbddddcccckjl";
    fun(s);*/

    /*int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int x = 9;
    int p = fun(a, n, x);
    if (p == -1)
        printf("x 不在数组中\n");
    else
        printf("x 的下标是： %d\n", p);*/

    /*printf("%d\n", RED);
    printf("%d\n", GREEN);
    printf("%d\n", BLUE);*/

    /*int a = 2, b = 3;
    printf("%d\n", A(a, b));*/

    /*char s[100] = "123456";
    invert(s);
    printf("%s\n", s);*/

    /*int c = 0;
    for (int i = 1000; i <= 9999; i++)
    {
        int q = i / 1000;
        int b = i / 100 % 10;
        int s = i % 100 / 10;
        int g = i % 10;
        if (q * q * q * q + b * b * b * b + s * s * s * s + g * g * g * g == i)
        {
            printf("%d ", i);
            c++;
        }
    }
    printf("\n");
    printf("c = %d\n", c);*/

    /*int a[] = {1, 3, 2, 5, 4, 2, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    int c = getNum(a, n);
    printf("c = %d\n", c);*/

    /*int a[] = {1, -3, 2, 5, 4, 2, 7, 10};
    int N = sizeof(a) / sizeof(a[0]);
    int min = a[0], max = a[0];
    getNum(a, N, &min, &max);
    printf("min = %d, max = %d\n", min, max);*/

    /*int a[n][m] = {{-1, 2, 3, 4}, {0, 5, 6, -4}, {7, 0, 9, -2}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    int* t = count(a, n, m);
    printf("z = %d, f = %d, x = %d\n", t[0], t[1], t[2]);*/

    /*char* s = "1 23fafa4 542342324234236 7890 afasdasdfafasdf abcde 1111111fafffffffffffffffff11.";
    printWord(s);*/

    /*stu ss[5];
    for (int i = 0; i < 5; i++)
    {
        printf("请输入第 %d 个学生的信息：\n", i + 1);
        scanf("%d %s %f %f %f", &ss[i].num, ss[i].name, &ss[i].score[0], &ss[i].score[1], &ss[i].score[2]);
    }
    print(ss);*/

    /*FILE* source = fopen("d1.txt", "r");
    FILE* target = fopen("d2.txt", "w");
    char c = fgetc(source);
    while (!feof(source))
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            fputc(c, target);
        c = fgetc(source);
    }
    fclose(target);
    fclose(source);*/

    /*int arr[5] = {2, 4, 6, 8, 10};
    int* p = arr + 1;
    printf("%d\n", *(p + 2) - *(--p));*/

    /*int arr[4] = {10, 20, 30, 40};
    int* p = arr;
    while (p < arr + 4)
    {
        printf("%d ", *p++);
    }
    printf("\n");*/

    /*int a[] = {1, 2, 3, 4, 5}, b[] = {6, 7, 8, 9}, s = 0;
    s = fun(a, 5 + fun(b, 4));
    printf("%d\n", s);*/


    return 0;
}
