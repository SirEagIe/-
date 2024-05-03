#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int searchPoint(int* arr, int size);

int main()
{
    srand(time(0));
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("Введите количество точек\n");
    scanf("%d", &n);
    n *= 2;
    int *a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("Ошибка распределения памяти\n");
        exit(1);
    }
    for(int i = 0; i < n; i++)
        a[i] = rand()%21 - 10;
    printf("Данные точки: \n");
    for(int i = 0; i < n; i += 2)
        printf("(%d , %d)  ", a[i], a[i + 1]);
    int numResultPoint = searchPoint(a, n);
    printf("\nТочка с минимальным расстоянием до остальных точек - (%d , %d)\n", a[numResultPoint], a[numResultPoint + 1]);
    free(a);
    return 0;
}

int searchPoint(int* a, int size)
{
    double sum, minSum, distance, result;
    for(int i = 0; i < size; i += 2)
    {
        sum = 0;
        for(int j = 0; j < size; j += 2)
        {
            if(i == j)
                continue;
            distance = sqrt((a[i] - a[j])*(a[i] - a[j]) + (a[i + 1] - a[j + 1])*(a[i + 1] - a[j + 1]));
            sum += distance;
        }
        printf("\nСумма расстояний от %d-й точки до остальных - %.2lf", (i+2)/2, sum);
        if(sum < minSum || i == 0)
        {
            minSum = sum;
            result = i;
        }
    }
    return result;
}
