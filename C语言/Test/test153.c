#include <stdio.h>
int main()
{
	int s = 0, n = 5;
	while (--n) s += n;
	printf("%d %d\n", s, n);
	return 0;
}
