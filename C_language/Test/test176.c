#include <stdio.h>

double sum(double* a, double x, int n)
{
	double a0 = a[0];
	double m = 1, ax = 1, s = 0 + a0;
	for (int i = 1; i <= n; i++)
	{
		m *= x;
		ax = a[i] * m;
		s += ax;
	}
	return s;
}

int main()
{
	double a[3] = {3, 7, 11};
	double x = 2;
	int n = sizeof(a) /sizeof(a[0]);
	double s = sum(a, x, n);
	printf("%lf\n", s);
	return 0;
}
