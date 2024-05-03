#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    FILE *fp;
    printf("Введите слово для поиска: ");
    char word[80];
    gets(word);
    fp = fopen("text.txt", "r");
    if(fp == NULL)
    {
        printf("Невозможно открыть файл!\n");
        exit(1);
    }
    int finded, kol = 0;
    char ch;
    for(int i = 0; i < 80; i++)
    {
        ch = getc(fp);
        finded = 0;
        if(ch == word[0])
        {
            for(int j = 0; j < strlen(word); j++)
            {
                if(ch == word[j])
                {
                    finded = 1;
                    ch = getc(fp);
                }
                else
                {
                    finded = 0;
                    break;
                }
            }
            if(finded == 1)
                kol++;
        }
    }
    printf("Количество вхождений слова - %d", kol);
    fclose(fp);
    return 0;
}
