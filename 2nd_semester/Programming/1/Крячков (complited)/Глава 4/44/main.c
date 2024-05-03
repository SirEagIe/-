#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int saddlePoint(int** arr, int n, int m);

int main()
{
    srand(time(0));
    setlocale(LC_CTYPE, "rus");
    int nrow, ncol;
    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d%d", &nrow, &ncol);
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
    {
        for(int j = 0; j < ncol; j++)
            arr[i][j] = rand()%11;
    }
    printf("Элементы матрицы равны\n");
    for(int i = 0; i < nrow; i++)
    {
        for(int j = 0; j < ncol; j++)
            printf("%4d ", arr[i][j]);
            printf("%\n");
    }
    saddlePoint(arr, nrow, ncol);
    for(int i = 0; i < nrow; i++)
        free(arr[i]);
    free(arr);
    return 0;
}

int saddlePoint(int** arr, int n, int m)
{
    int numRow1, numRow2, numCol1, numCol2, minRow, maxCol, sPnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] < minRow || j == 0)
            {
                minRow = arr[i][j];
                numRow1 = i;
                numCol1 = j;
            }
        }
        for(int k = 0; k < n; k++)
        {
            if(arr[k][numCol1] > maxCol || k == 0)
            {
                maxCol = arr[k][numCol1];
                numRow2 = k;
                numCol2 = numCol1;
            }
        }
        if(numRow1 == numRow2 && numCol1 == numCol2)
        {
            printf("Элемент в %d-й строке, %d-м столбце является седловым\n", numRow1 + 1, numCol1 + 1);
            sPnt = 1;
        }
    }
    if(sPnt == 0)
        printf("В матрице нет седловых элементов\n");
}
