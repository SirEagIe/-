#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void randomArray(int *arr, int size);
void usersArray(int *arr, int size);
void swap(int *arr, int n1, int n2);
void shaker(int *arr, int size);
void shakerWithStep(int *arr, int size);
void printArray(int *arr, int size);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int size;
    printf("������� ����� �������\n");
    scanf("%d", &size);
    int arr[size];
    //usersArray(arr, size);                      //���������������� ���� �������
    randomArray(arr, size);                     //���������� ������� ���������� ����������
    printf("������ �� ����������: \n");
    printArray(arr, size);                      //������� �������� ��������� �������
    //shaker(arr, size);                          //��������� ����������
    shakerWithStep(arr, size);                  //��������� ���������� � ����������� ����������
    printf("������ ����� ����������: \n");
    printArray(arr, size);                      //������� �������� ��������� �������
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

void printArray(int *arr, int size)             //������� �������� ��������� �������
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void usersArray(int *arr, int size)             //���������������� ���� �������
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void swap(int *arr, int n1, int n2)             //�������� ��� �������� �������
{
    int temp;
    temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}

void shaker(int *arr, int size)                 //��������� ����������
{
    int leftBorder = 0, rightBorder = size - 1, flag = 2;
    while(flag != 0)                                        //���� �� ����� ��������, � ������� �� ����� ������������
    {
        flag = 0;
        for(int i = leftBorder; i < rightBorder; i++)       //��������� ��� ��������� ����� �������
        {
            if(arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                flag = 1;
            }
        }
        rightBorder--;                                      //������� ������� �������, ������� ����� ����������, ������
        for(int i = rightBorder ; i > leftBorder; i--)      //��������� ��� ��������� ������ ������
        {
            if(arr[i] < arr[i - 1])
            {
                swap(arr, i, i - 1);
                flag = 1;
            }
        }
        leftBorder++;                                       //������� ������� �������, ������� ����� ����������, �����
    }
}

void shakerWithStep(int *arr, int size)         //��������� ���������� � ����������� ����������
{
    int leftBorder = 0, rightBorder = size - 1, flag = 2;
    while(leftBorder < rightBorder && flag != 0)
    {
        flag = 0;
        for(int i = leftBorder; i < rightBorder; i++)
        {
            printf("\n��������� %d � %d\n", arr[i], arr[i + 1]);
            if(arr[i] > arr[i + 1])
            {
                printf("%d <--> %d\n\n", arr[i], arr[i + 1]);
                swap(arr, i, i + 1);
                flag = 1;
            }
            else
                printf("����������� �� ���������\n\n");
            printArray(arr, size);
        }
        rightBorder--;
        printf("\n�������� ������ ���������\n-------------------------\n");
        for(int i = rightBorder ; i > leftBorder; i--)
        {
            printf("\n��������� %d � %d\n", arr[i], arr[i - 1]);
            if(arr[i] < arr[i - 1])
            {
                printf("%d <--> %d\n\n", arr[i], arr[i - 1]);
                swap(arr, i, i - 1);
                flag = 1;
            }
            else
                printf("����������� �� ���������\n\n");
            printArray(arr, size);
        }
        leftBorder++;
        printf("\n�������� ����� ���������\n-------------------------\n");
    }
}
