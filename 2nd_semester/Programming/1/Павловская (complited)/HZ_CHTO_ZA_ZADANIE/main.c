#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    system("chcp 65001");
    double xn, xk, dx, F = 0, f = 1, eps;
	int n;
    printf("Введите xn, xk, dx, eps\n"); //0.5 1.5 0.01 0.01
    scanf("%lf%lf%lf%lf", &xn, &xk, &dx, &eps);
    printf("---------------------------------------------------\n");
    printf("|\tx\t|\tF\t|Количество членов|\n");
    printf("---------------------------------------------------\n");
    for(double x = xn, i = 0; x < xk; x += dx, i++)
    {
		F = 0;
		f = 1;
        if(x >= 1 || x <= -1)
            break;
        for(n = 0; fabs(f) > eps; n++)
        {
			//printf("%lf > %lf\n", fabs(f), eps);
            f = 2*(pow(x, (2*n + 1)))/(2*n + 1);
            F += f;
        }
        printf("|%15.2lf|%15.3lf|%17d|\n", x, F, n);
    }
    printf("---------------------------------------------------\n");
    return 0;
}
