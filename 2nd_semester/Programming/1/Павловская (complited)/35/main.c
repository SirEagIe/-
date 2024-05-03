#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, kol = 0, sum = 0;
    float c, max;
    printf("������� ������ �������\n");
    scanf("%d", &n);
    float arr[n];
    printf("������� �������� �������\n");
    usersArray(arr, n); //0.19   -62.04   -67.91   77.59   -80.34   67.02   57.19   -60.45   27.41   68.65
    /*printf("�������� ������� �����:\n");
    printArray(arr, n);*/
    printf("������� ����� C\n");
    scanf("%f", &c);
    for(int i = 0; i < n; i++)
        if(arr[i] < c)
            kol++;
    printf("���������� ��������� �������, ������� C - %d\n", kol);
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] < 0)
            break;
        sum += arr[i];
    }
    printf("����� ����� ������ ��������� �������, ������������� ����� ���������� �������������� �������� - %d\n", sum);
    for(int i = 0; i < n; i++)
        if(arr[i] > max || i == 0)
            max = arr[i];
    printf("������������ ������� ������� ����� %.2f\n", max);
    float lBoard = max - max*0.2;
    float rBoard = max + max*0.2;
    printf("����� ������� - %.2f", lBoard);
    printf("\n������ ������� - %.2f\n", rBoard);
    float *stack = (float *)malloc(n * sizeof(float));
    int iStack = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= lBoard && arr[i] <= rBoard)
        {
            stack[iStack] = arr[i];
            iStack++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(!(arr[i] >= lBoard && arr[i] <= rBoard))
        {
            stack[iStack] = arr[i];
            iStack++;
        }
    }
    for(int i = 0; i < n; i++)
        arr[i] = stack[i];
    printf("������ ����� ��������������:\n");
    printArray(arr, n);
    return 0;
}

void randomArray(float *arr, int size)            //���������� ������� ���������� ����������
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        arr[i] = (-10000 + rand()%20000)/100.;
    }
}

void usersArray(float *arr, int size)             //���������������� ���� �������
{
    for(int i = 0; i < size; i++)
    {
        scanf("%f", &arr[i]);
    }
}

void printArray(float *arr, int size)             //������� �������� ��������� �������
{
    for(int i = 0; i < size; i++)
    {
        printf("%7.2f ", arr[i]);
    }
    printf("\n");
}
