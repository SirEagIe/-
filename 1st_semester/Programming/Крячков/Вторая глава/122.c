#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int N, M, znak;
    printf("Введите числа N, M, N <= M, M < 13\n");
    scanf("%d%d", &N, &M);
    int B[N][M];
    int D[M];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            B[i][j] = rand()%1000;
            znak = rand();
            if(znak % 2 == 0)
                B[i][j] *= -1;
        }
    }
    printf("Элементы матрицы равны:\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            printf("%6d ", B[i][j]);
            printf("\n");
    }
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(j == 0)
                D[i] = 0;
            D[i] += B[j][i];
        }
    }
    printf("Суммы элементов столбцов матрицы равны\n");
    for(int i = 0; i < M; i++)
        printf("%6d ", D[i]);
    return 0;
}
