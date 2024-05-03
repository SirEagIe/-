#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int n_posit(const int *a, const int n);

int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("Ошибка распределения памяти!\n");
        exit(1);
    }
    int *b = (int*)malloc(n*sizeof(int));
    if(b == NULL)
    {
        printf("Ошибка распределения памяти!\n");
        exit(1);
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = rand()%21 - 10;
        b[i] = rand()%21 - 10;
    }
    printf("Элементы первого массива равны: \n");
    for(int i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
    printf("Элементы первого массива равны: \n");
    for(int i = 0; i < n; i++)
        printf("%4d", b[i]);
    printf("\n");
    if(n_posit(a, n) > n_posit(b, n))
    {
        printf("В первом массиве положительных элементов больше\n");
    }
    if(n_posit(a, n) < n_posit(b, n))
    {
        printf("Во втором массиве положительных элементов больше\n");
    }
    if(n_posit(a, n) == n_posit(b, n))
    {
        printf("В массивах одинаковое количество положительных элементов\n");
    }
    free(a);
    free(b);
    return 0;
}

int n_posit(const int* a, const int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > 0)
            count++;
    return count;
}
