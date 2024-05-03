#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    char s1[80], s2[80];
    gets(s1);
    gets(s2);
    printf("Длина: %d и %d\n", strlen(s1), strlen(s2));
    if(!strcmp(s1, s2))
        printf("Строки равны\n");
    strcat(s1, s2);
    printf("%s\n", s1);
    strcpy(s1, "Проверка!");
    printf("%s\n", s1);
    if(strchr("Алло!", 'А'))
        printf("А есть в Алло!\n");
    if(strstr("Привет!", "ив"))
        printf("Найдено ив\n");
    return 0;
}
