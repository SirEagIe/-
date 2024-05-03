#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <float.h>

int main()
{
    setlocale(LC_ALL, "rus");
    const int maxIter = 500;
    double x, eps = DBL_EPSILON;
    printf("Введите аргумент:\n");
    scanf("%lf", &x);
    double ch = 1, y = ch;
    int n;
    for(int i = 0; fabs(ch) > eps && i < maxIter; i++){
        ch *= x*x/((2*n+1)*(2*n+2));
        y += ch;
        n = i;
    }
    if(n < maxIter){
        printf("Значение функции: %lf при x = %lf\n", y, x);
        printf("вычислено после %i итераций\n", n);
    }
    else
        printf("Ряд расходится\n");
    return 0;
}
