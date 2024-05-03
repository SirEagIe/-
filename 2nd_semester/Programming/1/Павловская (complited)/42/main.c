#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int n, m;
    printf("������� ���������� ����� � �������� �������\n");
    scanf("%d%d",&n, &m);
    int i, j;
    int **arr = (int**)malloc(n * sizeof(int*));
    if(arr == NULL)
    {
        printf("������ ��������� ������\n");
        exit(1);
    }
    for(int i = 0; i < n; i++)
        arr[i] = (int*)malloc(m * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == NULL)
        {
            printf("������ ��������� ������\n");
            exit(1);
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = rand()%100 - 30;
    printf("�������� ������� �����:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    int num = -1;
    int all_posit;
    for(j = 0; j < m; j++)
    {
        all_posit = 1;
        for(i = 0; i < n; i++)
            if(arr[i][j] < 0)
            {
                all_posit = 0;
                break;
            }
        if(all_posit)
        {
            num = j;
            break;
        }
    }
    if(-1 == num)
        printf("�������� ���\n");
    else
        printf("����� �������: %d\n", num+1);
    for(int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
