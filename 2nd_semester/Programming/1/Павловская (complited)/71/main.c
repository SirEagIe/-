#include <stdio.h>
#include <math.h>
#include <locale.h>

double coshFunc(double x, double eps, int err);

int main()
{
    setlocale(LC_CTYPE, "rus");
    double Xn, Xk, dX, eps, y;
    int err;
    printf("Введите Xn, Xk, dX, eps\n");
    scanf("%lf%lf%lf%lf", &Xn, &Xk, &dX, &eps);
    printf("---------------------------------\n");
    printf("|\tX\t|\tY\t|\n");
    printf("---------------------------------\n");
    for(double x = Xn; x <= Xk; x += dX)
    {
        y = coshFunc(x, eps, err);
        if(err == 1)
            printf("|%15.2lf| Ряд расходится|\n", x);
        else
            printf("|%15.2lf|%15.6g|\n", x, y);
    }
    printf("---------------------------------\n");
    return 0;
}

double coshFunc(double x, double eps, int err)
{
    err = 0;
    const int MaxIter = 500;
    double ch = 1, y = ch;
    for(int n = 0; fabs(ch) > eps; n++)
    {
        ch *= x * x /((2 * n + 1)*(2 * n + 2));
        y += ch;
        if(n > MaxIter)
        {
            err = 1;
            return 0;
        }
    }
    return y;
}

