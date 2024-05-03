#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int A[85], max = -20;
    for(int i = 0; i < 85; i++)
    {
        A[i] = rand() % 31 - 20;
    }
    printf("Элементы массива равны:\n");
    for(int i = 0; i < 85; i++)
    {
        if(i%10 == 0 && i != 0)
            printf("\n");
        printf("%9d ", A[i]);
    }
    for(int i = 0; i < 85; i++)
    {
        if(A[i] < 0 && A[i] > max)
        {
            max = A[i];
        }
    }
    printf("\nМаксимальное отрицательное число в массиве равно %d\n", max);
    return 0;
}
