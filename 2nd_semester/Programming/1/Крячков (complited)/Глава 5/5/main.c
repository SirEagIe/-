#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Введите текст: ");
    char text[200] = {0}, correctText[200]  = {0};
    gets(text);
    int j = 0;
    for(int i = 0; i < strlen(text); i++)   //Программ    для   редактирования      текста.      Расстояние      между    словами  -  один    пробел.     Расстояние    между    предложениями    -   два пробела.
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
