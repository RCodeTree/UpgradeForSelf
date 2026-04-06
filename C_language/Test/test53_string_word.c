#include<stdio.h>
void main()
{
    char s[80],c1,c2=' ';
    int i=0,num=0;
    gets(s);
    while(s[i]!='\0')
    {
        c1=s[i];
        if(c1!=' '&&c2==' ') num++;
        i++;
        c2=c1;
    }
    printf("There are %d words.\n",num);
}
