#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int nrow, ncol;
    printf("������� ���������� ����� � �������� �������\n");
    scanf("%d%d",&nrow, &ncol);
    int **arr = (int**)malloc(nrow * sizeof(int*));
    if(arr == NULL)
    {
        printf("������ ��������� ������\n");
        exit(1);
    }
    for(int i = 0; i < nrow; i++)
        arr[i] = (int*)malloc(ncol * sizeof(int));
    for(int i = 0; i < nrow; i++)
    {
        if(arr[i] == NULL)
        {
            printf("������ ��������� ������\n");
            exit(1);
        }
    }

    for(int i = 0; i < nrow; i++)
        for(int j = 0; j < ncol; j++)
            arr[i][j] = rand()%100 - 50;
    printf("�������� ������� �����:\n");
    for(int i = 0; i < nrow; i++)
    {
        for(int j = 0; j < ncol; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    int *sum = (int*)malloc(ncol * sizeof(int));
    if(sum == NULL)
    {
        printf("������ ��������� ������\n");
        exit(1);
    }
    for(int i = 0; i < ncol; i++)
    {
        sum[i] = 0;
        for(int j = 0; j < nrow; j++)
            sum[i] += arr[j][i];
    }
    printf("����� ����� �������:\n");
    for(int i = 0; i < nrow; i++)
        printf("%4d ", sum[i]);
    long buf_sum;
    int nmax, buf_a;
    for(int i = 0; i < nrow - 1; i++)
    {
        nmax = i;
        for(int j = i + 1; j < ncol; j++)
            if(sum[j] > sum[nmax]) nmax = j;
        buf_sum = sum[i];
        sum[i] = sum[nmax];
        sum[nmax] = buf_sum;
        for(int j = 0; j < nrow; j++)
        {
            buf_a = arr[j][i];
            arr[j][i] = arr[j][nmax];
            arr[j][nmax] = buf_a;
        }
    }
    printf("\n�������� �������������� �������:\n");
    for(int i = 0; i < nrow; i++)
    {
        for(int j = 0; j < ncol; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    printf("����� ����� �������������� �������:\n");
    for(int i = 0; i < nrow; i++)
        printf("%4d ", sum[i]);
    for(int i = 0; i < nrow; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
