#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int searchSegment(int *arr, int size, int *pos, int *maxLenth);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, len, pos;
    printf("Введите длину массива: ");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    printf("\nВведите эементы массива: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    searchSegment(a, n, &pos, &len);
    printf("\nНомер первого элемента нужного отрезока - %d, его длина - %d \n", pos, len);
    free(a);
    return 0;
}

int searchSegment(int *arr, int size, int *pos, int *maxLenth)
{
    *maxLenth = 0;
    *pos = -1;
    int lenth;
    int rightSegment = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                lenth =  j - i + 1;
                int k = i;
                int l = j;
                while(k <= l)
                {
                    if(arr[k] == arr[l])
                        rightSegment = 1;
                    else
                    {
                        rightSegment = 0;
                        break;
                    }
                    k++;
                    l--;
                }
            }
            if(rightSegment == 1)
            {
                if(lenth > *maxLenth)
                {
                    *pos = i + 1;
                    *maxLenth = lenth;
                }
            }
        }
    }
}
