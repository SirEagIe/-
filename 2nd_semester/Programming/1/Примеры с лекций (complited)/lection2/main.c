#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    char s1[80], s2[80];
    gets(s1);
    gets(s2);
    printf("�����: %d � %d\n", strlen(s1), strlen(s2));
    if(!strcmp(s1, s2))
        printf("������ �����\n");
    strcat(s1, s2);
    printf("%s\n", s1);
    strcpy(s1, "��������!");
    printf("%s\n", s1);
    if(strchr("����!", '�'))
        printf("� ���� � ����!\n");
    if(strstr("������!", "��"))
        printf("������� ��\n");
    return 0;
}
