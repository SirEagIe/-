#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int isPowerOfTwo(int num);

int main()
{
    //������ ������� ������
    setlocale(LC_ALL, "rus");
    char ch;
    int x;
    while(ch != 'q')
    {
        printf("������� �����: ");
        scanf("%d", &x);
        if(isPowerOfTwo(x) == 1)
            printf("������ ������� ������\n");
        if(isPowerOfTwo(x) == 0)
            printf("�� ������ ������� ������\n");
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
