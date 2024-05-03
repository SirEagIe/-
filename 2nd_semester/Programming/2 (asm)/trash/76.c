#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void q_sort(float* array, int left, int right);

int main()
{
    system("chcp 65001");
    srand(time(0));
    const int n = 10;
    float arr[n];
    int l, r;
    for(int i = 0; i < n; i++)
        arr[i] = (rand()%2000 - 1000)/100.;
    l = 0;
    r = n - 1;
    printf("Элементы массива равны:\n");
    for(int i = 0; i < n; i++)
        printf("%8.2f", arr[i]);
    q_sort(arr, l , r);
    printf("\nЭлементы после сортировки массива равны:\n");
    for(int i = 0; i < n; i++)
        printf("%8.2f", arr[i]);
    return 0;
}

void q_sort(float* array, int left, int right)
{
    int i = left, j = right;
    float middle = array[(left + right)/2];
    float temp;
    while(i < j)
    {
        while(array[i] < middle)
            i++;
        while(middle < array[j])
            j--;
        if(i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if(left < j)
        q_sort(array, left, j);
    if(i < right)
        q_sort(array, i, right);
}