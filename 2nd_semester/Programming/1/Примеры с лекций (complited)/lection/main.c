#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a, *p;
    int key;
    for( ; ; )
    {
        printf("������� �������� a\n");
        scanf("%d", &a);
        p = &a;
        printf("�������� ���������� a ����� %d = %x �����.\n", a, a);
        printf("����� ���������� a ����� %x �����.\n", &a);
        printf("������ �� ������ ��������� p ����� %d = %x �����.\n", *p, *p);
        printf("�������� ��������� p ����� %x �����.\n", p);
        printf("����� ������������ ��������� p ����� %x �����.\n", &p);
        key = getch();
        if (key == 113)
            break;
        printf("\n");
    }
    return 0;
}
