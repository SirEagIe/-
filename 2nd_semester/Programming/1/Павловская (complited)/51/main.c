#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int len = 81;
    char word[len], line[len];
    printf("������� �����: ");
    gets(line);
    printf("������� ����� ��� ������: "); //�������� ����� ��� ������ ������������������ ��������
    gets(word);
    if(strstr(line, word))
        printf("������������\n");
    else
        printf("�����������\n");
    return 0;
}
