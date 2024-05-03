#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int n;
    printf("Введите размер квадратной матрицы\n");
    scanf("%d",&n);
    int **arr = (int**)malloc(n * sizeof(int*));
    if(arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    for(int i = 0; i < n; i++)
        arr[i] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == NULL)
        {
            printf("Ошибка выделения памяти\n");
            exit(1);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); //2 -4 -7 7 0 7 7 -7 -10 -8 -1 7 5 8 -5 -7 7 -10 -8 0 -2 -6 -4 -10 -4
    printf("Элементы массива равны:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    int kolRow = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0)
            {
                kolRow++;
                break;
            }
        }
    }
    printf("Количество строк, содержащий хотя бы один нулевой элемент - %d\n", kolRow);
    int col;
    int maxSeria = 1;
    int maxRowSeria = 1;
    int seria = 1;
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int k = i + 1; k < n; k++)
            {
                if(arr[i][j] == arr[k][j])
                    seria++;
                else
                    break;
            }
            if(seria > maxRowSeria)
            {
                maxRowSeria = seria;
            }
            seria = 1;
        }
        if(maxRowSeria > maxSeria)
            {
                maxSeria = maxRowSeria;
                col = j + 1;
            }
            maxRowSeria = 1;
    }
    printf("\Максимальная серия из одинаковых элементов = %d в столбце %d\n", maxSeria, col);
    for(int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
