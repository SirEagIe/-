#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    FILE *fp;
    fp = fopen("text.txt", "r");
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
    fp = fopen("text.txt", "r");
    char* buf = (char*)malloc((len + 1)*sizeof(char));
    for(int i = 0; i < len + 1; i++)
    {
        buf[i] = getc(fp);
    }
    buf[len] = '\0';
    //printf("%s", text);
    int n = 0;
    for(int i = 0; buf[i]; i++)
    {
        if(buf[i] == '?')
        {
            for(int j = n; j <= i; j++)
                printf("%c", buf[j]);
            n = i + 1;
        }
        if(buf[i] == '.' || buf[i] == '!')
            n = i + 1;
    }
    free(buf);
    fclose(fp);
    return 0;
}
