#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, k, result;
    printf("Введите натуральное число n\n");
    scanf("%d", &n);
    printf("Введите значение k\n");
    scanf("%d", &k);
    result = (int)(n/pow(10, k-1))%10;
    printf("%d-я цифра числа %d - %d", k, n, result);
    return 0;
}
