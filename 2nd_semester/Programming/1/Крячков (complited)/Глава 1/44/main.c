#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, f1 = 1, f2 = 1, f3 = f1 + f2, result;
    printf("¬ведите n > 10\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            printf("%d", f1);
        else
            printf(" + %d", f1);
        if(i == 0)
            result = f1;
        else
            result += f1;
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2; //1+1+2+3+5+8
    }
    printf(" = %d", result);
    return 0;
}
