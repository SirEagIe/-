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
    printf("Введите длину массива\n");
    scanf("%d", &size);
    int arr[size];
    //usersArray(arr, size);                      //пользовательский ввод массива
    randomArray(arr, size);                     //заполнение массива случайными элементами
    printf("Массив до соритровки: \n");
    printArray(arr, size);                      //вывести значения элементов массива
    //shaker(arr, size);                          //шейкерная сортировка
    shakerWithStep(arr, size);                  //шейкерная сортировка с расписанным алгоритмом
    printf("Массив после соритровки: \n");
    printArray(arr, size);                      //вывести значения элементов массива
    return 0;
}

void randomArray(int *arr, int size)            //заполнение массива случайными элементами
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%20;
    }
}

void printArray(int *arr, int size)             //вывести значения элементов массива
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void usersArray(int *arr, int size)             //пользовательский ввод массива
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void swap(int *arr, int n1, int n2)             //поменять два элемента местами
{
    int temp;
    temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}

void shaker(int *arr, int size)                 //шейкерная сортировка
{
    int leftBorder = 0, rightBorder = size - 1, flag = 2;
    while(flag != 0)                                        //пока не будет итерации, в которой не будет перестановок
    {
        flag = 0;
        for(int i = leftBorder; i < rightBorder; i++)       //сравнение пар элементов слева направо
        {
            if(arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                flag = 1;
            }
        }
        rightBorder--;                                      //сужение участка массива, который будет проверятся, справа
        for(int i = rightBorder ; i > leftBorder; i--)      //сравнение пар элементов справа налево
        {
            if(arr[i] < arr[i - 1])
            {
                swap(arr, i, i - 1);
                flag = 1;
            }
        }
        leftBorder++;                                       //сужение участка массива, который будет проверятся, слева
    }
}

void shakerWithStep(int *arr, int size)         //шейкерная сортировка с расписанным алгоритмом
{
    int leftBorder = 0, rightBorder = size - 1, flag = 2;
    while(leftBorder < rightBorder && flag != 0)
    {
        flag = 0;
        for(int i = leftBorder; i < rightBorder; i++)
        {
            printf("\nСравнение %d и %d\n", arr[i], arr[i + 1]);
            if(arr[i] > arr[i + 1])
            {
                printf("%d <--> %d\n\n", arr[i], arr[i + 1]);
                swap(arr, i, i + 1);
                flag = 1;
            }
            else
                printf("Перемещения не поризошло\n\n");
            printArray(arr, size);
        }
        rightBorder--;
        printf("\nДвижение вправо завершено\n-------------------------\n");
        for(int i = rightBorder ; i > leftBorder; i--)
        {
            printf("\nСравнение %d и %d\n", arr[i], arr[i - 1]);
            if(arr[i] < arr[i - 1])
            {
                printf("%d <--> %d\n\n", arr[i], arr[i - 1]);
                swap(arr, i, i - 1);
                flag = 1;
            }
            else
                printf("Перемещения не поризошло\n\n");
            printArray(arr, size);
        }
        leftBorder++;
        printf("\nДвижение влево завершено\n-------------------------\n");
    }
}
