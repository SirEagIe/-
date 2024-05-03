#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "rus");
    double xn, xk, dx, a, b, c, F;
    printf("¬ведите xn, xk, dx, a, b, c\n");
    scanf("%lf%lf%lf%lf%lf%lf", &xn, &xk, &dx, &a, &b, &c);
    printf("---------------------------------\n");
    printf("|\tx\t|\tF\t|\n");
    printf("---------------------------------\n");
    double x = xn;
    int check;
    while(x <= xk){
        if(x < 3 && b != 0)           F = a*x*x-b*x+c;
        else if(x > 3 && b == 0){
            if(x == c)                check = 0;
            else                      F = (x-a)/(x-c);
        }
             else{
                if(c == 0)            check = 0;
                else                  F = x/c;
             }

        if(check == 0){
            printf("|%15.2lf|   нет значений|\n", x);
            check = 1;
        }
        else{
            if((!((int)a || (int)b) && ((int)a ^ (int)c)) != 0)
                printf("|%15.2lf|%15.3lf|\n", x, F);
            else
                printf("|%15.2lf|%15d|\n", x, (int)F);
        }
        x += dx;
    }
    printf("---------------------------------\n");
    return 0;
}
