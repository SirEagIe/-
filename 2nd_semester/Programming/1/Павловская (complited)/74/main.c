#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int ser_equals(int** a, const int m, const int n);

int main()
{
    srand(time(0));
    setlocale(LC_CTYPE, "rus");
     int m, n;
    printf("������� ���������� ����� � �������� �������: ");
    scanf("%d%d", &m, &n);
    int **arr = (int**)malloc(m * sizeof(int*));
    if(arr == NULL)
    {
        printf("������ ��������� ������\n");
        exit(1);
    }
    for(int i = 0; i < m; i++)
        arr[i] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < m; i++)
    {
        if(arr[i] == NULL)
        {
            printf("������ ��������� ������\n");
            exit(1);
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            arr[i][j] = rand()%21;
    }
    printf("�������� ������� �����\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%4d ", arr[i][j]);
            printf("%\n");
    }
    int line = ser_equals(arr, m, n);
    if(line > 0)
        printf("����� ������� ����� � ������ %d\n", line);
    else
        printf("����� ���������� ��������� ���\n");
    for(int i = 0; i < m; i++)
        free(arr[i]);
    free(arr);
    return 0;
}

int ser_equals(int** a, const int m, const int n)
{
    int count, line = -1, maxcount = 0;
    for(int i = 0; i < m; i++)
    {
        count = 0;
        for(int j = 0; j < n - 1; j++)
        {
            if(a[i][j] == a[i][j + 1])
                count++;
            else
            {
                if(count > maxcount)
                {
                    maxcount = count;
                    line = i;
                }
                count = 0;
            }
        }
        if(count > maxcount)
        {
            maxcount = count;
            line = i;
        }
    }
    return line + 1;
}
