#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int m, n, nod;
    printf("Введите два натуральных числа\n");
    scanf("%d%d", &m, &n);
    while(m != n)
    {
        if(m < n)
        {
            n = n - m;
            continue;
        }
        if(m > n)
        {
            m = m - n;
            continue;
        }
    }
    if(m == n)
        nod = m;
    printf("НОД для этих чисел равен %d", nod);
    return 0;
}
