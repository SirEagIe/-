#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int searchInv(float* arr, int size);

int main()
{
    srand(time(0));
	setlocale(LC_CTYPE, "rus");
	int n;
	printf("Введите длину массива\n");
	scanf("%d", &n);
	float* x = (float*)malloc(n * sizeof(float));
	if(x == NULL)
	{
		printf("Ошибка распеделения памяти\n");
		exit(1);
	}
	for(int i = 0; i < n; i++)
		x[i] = (float)(rand()%200 - 100)/10.;
	printf("Элементы массива равны \n");
	for(int i = 0; i < n; i++)
		printf("%7.2lf", x[i]);
	printf("\nКоличество инверсий в массиве - %d", searchInv(x, n));
	free(x);
	return 0;
}

int searchInv(float* arr, int size)
{
	int result = 0;
	for(int i = 1; i < size; i++)
    {
        if(arr[i] > arr[i - 1])
            result++;
    }
	return result;
}
