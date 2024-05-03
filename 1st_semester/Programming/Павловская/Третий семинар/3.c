#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int n = 20;
    float arr[n], middle, temp;
    int stackl[n], stackr[n], sp = 0;
    int i, j, left, right;
    printf("Введите элементы массива\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("Элементы массива равны:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    //Сортировка
    sp = 1; stackl[1] = 0; stackr[1] = n - 1;
    while(sp > 0)
    {
        //выборка из стека последнего запроса
        left = stackl[sp];
        right = stackr[sp];
        sp--;
        while(left < right)
        {
            //разделение {arr[left]...arr[right]}
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
                //Запись в стек запроса изправой части
                sp++;
                stackl[sp] = i;
                stackr[sp] = right;
            }
            right = j;
            //Теперь left и right ограничивают левую часть
        }
    }
    //Вывод результата
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
