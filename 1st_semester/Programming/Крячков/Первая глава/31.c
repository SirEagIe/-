#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define min(a, b) (a<b) ? a : b

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a, b;
    float P, k;
    printf("Введите значения a, b\n");
    scanf("%d%d", &a, &b);
    if (a%b == 0 || a == 2)
        k = a*a + b;
    else
        k = (1. + b)/(2. - a);
    P = (min(a + b, 2*a)) + k*(min(a - 3*b, 25));
    printf("P = %.2f\n", P);
    return 0;
}
