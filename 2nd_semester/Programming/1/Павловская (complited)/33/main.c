#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int n = 10;
    float arr[n], middle, temp;
    int stackl[n], stackr[n], sp = 0;
    int i, j, left, right;
    printf("�������� ������� �����:\n");
    randomArray(arr, n);
    printArray(arr, n);
    //����������
    sp = 1; stackl[1] = 0; stackr[1] = n - 1;
    while(sp > 0)
    {
        //������� �� ����� ���������� �������
        left = stackl[sp];
        right = stackr[sp];
        sp--;
        while(left < right)
        {
            //���������� {arr[left]...arr[right]}
            i = left; j = right;
            middle = arr[(left + right)/2];
            while(i < j)
            {
                while(arr[i] < middle) i++;
                while(middle < arr[j]) j--;
                if(i <= j)
                {
                    temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                    i++; j--;
                }
            }
            if(i < right)
            {
                //������ � ���� ������� �������� �����
                sp++;
                stackl[sp] = i;
                stackr[sp] = right;
            }
            right = j;
            //������ left � right ������������ ����� �����
        }
    }
    //����� ����������
    printf("\n");
    printArray(arr, n);
    return 0;
}

void randomArray(int *arr, int size)            //���������� ������� ���������� ����������
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%20;
    }
}

void usersArray(int *arr, int size)             //���������������� ���� �������
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int size)             //������� �������� ��������� �������
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

