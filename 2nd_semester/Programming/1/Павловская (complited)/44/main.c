#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int n;
    printf("Введите размер квадратной матрицы\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n * n * sizeof(int));
    if(arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    for(int i = 0; i < n*n; i++)        //9 6 1 3 0 5 2 5 10 -5 1 -2 12 3 9 -1 8 -4 -1 0 9 0 8 4 13
        scanf("%d", arr + i);
    printf("Элементы массива равны:\n");
    for(int i = 0; i < n*n; i++)
    {
        printf("%4d ", *(arr + i));
        if((i+1) % n == 0 && i != 0)
            printf("\n");
    }
    int rowSum = 0;
    int all_posit = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((*(arr + i*n + j)) < 0)
            {
                all_posit = 0;
                break;
            }
            rowSum += (*(arr + i*n + j));
        }
        if(all_posit)
            printf("Сумма %dй строки = %d\n", i + 1, rowSum);
        else
            printf("%dя строка содержит отрицательные числа\n", i + 1);
        all_posit = 1;
        rowSum = 0;
    }
    int dSum = 0;
    int mindSum = 0;
    int el;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            el = *(arr + i + (n - 1)*j);
            dSum += (int)fabs(el);
        }
        if(dSum < mindSum || i == 0)
            mindSum = dSum;
        //printf("Сумма %dй диагонали = %d\n", i + 1, dSum);
        dSum = 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            el = *(arr + (n*n - (i + 1)) - (n - 1)*j);
            dSum += (int)fabs(el);
        }
        if(dSum < mindSum)
            mindSum = dSum;
        //printf("Сумма %dй диагонали = %d\n", (n*n - (i + 1)), dSum);
        dSum = 0;
    }
    printf("Минимум среди сумм модулей элементов диагоналей, параллельных побочной = %d\n", mindSum);
    free(arr);
    return 0;
}
