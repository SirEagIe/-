#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a, b, m, check = 0;
    printf("������� m\n");
    scanf("%d", &m);
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if((i*i + j*j == m))
            {
                check = 1;
                a = i;
                b = j;
            }
        }
    }
    if(check == 0)
        printf("��� ����� ������ ����������� � ���� ����� ���� ���������\n");
    else
        printf("%d^2 + %d^2 = %d", a, b, m);
    return 0;
}
