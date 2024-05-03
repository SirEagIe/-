#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    double e, ai = 1./2., aj = 1;
    int z = 2;
    printf("Введите значение e, 0 < e < 0,1\n");
    scanf("%lf", &e);
    for(int i = 3; !(fabs(ai - aj) < e); i++){
        aj = ai;
        ai = 1./i;
        z = i;
    }
    printf("|ai - ai-1| < e\n");
    printf("|1/%d - 1/%d| < %lf\n", z, z-1, e);
    printf("|%lf - %lf| < %lf\n", ai, aj, e);
    printf(" %lf < %lf\n", fabs(ai - aj), e);
    printf("ai = 1/%d = %lf", z, ai);
    return 0;
}
