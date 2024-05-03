#include <stdio.h>
#include <string.h>
#include <locale.h>

int issubstr(char* str1, char* str2);

int main()
{
    setlocale(LC_CTYPE, "rus");
    char text[100] = {0};           //Текст для проверки поиска
    char word[100] = {0};
    printf("Введите текст: ");
    gets(text);
    printf("Найти слово: ");
    gets(word);
    printf("%d\n", issubstr(word, text));
    return 0;
}

int issubstr(char* str1, char* str2)
{
    int result;
    int i, j = 0;
    int check = 0;
    while(j < strlen(str2))
    {
        for( ; j < strlen(str2); j++)
        {
            if(str1[0] == str2[j])
            {
                result = j;
                check = 1;
                break;
            }
        }
        if(check == 0)
            return -1;
        for(i = 0; i < strlen(str1); i++)
        {
            if(str1[i] == str2[j])
            {
                check = 1;
                j++;
            }
            else
                check = 0;
        }
        if(check == 1)
            return result + 1;
        if(check == 0)
            j = ++result;
    }
}
