#include <stdio.h>
#include <stdlib.h>

int sumOfNum(int num);

int main()
{
    //Сумма цифр числа
    system("chcp 65001");
    char ch;
    int x;
    while(ch != 'q')
    {
        printf("Введите число: ");
        scanf("%d", &x);
        printf("%d\n", sumOfNum(x));
        ch = getch();
    }
    return 0;
}

int sumOfNum(int num)
{
    if(num/10 == 0)
    {
        return num;
    }
    return num%10 + sumOfNum(num/10);
}