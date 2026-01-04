#include <stdio.h>
#include <string.h>
int main()
{
	char a[3][20] = {{"china"}, {"isa"}, {"bigcountry!"}};
	char k[100] = {0}, *p = k;
	int i;
	for (i = 0; i < 3; i++)
	{
		p = strcat(p, a[i]);
	}
	i = strlen(p);
	printf("%d\n", i);
	return 0;
}
