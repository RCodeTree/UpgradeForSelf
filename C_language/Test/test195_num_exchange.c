#include <stdio.h>

int main()
{
	int a[5] = {0}, mai = 0, mii = 0, tmp;
	for (int i = 0; i < 5; i++) 
	{
		scanf("%d", &a[i]);
		if (a[i] > a[mai]) { mai = i;}
		if (a[i] < a[mii]) { mii = i;}
	}
	for (int i = 0; i < 5; i++) printf("%d ", a[i]);
	printf("\n");
	tmp = a[0];
	a[0] = a[mii];
	a[mii] = tmp;
	tmp = a[4];
	a[4] = a[mai];
	a[mai] = tmp;
	for (int i = 0; i < 5; i++) printf("%d ", a[i]);
	return 0;
}

