#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int nonIncreasingSequence(int* arr, int size);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("������� ����� �������\n");
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("������ ������������� ������\n");
        exit(1);
    }
    printf("������� �������� �������\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int result = nonIncreasingSequence(a, n);
    if(result == NULL)
        printf("�������� ������� �������� ����������� ������������������\n");
    else
        printf("�������� ������� �� �������� ����������� ������������������, �������, �� ������� ���������� �������, - %d", result);
    free(a);
    return 0;
}

int nonIncreasingSequence(int* arr, int size)
{
    int result = NULL;
    for(int i = 1; i < size; i++)
        if(arr[i - 1] > arr[i])
            result = i + 1;
    return result;
}
