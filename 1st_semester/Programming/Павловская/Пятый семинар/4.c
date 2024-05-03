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
    char* text = (char*)malloc((len + 1)*sizeof(char));
    char* word = (char*)malloc((len + 1)*sizeof(char));
    for(int i = 0; i < len + 1; i++)
    {
        text[i] = getc(fp);
    }
    text[len] = '\0';
    word[len] = '\0';
    for(int j = 0; j < len; j++)
    {
        word[j] = '\0';
    }


    int flag = 0, k = 0;
    for(int i = 0; i < len; i++)
    {
        if(flag == 0)
        {
            word[k] = text[i];
            k++;
        }
        if(flag == 1)
            putchar(text[i]);
        if(text[i] == ' ')
        {
            if(flag == 0)
            {
                flag = 1;
                continue;
            }
            if(flag == 1)
            {
                printf("%s", word);
                for(int j = 0; j < len; j++)
                {
                    word[j] = '\0';
                }
                k = 0;
                flag = 0;
                continue;
            }
        }
    }
    printf(" %s", word);



    free(text);
    free(word);
    fclose(fp);
    return 0;
}
