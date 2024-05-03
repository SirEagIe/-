#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef double (*Pfun)(const double, const double);
void print_tabl(Pfun fun, const double Xn, const double Xk, const double dX, const double eps);
double coshFunc(double x, double eps);

int main()
{
    setlocale(LC_CTYPE, "rus");
    double Xn, Xk, dX, eps, y;
    printf("¬ведите Xn, Xk, dX, eps\n");
    scanf("%lf%lf%lf%lf", &Xn, &Xk, &dX, &eps);
    print_tabl(cosh, Xn, Xk, dX, eps);
    return 0;
}

void print_tabl(Pfun fun, const double Xn, const double Xk, const double dX, const double eps)
{
    printf("---------------------------------\n");
    printf("|\tX\t|\tY\t|\n");
    printf("---------------------------------\n");
    for(double x = Xn; x <= Xk; x += dX)
        printf("|%15.2lf|%15.6g|\n", x, fun(x, eps));
    printf("---------------------------------\n");
}

double coshFunc(double x, double eps)
{
    const int MaxIter = 500;
    double ch = 1, y = ch;
    for(int n = 0; fabs(ch) > eps; n++)
    {
        ch *= x * x /((2 * n + 1)*(2 * n + 2));
        y += ch;
        if(n > MaxIter)
            return 0;
    }
    return y;
}
