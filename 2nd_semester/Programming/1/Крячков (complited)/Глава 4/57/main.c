#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int nonIncreasingSequence(int* arr, int size);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("¬ведите длину массива\n");
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("ќшибка распределени€ пам€ти\n");
        exit(1);
    }
    printf("¬ведите элементы массива\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int result = nonIncreasingSequence(a, n);
    if(result == NULL)
        printf("Ёлементы массива образуют неубывающую последовательность\n");
    else
        printf("Ёлементы массива не образуют неубывающую последовательность, элемент, на котором нарушаетс€ условие, - %d", result);
    free(a);
    return 0;
}

int nonIncreasingSequence(int* arr, int size)
{
    int result = NULL;
    for(int i = 1; i < size; i++)
        if(arr[i - 1] > arr[i])
            result = i + 1;
    return result;
}
