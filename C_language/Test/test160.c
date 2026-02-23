#include <stdio.h>

void f(float a, float b, float* c)
{
	static float x;
	float y;
	x = (y = a > b ? a : b) > x ? y :x;
	*c = x;
}

int main()
{
	float a[5] = {2.5, -1.5, 7.5, 4.5, 6.5}, x;
	for (int i = 0; i < 4; i++)
	{
		f(a[i], a[i + 1], &x);
		printf("%.1f\n", x);
	}
	return 0;
}
