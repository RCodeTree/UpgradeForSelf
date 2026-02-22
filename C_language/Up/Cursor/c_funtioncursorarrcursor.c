#include <stdio.h>
int func1(int a)
{
	printf("func1: %d\n", a);
}

int func2(int a)
{
	printf("func2: %d\n", a);
}

int main()
{
	int (*pfarr[])(int) = {func1, func2};
	int (*(*pfarrp)[2])(int) = &pfarr;
	for(int i = 0; i < 2; i++)
	{
		(*pfarrp)[i](i); 
        /* 
        result:
        func1: 0
        func2: 1
        */
	}
	return 0;
}