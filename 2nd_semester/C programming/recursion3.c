#include <stdio.h>
#include <stdlib.h>

int _function(int n);

int main()
{
    //Цифры в обратном порядке
    system("chcp 65001");
    char ch;
    int x;
    while(ch != 'q')
    {
        printf("Введите число: ");
        scanf("%d", &x);
        _function(x);
        printf("\n");
        ch = getch();
    }
    return 0;
}

int _function(int n)
{
    if(n/10 != 0)
    {
        printf("%d", n%10);
    }
    if(n/10 == 0)
    {
        printf("%d", n%10);
        return 1;
    }
    return _function(n/10);
}