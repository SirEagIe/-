#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int Y[150], min = RAND_MAX;
    int temp;
    for(int i = 0; i < 150; i++)
    {
        temp = rand();
        Y[i] = temp;
        if(temp % 2 == 0)
            Y[i] *= -1;
    }
    printf("Элементы массива равны:\n");
    for(int i = 1; i < 151; i++)
    {
        printf("%9d ", Y[i]);
        if(i%10 == 0)
            printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 150; i++)
    {
        if(Y[i] > 0 && Y[i] < min)// && min2 > min1)
        {
            min = Y[i];
        }
    }
    printf("Минимальное положительное число в массиве равно %d\n", min);
    return 0;
}
