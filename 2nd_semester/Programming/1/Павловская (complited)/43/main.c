#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int nrow, ncol;
    printf("Введите количество строк и столбцов массива\n");
    scanf("%d%d",&nrow, &ncol);
    int **arr = (int**)malloc(nrow * sizeof(int*));
    if(arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    for(int i = 0; i < nrow; i++)
        arr[i] = (int*)malloc(ncol * sizeof(int));
    for(int i = 0; i < nrow; i++)
    {
        if(arr[i] == NULL)
        {
            printf("Ошибка выделения памяти\n");
            exit(1);
        }
    }

    for(int i = 0; i < nrow; i++)
        for(int j = 0; j < ncol; j++)
            arr[i][j] = rand()%100 - 50;
    printf("Элементы массива равны:\n");
    for(int i = 0; i < nrow; i++)
    {
        for(int j = 0; j < ncol; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    int *sum = (int*)malloc(nrow * sizeof(int));
    if(sum == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    for(int i = 0; i < nrow; i++)
    {
        sum[i] = 0;
        for(int j = 0; j < ncol; j++)
            sum[i] += arr[i][j];
    }
    printf("Суммы строк массива:\n");
    for(int i = 0; i < nrow; i++)
        printf("%4d ", sum[i]);
    long buf_sum;
    int nmin, buf_a;
    for(int i = 0; i < nrow - 1; i++)
    {
        nmin = i;
        for(int j = i + 1; j < nrow; j++)
            if(sum[j] < sum[nmin]) nmin = j;
        buf_sum = sum[i];
        sum[i] = sum[nmin];
        sum[nmin] = buf_sum;
        for(int j = 0; j < ncol; j++)
        {
            buf_a = arr[i][j];
            arr[i][j] = arr[nmin][j];
            arr[nmin][j] = buf_a;
        }
    }
    printf("\nЭлементы упорядоченного массива:\n");
    for(int i = 0; i < nrow; i++)
    {
        for(int j = 0; j < ncol; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    printf("Суммы строк упорядоченного массива:\n");
    for(int i = 0; i < nrow; i++)
        printf("%4d ", sum[i]);
    for(int i = 0; i < nrow; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
