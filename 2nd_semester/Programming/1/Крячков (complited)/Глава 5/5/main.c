#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("������� �����: ");
    char text[200] = {0}, correctText[200]  = {0};
    gets(text);
    int j = 0;
    for(int i = 0; i < strlen(text); i++)   //��������    ���   ��������������      ������.      ����������      �����    �������  -  ����    ������.     ����������    �����    �������������    -   ��� �������.
    {
        if(text[i] == '.')
        {
            correctText[j++] = text[i];
            correctText[j++] = ' ';
            continue;
        }
        if(text[i] == ' ' && text[i - 1] == ' ')
            continue;
        correctText[j++] = text[i];
    }
    setlocale(LC_ALL, "C");
    puts(correctText);
    return 0;
}
