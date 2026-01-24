#include <stdio.h>
int main( )
{
	float r, h, cl, cs, cvz;
	scanf("%f %f", &r, &h);
	
	cl = 2 * 3.14159 * r;
	cs = 3.14159 * r * r;
	cvz = 3.14159 * r * r * h;

	printf("圆的周长：%6.2f，面积：%6.2f\n", cl, cs);
	printf("圆的体积：%6.2f\n", cvz);

	return 0;
}
