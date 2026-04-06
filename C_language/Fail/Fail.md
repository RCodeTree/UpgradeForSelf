设有宏定义命令：#define RES 30-5 则表达式 RES*5+30 的值为____.
```c 
#include <stdio.h>
#define RES 30-5
int main()
{
    /* 
    解析：
    宏 RES 展开为文本 30-5
    因此表达式是 30 - 5*5 + 30 = 35 （乘法优先于加减）
    */
    printf("%d\n",RES*5+30);
    return 0;
}
```


若有宏定义：#define Test(y)y*y，则表达式 Test(4-2)的值为____.
```c
#include <stdio.h>
#define Test(y)y*y
int main()
{
    /* 
    解析：
    宏 Test(y) 展开为文本 y*y
    因此表达式是 4-2*4-2 = 4-8-2 = -6 （括号优先于加减）
    */
    printf("%d\n",Test(4-2));
    return 0;
}
```


字符串”boy\0s”在内存中占用的字节数是____.
```c
#include <stdio.h>
int main()
{
     /* 
    解析：
    字符串”boy\0s”在内存中占用的字节数是 6 （包括结束符 \0）
    */
    printf("%d\n",sizeof("boy\0s")); // 6
    return 0;
}
```

设 a，b，c 均为 int 型变量，则执行语句 a=b=3;c=++a||++b;后，b 的值为_______.
```c
#include <stdio.h>
int main()
{
    /* 
    解析：
    语句 a=b=3; 给 a，b 赋值为 3
    语句 c=++a||++b; 先对 a 进行自增，由于 a 为 4，非 0，因此 || 后面的表达式不执行，c 赋值为 1
    因此 b 的值为 3
    */
    int a,b,c;
    a=b=3;
    c=++a||++b;
    printf("%d\n",b); // 3
    printf("%d\n",c); // 1
    return 0;
}
```


设 x，y，z，t 均为 int 型变量，则执行以下语句 x=y=z=1;t=++x||++y&&++z; 后，t 的值为________.
```c
#include <stdio.h>
int main()
{
    /* 
    解析：
    && 的优先级高于 ||
    语句 x=y=z=1; 给 x，y，z 赋值为 1
    语句 t=++x||++y&&++z; 先对 x 进行自增，由于 x 为 2，非 0，因此 || 后面的表达式不执行，t 赋值为 1
    因此 t 的值为 1
    */
    int x,y,z,t;
    x=y=z=1;
    t=++x||++y&&++z;
    printf("%d\n",t); // 1
    return 0;
}
```

printf("s=%-5.3s","student");的输出结果是____.
```c
#include <stdio.h>
int main()
{
    /* 
    解析：
    格式化输出字符串 s=%-5.3s
    字符串”student”的前 3 个字符是 stu
    - 表示左对齐
    5 表示输出宽度为 5
    .3 表示输出 3 个字符
    因此输出结果是 stu
    */
    printf("s=%-5.3s","student"); // stu
    return 0;
}
```

``` c
// 结果：6
#include <stdio.h>
int main()
{
        int m = 5;
        if(m++ > 5)
                printf("%d\n", m);
        else
                printf("%d\n", m--);
        return 0;
}
```


``` 
以下不正确的 if 语句形式是____。
A)if (x>y&&x!=y);
B)if (x==y) x+=y;
C)if(x!=y) scanf("%d",&x) else scanf("%d",&y);
D)if(x<y) {x++;y++;}
```


```
在 C 语言中，表示逻辑“真”值用_______
```


以下程序的运行结果是_______ 。
``` c
#include <stdio.h>
int main()
{
    int x,y,z;
    x=1;y=2;z=3;
    x=y--<=x||x+y!=z;
    printf("%d,%d",x,y); // 1,1
    return 0;
}
```


``` c
#include <stdio.h>
int main()
{
	int a = 10, b = 10, i;
	for(i = 0; a > 8; b = ++i)
		printf("%d %d ", a--, b); // 10 10 9 1
	return 0;
}
```


``` c
#include <stdio.h>
void main()
{ 
    int k;
    for(k=0;k<10;k++);
    printf("%d",k); // 10
}
```


``` c
#include <stdio.h>
int main()
{
    int m;
    for(m=1;m<=50;m++)
    {
        if(m%12!=0)
            continue;
        printf("%4d",m); // 空格空格12空格空格24空格空格36空格空格48
    }
    printf("\n");

    return 0;
}
```


```
输入一个正整数 m，计算 2-4+6-8+10-12+⋯ 的前 m 项之和。
```


```
求 Fibonacci 数列前 12 项的和。
```

```
输出以下三角形：
    *
   ***
  *****
 *******
*********
```


**有已排好序的字符串 a，下面的程序是将字符串 s 中的每个字符按升序的规律插入到 a 中。
请选择填空。（ ）（ ）**
``` c
/* 
关键点：
一、查找插入位置
二、将插入位置后面的字符后移一位

结论：
- 用 i = strlen(a) 从“当前字符串末尾的 \0 位置”开始右移是正确的；用 strlen(a)-1 会漏掉终止符，导致字符串不再以 \0 结尾。
原因

- strlen(a) 返回的是字符个数，不含 \0 。因此“ \0 的下标”正好是 strlen(a) 。

- 插入前，需要把区间 [j, strlen(a)] 的所有元素整体右移一位，包含 \0 本身：
  - 循环初值 i = strlen(a) ，先做 a[i+1] = a[i] ，把 \0 移到新末尾，字符串长度自动+1且仍有效；
  - 然后继续 i-- ，将 a[i] 逐个搬到 a[i+1] ，直到 i == j 。

- 若从 strlen(a)-1 开始，只会移动最后一个可见字符，不会移动 \0 ，结果尾部仍旧在旧位置，插入后字符串变成“无终止符”的未定义状态，需要额外手动补 a[len+1] = '\0' ，这不是本题的写法。
*/
#include<stdio.h>
main()
{
    char a[20]="cehiknqtw";
    char s[]="fbla";
    int i,k,j;
    for(k=0;s[k]!='\0';k++)
    {
    j=0;
    while(s[k]>=a[j]&&a[j]!='\0') j++;
    for(【1】) 【2】;
    a[j]=s[k];
    }
puts(a);
}

/* 
【1】
A)i=strlen(a)+k;i>=j;i--    B)i=strlen(a);i>=j;i-- 
C)i=j;i<=strlen(a)+k;i++    D)i=j;i<=strlen(a);i++

【2】
A)a[i]=a[i+1]   B)a[i+1]=a[i]
C)a[i]=a[i-1]   D)a[i-1]=a[i] 

答案：【1】B  【2】B
*/
```


**下面程序的功能是将已按升序排好序的两个字符串 a 和 b 中的字符,按升序归并到字符串
c 中。请分析程序填空。（ ）（ ）（ ）**
``` c
#include "stdio.h" 
/* 
归并排序的要点是将两个数组 a 和 b 的下标逐次后移，存放的是那个数组的元素，就移动那个数组的下标，而目标数组 c 则每次循环都要移动。当 a、b 数组其中一个到达结束标志后，再将没到达结束标志的数组中剩余的数据全部写到 c 中。
*/
/* 
- 前面循环合并公共部分： while (a[i] != '\0' && b[j] != '\0') 将更小字符放入 c ，并推进 i/j 与 k 
- 循环退出时，说明两个串中有一个已到末尾：
- 若 a[i] == '\0' ，则 a 已用完， b 还有剩余；令 p = b + j 
- 否则 b[j] == '\0' ， b 用完， a 还有剩余；令 p = a + i 
- 之后 strcat(c, p) 将从当前指针开始的“剩余尾段”一次性追加到 c 

- p 是 char* 指针，不是 char 。 p=b+j 与 p=a+i 把 p 指向某个字符串的当前位置。
- b+j 是指向 b[j] 的地址，等价于 &b[j] ；同理 a+i 是 &a[i] 。它们指向“剩余子串”的起始位置，不是单个字符
*/
main()
{
    char a[]="acegikm";
    char b[]="bdfhjlnpq";
    char c[80],*p;
    int i=0,j=0,k=0;
    while (a[i]!='\0'&&b[j]!='\0')
    {
        if (a[i]<b[j]) {【1】}
        else {【2】};
        k++;
    }
    c[k]='\0';
    if (【3】) p=b+j;
    else p=a+i;
    strcat(c,p);
    puts(c);
}
/* 
【1】【2】
A)c[k]=a[i];i++     B)c[k]=b[j];i++
C)c[k]=a[i];j++     D)c[k]=b[j];j++
【3】
A)a[i]=='\0'    B)a[i]!='\0' 
C)a[i-1]=='\0'  D)a[i-1]!='\0' 
*/
```



**下面程序的功能是将字符串 s 中所有的字符'c'删除。（ ）**
``` c
/* 
关键点：
删除指定字符的程序要点在于采用双下标，
一、一个下标对数组从头到尾进行逐个扫描，
二、另外一个下标则只有当写入不删除字符时才向后移动。其关键思想就是：s[j++]=s[i]。
*/
#include "stdio.h" 
main()
{  
    char s[80];
    int i,j;
    gets(s);
    for (i=j=0;s[i]!='\0';i++)
        if (s[i]!='c')_____;
        s[j]='\0';
    puts(s);
}
/* 
A)s[j++]=s[i]   B)s[++j]=s[i] 
C)s[j]=s[i];j++   D)s[j]=s[i] 
*/
```


**下面程序的功能是从键盘输入一行字符，统计其中有多少个单词，单词之间用空格分隔。请分析程序填空。（ ）**
``` c
/*
 判断是不是一个单词的要点就是当前字符不是空格而前一个字符是空格。
*/
Apple pen orange\0
#include<stdio.h>
main()
{
    char s[80],c1,c2=' ';
    int i=0,num=0;
    gets(s);
    while(s[i]!='\0')
    {
        c1=s[i];
        if(_____) num++;
        i++;
        c2=c1;
    }
    printf("There are %d words.\n",num);
}
/* 
A)c1==' '&&c2==' '  B)c1!=' '&&c2==' ' 
C)c1==' '&&c2!=' '  D)c1!=' '&&c2!=' '
*/ 
```
**当运行以下程序时，从键盘输入 ab<CR>c<CR>def<CR>，则下面程序的运行结果是（ ）**
``` c
#include<stdio.h>
#define N 6
main()
{
    char c[N];int i=0;
    for(;i<N;c[i]=getchar(),i++);
    for(i=0;i<N;i++) putchar(c[i]);
}
A)abcdef 

B)ab        C)a         D)ab
  c           c           c
  def         d           d
```





19. 以下程序运行后的输出结果是（ ）。
``` c
int p=2;
main()
{
    int s,j,sum;
    for(j=0;j<=5;j++)
        s=sum(j);
    printf("s=%d\n",s);
}
int sum(int k)
{
    static int x=1;
    int y=1;
    p++;
    y++;
    return x+=k+p+y;
}
```

答案：s=61



20. 程序运行后的输出结果是（ ）。
``` c
#include <string.h>
int a=4;
int i; // 供 f() 使用的全局 i
int f(int n)
{
    int t=0; static int a=5;
    if(n%2){int a=6; t+=a+i;}
    else   {int a=7; t+=a+i;}
    return t+a++;
}
main()
{
    int s=a; i=0;
    for(i=0;i<2;i++) s+=f(i);
    printf("%d\n",s);
}
```

答案：28



22. 输出用 1 元人民币换成 1 分、2 分、5 分的所有兑换方案。（填写循环与条件）
``` c
/* 
变量含义：
- i ：5 分硬币的枚举数量（ 0..20 ），每枚贡献 5*i 分
- j ：2 分硬币的枚举数量（ 0..50 ），每枚贡献 2*j 分
- k ：由 i 、 j 决定的 1 分硬币数量，满足总额约束
- m ：已输出的方案计数，用于每输出 3 个方案后加一个空行

核心等式与约束：
- 金额守恒： 5*i + 2*j + 1*k = 100
- 因此 k = 100 - 5*i - 2*j
- 只要 k >= 0 就是一个有效方案
- 外层循环 i=0..20 保证 5 分硬币不超过 100 分；内层 j=0..50 保证 2 分硬币不超过 100 分，配合 k>=0 过滤掉超额组合
*/
#include <stdio.h>
void main()
{
    int i,j,k,m=0;
    for(i=0;i<=20;i++)
        for(j=0; j<=50; j++)
        {
            k=100-5*i-2*j;
            if(k>=0)
            {
                printf("\n %d %d %d \n",i,j,k);
                m=m+1;
                if(m%3==0)
                    printf("\n");
            }
        }
}
```

答案：第二层循环条件 `j<=50`；判断条件 `k>=0`


已知 int a=5,b=2; 表达式 a%b 的值是____。

答案：1



已知 int a[10]={1,2,3,4,5,6,7,0,9,6}; 最小的元素的下标值是____。

答案：7



使用 TURBO C 系统编译 C 语言源程序后生成的文件名后缀是（_____）。

答案：.obj



若有以下宏定义： #define M(a,b) -a/b ，则执行语句 printf("%d", M(4+3, 2+1)); 后输出结果为（_____）。

答案：-2



有以下程序：
``` c
main()
{
    int a[7]={11,13,14,15,16,17,18}, i=0, j=0;
    while(i<7 && a[i]%2) { j=j+a[i]; i++; }
    printf("%d\n", j);
}
```
执行后输出结果是（_____）。

答案：24



