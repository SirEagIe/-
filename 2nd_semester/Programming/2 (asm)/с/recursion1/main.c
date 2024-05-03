#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int isPowerOfTwo(int num);

int main()
{
    //Точная степень двойки
    setlocale(LC_ALL, "rus");
    char ch;
    int x;
    while(ch != 'q')
    {
        printf("Введите число: ");
        scanf("%d", &x);
        if(isPowerOfTwo(x) == 1)
            printf("Точная степень двойки\n");
        if(isPowerOfTwo(x) == 0)
            printf("Не точная степень двойки\n");
        ch = getch();
    }
    return 0;
}

int isPowerOfTwo(int num)
{
    if(num == 2)
    {
        return 1;
    }
    if(num%2 == 0)
    {
        num /= 2;
        isPowerOfTwo(num);
    }
    else
    {
        return 0;
    }
}
