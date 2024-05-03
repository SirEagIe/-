#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, ch, zn;
    printf("Введите n, n > 10\n");
    scanf("%d", &n);
    double sum, d;
    sum = 1;
    ch = 1;
    zn = 2;
    printf("1/2");
    for(int i = 0; i < n; i++ ){
        d = (double)ch/(double)zn;
        sum *= d;
        if (i != 0)
            printf(" \* %d/%d", ch, zn);
        ch += 6;
        zn += 6;
    }
    printf(" = %.10lf", sum);
    return 0;
}
