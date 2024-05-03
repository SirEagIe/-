#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int searchPoint(int* arr, int size, float radius);

int main()
{
    srand(time(0));
    setlocale(LC_CTYPE, "rus");
	float radius;
    int n;
    printf("������� ���������� �����\n");
    scanf("%d", &n);
    n *= 3;
    int *a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("������ ������������� ������\n");
        exit(1);
    }
    for(int i = 0; i < n; i++)
        a[i] = rand()%11 - 5;
    printf("������ �����: \n");
    for(int i = 0; i < n; i += 3)
        printf("(%d , %d , %d)  ", a[i], a[i + 1], a[i + 2]);
	printf("������� ������ ����\n");
	scanf("%f", &radius);
    int point = searchPoint(a, n, radius);
    printf("\n������ ����� - (%d , %d , %d)", a[point], a[point+1], a[point+2]);
    free(a);
    return 0;
}

int searchPoint(int* arr, int size, float radius)
{
    int point;
    float dist;
    int kolPnt, maxKolPnt = 0;
    for(int i = 0; i < size; i += 3)
    {
        kolPnt = 0;
        for(int j = 0; j < size; j += 3)
        {
            if(i == j)
                continue;
            dist = sqrt((arr[i] + arr[j])*(arr[i] + arr[j]) + (arr[i+1] + arr[j+1])*(arr[i+1] + arr[j+1]) + (arr[i+2] + arr[j+2])*(arr[i+2] + arr[j+2]));
            printf("\n���������� ����� ������� %d � %d - %.2f", i/3+1, j/3+1, dist);
            if(dist <= radius)
            {
                kolPnt++;
                printf("\t����� %d ���������� � ���� � ������� � ����� %d � �������� %.1f", j/3+1, i/3+1, radius);
            }
            else
                printf("\t����� %d �� ���������� � ���� � ������� � ����� %d � �������� %.1f", j/3+1, i/3+1, radius);
        }
        if(kolPnt > maxKolPnt)
        {
            maxKolPnt = kolPnt;
            point = i;
        }
    }
    return point;
}
