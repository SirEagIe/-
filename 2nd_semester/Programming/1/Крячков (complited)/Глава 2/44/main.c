#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    double x, y, f;
    printf("-------------------------------------------------\n");
    printf("|\tx\t|\ty\t|\tf\t|\n");
    printf("-------------------------------------------------\n");
    for(x = 0.2; x <= 0.6; x += 0.1)
    {
        for(y = 0; y <= 0.4; y += 0.05)
        {
            if(x >= y)
                f = log(fabs(x/(y + 1)));
            if(x < y)
                f = (1 + x)/(1 + y)*exp(-fabs(x + y));
            printf("|%15.2lf|%15.2lf|%15.12lf|\n", x, y, f);
        }
    }
    printf("-------------------------------------------------\n");
    return 0;
}
