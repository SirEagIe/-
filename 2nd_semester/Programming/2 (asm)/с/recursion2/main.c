#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sumOfNum(int num);

int main()
{
    //����� ���� �����
    setlocale(LC_ALL, "rus");
    char ch;
    int x;
    while(ch != 'q')
    {
        printf("������� �����: ");
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
