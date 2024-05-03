#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, m;
    double S = 0;
    printf("Введите n, m\n");
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= m; k++)
        {
            S += sin((M_PI/4)*i + (M_PI/8)*pow(k, 2));
        }
    }
    printf("Результат равен %lf\n", S);
    return 0;
}
