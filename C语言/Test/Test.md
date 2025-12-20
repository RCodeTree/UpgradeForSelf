### 1.实现数组逆序。
``` c
#include <stdio.h>
void fun(int *arr,int n){
    int i,t;
    for(i=0;i<______①______;i++){
        t=arr[i];
        arr[i]=arr[n-1-i];
        ______②______=t;
    }
}

int main(){
    int a[5]={1,2,3,4,5},*p=a,i;
    ______③______;
    for(i=0;i<5;i++)
        printf("%d",a[i]);
    return 0;
}
```


### 2.下面程序的功能是将字符串中从第一个数字字符开始的所有字符复制到另一个字符数组中。例如：输入“abcd12qwer123”，s2数组中保存“12qwer123”。
``` c
#include<stdio.h>
int main() {
    char s1[50],s2[50]={0};
    char *p,*q;
    gets(s1);
    for(p=s1;*p;p++)
        if(*p>='0'&& *p<='9')
            ______①______;
    q=s2;
    while(*p){
        ______②______;
        p++,q++;
    }
    ______③______;
    puts(s2);
    return 0;
}
```





## 1.___________

``` c
#include<stdio.h>
int b;
void f(int a){
    int b=2;
    printf("b=%d",b);
    b=3;
}
void main(){
    int a = 100;
    f(a);
    printf("%d,%d\n",a,b);
}
```

``` c

```