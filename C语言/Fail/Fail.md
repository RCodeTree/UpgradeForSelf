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


