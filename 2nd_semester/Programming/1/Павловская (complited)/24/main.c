#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "rus");
    double xn, xk, dx, t, y;
    printf("¬ведите xn, xk, dx, t\n");
    scanf("%lf%lf%lf%lf", &xn, &xk, &dx, &t);
    printf("---------------------\n");
    printf("|    x    |    y    |\n");
    printf("---------------------\n");
    double x = xn;
    while(x <= xk){
        if(x < 0) y = t;
        if(x >= 0 && x < 10) y = t*x;
        if(x >= 10) y = 2*t;
        if(t > 100) printf("|%9.2lf|%9d|\n", x, (int)y);
        else printf("|%9.2lf|%9.2lf|\n", x, y);
        x += dx;
    }
    printf("---------------------\n");
    return 0;
}
