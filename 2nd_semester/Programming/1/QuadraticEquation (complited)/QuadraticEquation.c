#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c;
	printf("Enter the first parameter: ");
	scanf("%f", &a);								// ввод первого параметра
	printf("Enter the second parameter: ");
	scanf("%f", &b); 							    // ввод второго параметра
	printf("Enter the third parameter: ");
	scanf("%f", &c);                                // ввод третьего параметра
	float D = b*b-4*a*c; 							// вычисление дискриминанта
	printf("D = %.2f\n", D);						// вывод дискриминанта
	if (D < 0)										// дискриминант меньше нуля
		printf("No solutions");						// нет корней
	if (D == 0)										// дискриминант равен нулю
	{
		float x = (-b+sqrtf(D)/2*a);
		printf("x = %.2f\n", x);					// вывод одного корня
	}
	if (D > 0)										// дискриминант больше нуля
	{
		float x1 = (-b+sqrtf(D)/2*a);
		float x2 = (-b-sqrtf(D)/2*a);
		printf("x1 = %.2f\nx2 = %.2f\n", x1, x2); 	// вывод двух корней
	}
	return 0;
}