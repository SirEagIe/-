#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()
{   while (1==1)
    {
    int key;
    setlocale(LC_ALL, "rus");
    printf("������� �� ���� �� ��������� ��������:\n");
    key = getch();
    key = getch();
    switch(key){
        case 77: printf("������� ������\n");
        break;
        case 75: printf("������� �����\n");
        break;
        case 72: printf("������� �����\n");
        break;
        case 80: printf("������� ����\n");
        break;
        default: printf("�� �������\n");
    }
    }
    return 0;
}
