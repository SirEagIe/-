#include <stdio.h>

int main()
{
	float fahr;
	printf("Enter Fahrenheit Temperature: \n");
	scanf("%f", &fahr);
	float cels=(fahr-32)*5/9;
	printf("Fahrenheit: %f, Celsius: %f", fahr, cels);
	return 0;
}