#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int len = 81;
    char word[len], line[len];
    printf("Введите текст: ");
    gets(line);
    printf("Введите слова для поиска: "); //тестовый текст для поиска послдеовательности символов
    gets(word);
    if(strstr(line, word))
        printf("Присутствует\n");
    else
        printf("Отсутствует\n");
    return 0;
}
