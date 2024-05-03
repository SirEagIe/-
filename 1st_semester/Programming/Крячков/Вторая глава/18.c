#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int k, result = 0;
    printf("Введите k < 20\n");
    scanf("%d", &k);
    int matrix[k][k];
    for(int i = 0; i < k; i++)
    {
        printf("Введите элементы %d-й строки матрицы\n", i+1);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Матрица равна: \n");
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
            printf("%3d ", matrix[i][j]);
            printf("\n");
    }
    for(int d = 0; d < k; d++)
        result += matrix[d][k-d-1];
    printf("Сумма элементов на диагонали, ортогональной главной, равна %d", result);
    return 0;
}
