#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{

    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int n;
    printf("������� ���������� ���������\n");
    scanf("%d", &n);
    int a[n];
    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 21 - 10;
    }
    printf("�������� ������� �����:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%4d ", a[i]);
    }
    int sum = 0, flag_neg = 0;
    for(i = n - 1; i >= 0; i--)
    {
        if(a[i] < 0)
        {
            flag_neg = 1;
            break;
        }
        sum += a[i];
    }
    if(flag_neg)
        printf("\n����� ����� %d", sum);
    else
        printf("\n������������� ��������� ���");
    return 0;
}
