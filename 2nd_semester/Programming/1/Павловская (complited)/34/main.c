#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    float max, result, a, b;
    printf("Введите размер массива\n");
    scanf("%d", &n);
    float arr[n];
    randomArray(arr, n);
    printf("Элементы массива равны:\n");
    printArray(arr, n);
    for(int i = 0; i < n; i++)
        if(arr[i] > max || i == 0)
            max = arr[i];
    printf("Максимальный элемент массива равен %.2f\n", max);
    int flag = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(flag == 1)
            result += arr[i];
        if(arr[i] > 0 && flag == 0)
            flag = 1;
    }
    printf("Сумма элементов массива, расположенных до последнего положительного элемента равна %.2f\n", result);
    printf("Введите границы интервала [a, b]\n");
    scanf("%f%f", &a, &b);
    for(int i = 0; i < n; i++)
        if(fabs(arr[i]) >= a && fabs(arr[i]) <= b)
            arr[i] = 0;
    printf("Массив после сжатия:\n");
    printArray(arr, n);
    return 0;
}

void randomArray(float *arr, int size)            //заполнение массива случайными элементами
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        arr[i] = (-10000 + rand()%20000)/100.;
    }
}

void usersArray(float *arr, int size)             //пользовательский ввод массива
{
    for(int i = 0; i < size; i++)
    {
        scanf("%f", &arr[i]);
    }
}

void printArray(float *arr, int size)             //вывести значения элементов массива
{
    for(int i = 0; i < size; i++)
    {
        printf("%7.2f ", arr[i]);
    }
    printf("\n");
}
