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
        printf("Введите значение a\n");
        scanf("%d", &a);
        p = &a;
        printf("Значение переменной a равно %d = %x шестн.\n", a, a);
        printf("Адрес переменной a равен %x шестн.\n", &a);
        printf("Данные по адресу указателю p равны %d = %x шестн.\n", *p, *p);
        printf("Значение указателя p равно %x шестн.\n", p);
        printf("Адрес расположения указателя p равен %x шестн.\n", &p);
        key = getch();
        if (key == 113)
            break;
        printf("\n");
    }
    return 0;
}
