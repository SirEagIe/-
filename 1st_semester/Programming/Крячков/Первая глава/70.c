#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, adjacentNum = 0;
    printf("Введите количество чисел\n");
    scanf("%d", &n);
    int arr[n];
    printf("Введите последовательность чисел\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i != 0 && arr[i] > 0 && arr[i-1] > 0)
            adjacentNum++;
    }
    printf("Количество соседств положительных чисел равно %d", adjacentNum);
    return 0;
}
