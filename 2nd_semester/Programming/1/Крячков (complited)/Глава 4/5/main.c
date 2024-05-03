#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int maxEl(int* arr, int size);

int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("Введите n\n");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    for(int i = 0; i < n; i++)
        a[i] = rand()%10;
    printf("Элементы массива равны: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nМаксимальное из чисел, встречающихся в массиве более одного раза - %d\n", maxEl(a, n));
    free(a);
    return 0;
}

int maxEl(int* arr, int size)
{
    int kol = 0;
    int max = -1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            if(arr[i] == arr[j])
                kol++;
        if((arr[i] > max || i == 0) && kol > 1)
            max = arr[i];
        kol = 0;
    }
    return max;
}
