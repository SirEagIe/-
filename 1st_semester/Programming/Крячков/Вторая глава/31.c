#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int N, k1 = 0, k0 = 0, check;
    printf("Введите длину массива\n");
    scanf("%d", &N);
    int IM[N];
    printf("Введите элементы массива\n");
    for(int i = 0; i < N; i++)      //заполнение массива
        scanf("%d", &IM[i]);
    printf("Элементы массива до сортировки:\n");
    for(int i = 0; i < N; i++)      //вывод элементов массива до сортировки
    {
        printf("%3d", IM[i]);
        if(IM[i] == 0)  k0++;       //подсчёт 0
        else if(IM[i] == 1)  k1++;  //подсчёт 1
        else                        //проверка на содержание в массиве других чисел
        {
            printf("\nВведены неверные данные\n");
            check = 0;
        }
    }
    if(check)                       //если порверка пройдена
    {
        for(int i = 0; i < k0; i++) //сортировка массива
            IM[i] = 0;
        for( ; k0 < N; k0++)
            IM[k0] = 1;
        printf("\nЭлементы массива после сортировки:\n");
        for(int i = 0; i < N; i++)
        {
            printf("%3d", IM[i]);
        }
    }
    return 0;
}
