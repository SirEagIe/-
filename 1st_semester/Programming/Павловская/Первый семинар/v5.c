#include <stdio.h>
#include <math.h>
int main()
{
	float a, z1, z2;
	printf("Enter a: ");
	scanf("%f", &a);
	z1 = 1 - 0.25 * pow(sin(2*a*M_PI/180), 2) + cos(2*a*M_PI/180);
	z2 = pow(cos(a*M_PI/180), 2) + pow(cos(a*M_PI/180), 4);
	printf("z1 = %f\nz2 = %f", z1, z2);
	return 0;
}
