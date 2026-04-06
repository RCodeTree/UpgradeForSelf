#include <stdio.h>
#include <string.h>
#include <math.h>

int getNum(char* s)
{
	int l = strlen(s);
	int n = l - 1;
	double r = 0.0;
	while (n)
	{
		r += pow(8, n) * (*s - '0');
		s++;
		n--;
	}
	r += (*s - '0');
	return (int) r;
}

int main()
{
	char* s = "556";
	int r = getNum(s);
	printf("%d\n", r);
	return 0;
}
