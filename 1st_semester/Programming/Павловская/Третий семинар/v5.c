#include <stdio.h>
#include <stdlib.h>
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
    printf("Введите элементы массива\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("Элементы массива равны:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%7.2f ", arr[i]);
    }
    printf("\n");
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
    for(int i = 0; i < n; i++)
    {
        printf("%7.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
