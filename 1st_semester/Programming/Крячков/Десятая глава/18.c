#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    FILE *fp;
    fp = fopen("text.txt", "r+");
    if(fp == NULL)
    {
        printf("Невозможно открыть файл!\n");
        exit(1);
    }
    int len = 0;
    char ch = getc(fp);
    while(ch != EOF)
    {
        len++;
        ch = getc(fp);
    }
    rewind(fp);
    char* text = (char*)malloc((len + 1)*sizeof(char));
    for(int i = 0; i < len + 1; i++)
    {
        text[i] = getc(fp);
    }
    text[len] = '\0';
    rewind(fp);
    int kolSpace = 0;
    for(int i = 0; i < len; i++)
    {
        if(text[i] != ' ')
            fputc(text[i], fp);
        else
            kolSpace++;
    }
    for(int i = 0; i < kolSpace; i++)
        fputs(" ", fp);
    free(text);
    fclose(fp);
    return 0;
}
