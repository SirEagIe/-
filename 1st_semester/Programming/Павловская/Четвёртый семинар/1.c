#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    const int nrow = 10, ncol = 20;
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int arr[nrow][ncol];
    for(int i = 0; i < nrow; i++)
        for(int j = 0; j < ncol; j++)
            arr[i][j] = rand()%200 - 100;
    printf("Элементы массива равны:\n");
    for(int i = 0; i < nrow; i++)
    {
        for(int j = 0; j < ncol; j++)
                printf("%4d ", arr[i][j]);
        printf("\n");
    }
    int n_pos_el;
    float s = 0;
    for(int i = 0; i < nrow; i++)
    {
        n_pos_el = 0;
        for(int j = 0; j < ncol; j++)
        {
            s += arr[i][j];
            if(arr[i][j] > 0)
                n_pos_el++;
        }
        printf("В %dй строке - %d положительных элементов\n", i+1, n_pos_el);
    }
    s /= (nrow*ncol);
    printf("Среднее арифметическое - %.2f\n", s);
    return 0;
}
