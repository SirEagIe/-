#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int key;
    int n, k, result;
    for( ; ; )
    {
        printf("������� ����������� ����� n\n");
        scanf("%d", &n);
        printf("������� �������� k\n");
        scanf("%d", &k);
        result = (int)(n/pow(10, k-1))%10;
        printf("%d-� ����� ����� %d - %d\n\n", k, n, result);
        key = getch();
        if(key == 113)
            break;
    }
    return 0;
}
