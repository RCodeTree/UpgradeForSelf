#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 4
#define COL 4
#define A(a, b) ((a + b) * (a + b))
#define N 5
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

/*int f(int m)
{
    static int i = 2;
    int s = 0;
    for (; i <= m; i++) s += i;
    return s;
}*/

/*typedef struct node
{
    int x;
    struct node* next;
} node;*/

/*void quickSort(int arr[], int i, int j)
{
    int start = i;
    int end = j;

    if (start > end) return;

    int baseNum = arr[i];

    while (start != end)
    {
        //利用end，从后往前开始找，找比基准数小的数字
        while (1)
        {
            if (end <= start || arr[end] < baseNum)
            {
                break;
            }
            end--;
        }

        //利用start，从前往后开始找，找比基准数大的数字
        while (1)
        {
            if (end <= start || arr[start] > baseNum)
            {
                break;
            }
            start++;
        }

        //把end和start指向的元素进行交换
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    //当start和end指向了同一个元素的时候，那么上面的循环就会结束
    //表示已经找到了基准数在数组中应存入的位置
    //基准数归位
    //就是拿着这个范围中的第一个数字，跟start指向的元素进行交换
    int temp = arr[i];
    arr[i] = arr[start];
    arr[start] = temp;

    //利用递归重复quickSort排序好基准数两边的数据
    //基准数左边的数
    quickSort(arr, i, start - 1);
    //基准数右边的数
    quickSort(arr, start + 1, j);
}*/

/*long fun(int n)
{
    return n * n;
}*/

/*void fun(int* a, int n)
{
    int i, m, t, k;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (k = i + 1; k < n; k++)
        {
            if (a[k] > a[m])
            {
                m = k;
            }
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}*/

/*void fun(char* str, char ch)
{
    while (*str && *str == ch) str++;
    if (*str == ch)
    {
        *str = ch;
        *(str + 1) = 0;
    }
}*/

/* void insert(char* aa)
{
    int i, j, n;
    char ch;
    n = strlen(aa);
    for (i = 1; i < n; i++)
    {
        ch = aa[i];
        j = i - 1;
        1;
        while ((j >= 0) && (ch < aa[j]))
        {
            aa[j + 1] = aa[j];
            j--;
        }
        aa[j + 1] = ch;
    }
} */

/*
float f(float*, int);
float f(float* a, int n);
*/

/*char* f1(char s1[], char s2[])
{
    int i, j, m;
    m = strlen(s2);
    for (i = 0; i < strlen(s1) - m; i++)
    {
        for (j = 0; j < m; j++) if (s1[i + j] != s2[j]) break;
        if (j == m) return s1 + i;
    }
    return NULL;
}*/

/*int jc(int k)
{
    return k < 2 ? 1 : k * jc(k - 1);
}*/

/*void f(int a[][5], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) a[i][j] = 0;
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) a[i][j] = jc(i + j);
}*/

/*
char* f(char* s)
{
    char c;
    int k;
    c = s[0];
    k = strlen(s);
    strcpy(s, s + 1);
    s[k - 1] = c;
    s[k] = '\0';
    return s;
}
*/

/*int f(int n)
{
    int c;
    if (n == 1) c = 10;
    else c = f(n - 1) + 2;
    return c;
}*/

/*void strc(char* strDest, char* strSrc)
{
    char temp[80], *p;
    int i = 0;
    strcpy(temp, strDest + 1);
    for (p = strDest; p <= strDest + strlen(strSrc); p++)
        *p = strSrc[i++];
    *p = '\0';
    strcat(strDest, temp);
}*/

/*int f(int x, int y)
{
    static int a = 1;
    return a = a + x + y;
}*/

/*long fib(int n)
{
    if (n > 2) return fib(n - 1) + fib(n - 2);
    else return 1;
}*/

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

void printLink(Node* head)
{
    Node* p1 = head->next;
    while (p1 != NULL)
    {
        printf("%d ", p1->val);
        p1 = p1->next;
    }
    printf("\n");
}

/*Node* distinctNode(Node* head)
{
    Node* p1 = head->next;
    Node *p2 = p1->next, *h = head;
    while (p2 != NULL)
    {
        if (p1->val == p2->val)
        {
            Node* t = p1->next->next;
            Node* t2 = p1->next;
            p1->next = t;
            p2 = t;
            free(t2);
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return h;
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

    /*char* s = "1 23fafa4 542342324234236 7890 afasdasdfafasdffasdfasdfasdaafafda abcde 1111111fafffffffffffffffff11.";
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

    /*int n = 1;
    printf("%d %d\n", n++, ++n);
    printf("%d %d\n", n, n++); // 2 1 -----> 先计算了n++, 再计算了n
    printf("%d\n", n); // 2*/

    /*
    int sum = f(3) + f(5);
    printf("%d\n", sum);
    */

    /*puts("jfakl");
    puts("jfakl");*/

    /*node *head, *p1, *p2;
    int n = 0;
    float ave = 0;
    while (1)
    {
        p2 = (node*)malloc(sizeof(node));
        scanf("%d", &p2->x);
        ave += p2->x;
        if (n++ == 0) head = p1 = p2;
        else
        {
            p1->next = p2;
            p1 = p2;
        }
        if (p2->x == 0)
        {
            p2->next = NULL;
            break;
        }
    }
    ave /= n;
    p1 = head;
    while (p1 -> next)
    {
        if (p1->x < ave) printf("%d\n", p1->x);
        p1 = p1->next;
    }*/

    /*FILE *pa = fopen("d1.txt", "r"), *pb = fopen("d2.txt", "w");
    char aa[11];
    float sl, jg;
    while (fscanf(pa, "%s%f%f", aa, &sl, &jg) != EOF)
    {
        if (aa[0] == '1') fprintf(pb, "%10s %10.3f %10.2f\n", aa, sl, jg * 0.9);
        else fprintf(pb, "%10s %10.3f %10.2f\n", aa, sl, jg);
    }
    fclose(pa);
    fclose(pb);
    remove("d1.txt");
    rename("d2.txt", "d1.txt");*/

    /*int x = 5;
    printf("%d %d", x++, ++x); // 6 7*/

    /*int n;
    int i = 0;
    printf("请输入数组的长度：");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;
    for (; i < n; i++)
    {
        if (scanf("%d", arr + i) != 1)
        {
            printf("输入包含非数字字符，程序终止！\n");
            free(arr);
            return 1;
        }
    }*/

    /*int y = 0;
    do { y = y * y; }
    while (!y);*/

    /*int x = 2, y = 3, z;
    z = (x -= x + 2), (x += 2, ++y); // z取的是 x-=x+2 的值
    printf("%d,%d,%d\n", x, y, z);*/

    /*int a = 3, b = 0, c = 3;
    if (a < b)
        if (b < 0) c = 5;
        else c += 2;
    printf("%d\n", c);*/

    /*int p = 5, q = 6, r;
    r = (p += p - 3), (q -= 2, ++p); // r = 7 p = 8 q = 4
    printf("%d,%d,%d\n", p, q, r);*/

    /*double f;
    f = 2, f + 8, f++;
    printf("%f\n", f);*/

    /*double x = 3.6, y = 5.2;
    int a = 9;
    printf("%lf\n", x + a % 4 * (int)(x + y) % 3 / 5);*/

    /*int p = 18, q = 4;
    p %= (q % 2);
    printf("%d\n", p);*/

    /*
     *printf("%8.3f%%", 2.0 / 3);
     *
     */

    /*FILE* s = fopen("d1.txt", "r");
    FILE* d = fopen("d2.txt", "w");
    char c = fgetc(s);
    while (!feof(s))
    {
        if (c != ' ') fputc(c, d);
        c = fgetc(s);
    }
    fclose(d);
    fclose(s);*/

    /*FILE* s = fopen("d1.txt", "r");
    FILE* d = fopen("d2.txt", "w");
    char c = fgetc(s);
    while (!feof(s))
    {
        if (c >= 'A' && c <= 'Z') fputc(c + 32, d);
        else fputc(c, d);
        c = fgetc(s);
    }
    fclose(d);
    fclose(s);*/

    /*FILE* s = fopen("d1.txt", "r");
    FILE* d = fopen("d2.txt", "w");
    char c;
    while ((c = fgetc(s)) != EOF)
    {
        if (!(c >= 'a' && c <= 'z'))
        {
            if (!(c >= 'A' && c <= 'Z'))
            {
                if (!(c >= '0' && c <= '9'))
                {
                    fputc(c, d);
                }
            }
        }
    }
    fclose(d);
    fclose(s);*/

    /*int a[5] = {2, 10, 4, 8, 6}; // 10 8 6 2 4
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    fun(a, 5);
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");*/

    /*char* str = "hello world";
    fun(str, 'e');
    printf("%s\n", str);*/

    /*char aa[10] = "bcad";
    insert(aa);
    printf("%s\n", aa);*/

    /*int a = 16, c;
    c = ~a;
    printf("%d\n", c);*/

    /*int n;
    scanf("%d", &n);
    if (n <= 0) return 1;
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", (a + i));
    int v = 0;
    for (int i = 0; i < n; i++) v += *(a + i);
    v = v / n;
    double r = 0;
    for (int i = 0; i < n; i++) r += pow(*(a + i) - v, 2);
    r = sqrt(r) / n;
    printf("v = %d, r = %f\n", v, r);*/

    /*
    // 4 + 16 + 1 + 3 = 24
    // 24 + 4 = 28
    struct student
    {
        int num;
        char name[16];
        char sex;
        int age;
    } s, *ps;
    printf("%lu %lu %lu\n", sizeof(struct student), sizeof(s), sizeof(ps)); // 28 28 8
    */

    /*short a = -1;
    printf("%d\n", a);
    printf("%d\n", ~a);*/

    /*FILE* s = fopen("d1.txt", "r");
    FILE* d = fopen("d2.txt", "w");
    char name[10];
    float score;
    while (fscanf(s, "%s %f", name, &score) != EOF)
    {
        if (score < 60) fprintf(d, "%s %f\n", name, score);
    }
    fclose(d);
    fclose(s);*/

    /*char* sp = "\x41\102c\0de";
    for (; *sp != '\0'; sp++) printf("*");*/

    /*int id;
    float score;
    int count;
    FILE* s = fopen("d1.txt", "r");
    if (!s) return 1;
    FILE* d = fopen("d2.txt", "w");
    if (!d) return 1;

    while (fscanf(s, "%d %f %d", &id, &score, &count) != EOF)
    {
        if (score + count > 100)
        {
            score = 100;
            fprintf(d, "%d %f %d\n", id, score, count);
        }
        else fprintf(d, "%d %f %d\n", id, score, count);
    }
    fclose(d);
    fclose(s);*/

    /*int m, i;
    while (scanf("%d", &m), m > 2)
    {
        for (i = 2; i <= sqrt(m); i++)
            if (m % i == 0)
            {
                printf("%d*%d=%d\n", i, m / i, m);
                break;
            }
        if (i > sqrt(m)) printf("不可分解\n");
    }*/

    /*
     二维数组实现：
     0 0 0 0 0
     1 0 0 0 0
     2 6 0 0 0
     6 24 120 0 0
     24 120 720 5040 0
     */
    /*int n = 5;
    int a[5][5];
    f(a, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("%d\t", a[i][j]);
        printf("\n");
    }*/
    /*//  编程，在[1,98]查找并输出所有满足条件“x + x+1 + x+2的平方根是整数”的数x（如输出2、11，因为2+3+4的和为9，11+12+13和为36，他们的平方根3、6都是整数）。
    int x1;
    for (x1 = 1; x1 <= 98; x1++)
    {
        int r = x1 + (x1 + 1) + (x1 + 2);
        if ((sqrt(r) * sqrt(r)) == r)
        {
            printf("%d ", x1);
        }
    }
    printf("\n");

    int x2;
    printf("在 [1,98] 中满足条件的 x 为：\n");
    for (x2 = 1; x2 <= 98; x2++)
    {
        int sum = x2 + (x2 + 1) + (x2 + 2); // 三个连续整数的和
        double root = sqrt(sum); // 取整后的平方根
        if (root * root == sum)
        {
            // 验证是否为完全平方
            printf("%d ", x2);
        }
    }
    printf("\n");*/

    /*
     *printf("%lu\n", sizeof("张三"));
     *
     */

    /*short a = 3;
    short b = -7;
    short c = a & b;
    printf("%d\n", c); // 1*/

    /*int a[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}}, i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j <= 3 - i; j++) printf("   ");
        for (j = 3 - i; j < 4; j++) printf("%3d", a[i][j]);
        putchar('\n');
    }*/

    /*double x;
    int n = 1;
    double r = 1.1;
    while (scanf("%lf", &x), x <= 1);
    while (pow(r, n) < x)
    {
        printf("%lf\n", pow(r, n));
        n++;
    }
    printf("%d\n", n);*/

    /*int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0)
                printf("%c%c", 219, 219);
            else
                printf(" ");
        printf("\n");
    }*/

    /* short a = 3;
    short b = -7;
    printf("%d\n", a | b); // 计算二进制如果得出仍是负数，则要转换回原码输出 */

    /*char a[10] = "1234567";
    for (int i = 1; i <= 4; i++) printf("%s\n", f(a));*/

    /*int n;
    int num = 1;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            num *= 4;
            a[i][j] = num;
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        int t = a[i][i];
        for (int j = 0; j < n; j++)
        {
            a[i][j] /= t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }*/

    /*int n, i;
    printf("\nplease input a number:\n");
    scanf("%d", &n);
    printf("%d=", n);
    for (i = 2; i <= n; i++)
    {
        while (n != i)
        {
            if (n % i == 0)
            {
                printf("%d*", i);
                n = n / i;
            }
            else
                break;
        }
    }*/

    /*
    // *
    // ***
    // *****
    // *******
    // *****
    // ***
    // *
    int i, j;
    int line = 7;
    int n = 4;
    int m = line - n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 2 * i - 1; j++)
    {
            printf("*");
    }
        printf("\n");
    }
    for (i = 3; i >= 1; i--)
    {
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }*/

    /*// 求第5个人的年龄
    int count = 4;
    int age = 10;
    while (count--)
    {
        age += 2;
    }
    printf("%d\n", age);
    printf("%d\n", f(5));*/

    /*// 输入一个整数，输出该整数的位数和该整数的反转数
    long num;
    scanf("%ld", &num);
    int count = 0;
    long temp = num;
    long r = 0;
    while (temp)
    {
        r = r * 10 + temp % 10;
        temp /= 10;
        count++;
    }
    printf("%d\n", count);
    printf("%ld\n", r);*/

    /*long num;
    scanf("%ld", &num);
    long temp = 0;
    long r = num;
    while (r)
    {
        temp = temp * 10 + r % 10;
        r /= 10;
    }
    if (temp == num) printf("This is a huiwen number\n");
    else printf("This is not a huiwen number\n");*/

    /*
     *FILE* s = fopen("D:\\UpgradeForSelf\\C_language\\Test\\d1.txt", "w");*/

    /*int a = 52;
    a /= 2 ^ 1;
    printf("%d\n", a);*/

    /*int i, j, a[4][4] = {
            {2, -1, 2, 7},
            {2, 4, 3, 5},
            {1, 4, -2, 3},
            {4, -2, 8, 3}
        };
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++) a[i][j] /= a[i][i];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++) printf("%4d", a[i][j]);
        putchar('\n');
    }*/

    /*int i;
    char a[80] = "Windows_xp,word_2003,VC_6.0";
    for (i = 0; a[i] != '\0'; i++)
        if (a[i] == ',') strc(a + i, "Microsoft");
    puts(a);*/

    /*int a = 10, b, c, i;
    b = 10 * a++;
    for (i = 1; i < 3; i++) c = f(a, b);
    printf("a,b,c:\n%d\n%d\n%d\n", a, b, c);*/

    /*int i, j, k, m;
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m - i + 1; j++) printf(" %d", i + j - 1); // 打印前半部分
        for (k = 1; j <= m; k++, j++) printf(" %d", k); // 打印后半部分
        printf("\n");
    }*/

    /*float a[N], x, v = 0, d;
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%f", a + i);
        v = v + a[i];
    }
    v /= 20;
    x = a[0];
    d = fabs(x - v);
    for (i = 1; i < N; i++)
        if (d > fabs(x - v))
        {
            d = fabs(x - v);
            x = a[i];
        }
    printf("%f  %f\n", v, x);*/

    /*// double x, area;
    // int i;
    // printf("请输入正方形 A1 的边长 x(x>1): ");
    // scanf("%lf", &x);
    // // 初始面积是 x²
    // area = x * x;
    // // 每个内接正方形面积是前一个的 1/2
    // for (i = 2; i <= 10; i++)
    // {
    //     area = area / 2;
    // }
    // printf("A10 的面积是: %.6lf\n", area);
    // 勾股定理
    // double x, h;
    // scanf("%lf", &x);
    // if (x <= 1) return -1;
    // for (int i = 2; i <= 10; i++)
    // {
    //     h = x / 2.0;
    //     x = sqrt(pow(h, 2) + pow(h, 2));
    // }
    // printf("%.6lf\n", x);
    // double s = sqrt(x);
    // printf("%.6lf\n", s);
    // // 边长等于原边长的 √2/2 倍
    // double x;
    // printf("请输入正方形 A1 的边长 x (x > 1): ");
    // scanf("%lf", &x);
    //
    // if (x <= 1)
    // {
    //     printf("边长必须大于 1！\n");
    //     return 1;
    // }
    //
    // double side = x; // 当前正方形的边长
    // int i;
    // // 从 A1 到 A10，一共需要内接 9 次
    // for (i = 1; i <= 9; i++)
    // {
    //     // 每次内接，边长变为原来的 √2/2 倍
    //     side = side * sqrt(2) / 2;
    // }
    //
    // double area = side * side; // 计算 A10 的面积
    // printf("正方形 A10 的面积为: %.4f\n", area);*/

    /*printf("%d\n", !!5);
    int x = 4, y = 3;
    y = x < 0 && x++ > 3;
    printf("(%d,%d)\n", x, y);*/

    /*char *s1 = "ABCDE", *s2 = "ABCD";
    printf("%d\n", strlen(strcat(s1, s2)));*/

    /*float x = 456.789123;
    printf("%f\n", (int)(x * 100 + 0.5) / 100.0); // 456.790000
    */

    /*int p = 3, q = 4;
    int result = (p += 3, q *= 2, p + q);
    printf("%d\n", result);
    */

    /*int a = 2;
    int b = (a = a + 3, (a = a * 2, a - 2), a + 4);
    printf("%d\n", b);*/

    /*int x = 8, y = 6, z = 4, t = 66;
    if (y < x && x < z)
    {
        t = x;
        x = z;
    }
    z = t;
    if (x < z && y < z) t = y;
    y = x;
    x = t;
    printf("%d%d%d\n", x, y, z); // 6866*/

    /*// \v：垂直制表符（ASCII 11）
    //
    // \b：退格符（ASCII 8）
    //
    // \x32：十六进制转义，对应 ASCII 50，即字符 '2'
    //
    // \123：八进制转义，对应 ASCII 83，即字符 'S'
    //
    // \n：换行符（ASCII 10）
    //
    // \"：双引号（ASCII 34）
    char str[] = "\v\b\x32\123\n\"";
    printf("%d\n", strlen(str));
    */

    /*
    int x = 4, y = -2, z = 88;
    if (x < y)
        // if (y < 0)
        // {
        //     z = 10;
        // }
        // else
        // {
        //     z -= 2;
        // }
        // switch (x)
        // {
        // case 4:
        //     z = 10;
        //     break;
        // case 5:
        //     z = 20;
        //     break;
        // default:
        //     z -= 2;
        //     break;
        // }
    // printf("%d\n", z);*/

    /*char s[80], *sp = "WORLD!";
    sp = strcpy(s, sp);
    s[0] = 'w';
    puts(sp);*/

    /*
     *printf("%ld\n", fib(4));
     *
     */

    /*
     *printf("%d\n", EOF); // -1
    */

    /*
    // 20.
    short p = 25;
    printf("%d\n", ~p);
    */

    /*
    // 21.
    short m = 22, n = 9;
    printf("%d\n", m ^ n);
    */

    /* 
    // 22.
    short a = 10;
    printf("%d\n", a << 2);
    */

    /* 
    // 23.
    int b = 48;
    printf("%d\n", b >> 3);
    */

    /* 
    // 24.
    int x = 24, y = 10;
    printf("%d\n", (x & y) | ((x ^ y) >> 1));
    */

    /* 
    // 25.
    int m = 30, n = 12;
    printf("%d\n", (m | n) & ~(m & n));
    */

    /* 
    // 26.
    int p = 20, q = 8;
    printf("%d\n", (p << 1) ^ (q >> 2));
    */

    /* 
    // 27.
    int m = 034, n = 056;
    printf("%d\n", (m | n) & ~(m & n));
    */

    /*// 磁盘文件 d1 和 d2，各自存放一个已按字母顺序排好的字符串，编程合并二个文件
    // 到 d3 文件中，合并后仍保持字母顺序（如 d1 中存放："accel"，d2 中存放"ilrz"，则 d3 中
    // 为"acceillrz"）
    FILE* f1 = fopen("d1.txt", "r");
    FILE* f2 = fopen("d2.txt", "r");
    FILE* f3 = fopen("d3.txt", "w");
    if (!f1 || !f2 || !f3)
    {
        perror("文件打开失败");
        return -1;
    }

    char ch1, ch2;
    ch1 = fgetc(f1);
    ch2 = fgetc(f2);
    while (ch1 != EOF && ch2 != EOF)
    {
        if (ch1 <= ch2)
        {
            fputc(ch1, f3);
            ch1 = fgetc(f1);
        }
        else
        {
            fputc(ch2, f3);
            ch2 = fgetc(f2);
        }
    }
    // 剩余字符
    while (ch1 != EOF)
    {
        fputc(ch1, f3);
        ch1 = fgetc(f1);
    }
    while (ch2 != EOF)
    {
        fputc(ch2, f3);
        ch2 = fgetc(f2);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);*/

    /*Node n1 = {1, NULL}, n2 = {2, NULL}, n3 = {3, NULL};
    n1.next = &n2;
    n2.next = &n3;
    Node* t = &n1;
    while (t != NULL)
    {
        printf("%d\n", t->val);
        t = t->next;
    }
    printf("逆置后：\n");
    Node *p, *q, *r;
    p = &n1;
    q = p->next;
    p->next = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    Node* t2 = p;
    while (t2 != NULL)
    {
        printf("%d\n", t2->val);
        t2 = t2->next;
    }*/

    /*
    Node
        head = {},
        n1 = {1, NULL},
        n2 = {1, NULL},
        n3 = {3, NULL},
        n4 = {4, NULL},
        n5 = {4, NULL},
        n6 = {6, NULL},
        n7 = {8, NULL},
        n8 = {8, NULL};
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    printLink(&head);
    distinctNode(&head);
    printLink(&head);
    */




    return 0;
}
