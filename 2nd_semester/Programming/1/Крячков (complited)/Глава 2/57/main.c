#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    int temp = 0, max = 0;
    char text[80];
    printf("Введите текст\n");
    gets(text);     //Это лабараторная работа по ЯП
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] != ' ')
            temp++;
        if(text[i] == ' ' || i == (strlen(text) - 1))
        {
            if(max < temp)
                max = temp;
            temp = 0;
        }
    }
    printf("Количество символов в слове максимальной длины равно %d", max);
    return 0;
}
