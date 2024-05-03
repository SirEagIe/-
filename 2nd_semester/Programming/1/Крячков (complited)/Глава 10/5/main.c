#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("chcp 1251");
    system("cls");
    const int l_code = 5, l_autor = 20, l_name = 30, l_year = 5, l_locale = 8, l_buf = l_code + l_autor + l_name + l_year + l_locale, l_books = 50;
    struct lib
    {
        char code[l_code + 1];
        char autor[l_autor + 1];
        char name[l_name + 1];
        char year[l_year + 1];
        char locale[l_locale + 1];
    };
    struct lib book[l_books];
    char buf[l_buf + 1];
    FILE *fp;
    fp = fopen("lib.txt", "r+");
    if(fp == NULL)
    {
        printf("ќшибка чтени€ файла\n");
        exit(1);
    }
    for(int i = 0; fgets(buf, l_buf, fp); i++)
    {
        if( i >= l_books)
        {
            printf("—лишком большой файл\n");
            return 1;
        }
        strncpy(book[i].code, buf, l_code);
        book[i].code[l_code] = '\0';
        strncpy(book[i].autor, buf + l_code, l_autor);
        book[i].autor[l_autor] = '\0';
        strncpy(book[i].name, buf + l_code + l_autor, l_name);
        book[i].name[l_name] = '\0';
        strncpy(book[i].year, buf + l_code + l_autor + l_name, l_year);
        book[i].year[l_year] = '\0';
        strncpy(book[i].locale, buf + l_code + l_autor + l_name + l_year, l_locale);
        book[i].locale[l_locale] = '\0';
        //printf("%s\n%s\n%s\n%s\n%s\n", book[i].code, book[i].autor, book[i].name, book[i].year, book[i].locale);
    }
    char inputBuf[80];
    int not_found = 1;
    while(1)
    {
        system("cls");
        printf("1 - удалить запись по шифру XXXX\n2 - добавить новую запись\n3 - изменить запись\n4 - получить информацию о книге с шифром XXXX\n");
        char ch = getch();
        switch(ch)
        {
            case '1':
                {
                    printf("¬ведите шифр книги: ");
                    gets(inputBuf);
                    for(int i = 0; i < l_books; i++)
                    {
                        if(strstr(book[i].code, inputBuf))
                        {
                            for(int j = 0; j < l_autor; j++)
                                book[i].autor[j] = ' ';
                            for(int j = 0; j < l_name; j++)
                                book[i].name[j] = ' ';
                            for(int j = 0; j < l_year; j++)
                                book[i].year[j] = ' ';
                            for(int j = 0; j < l_locale; j++)
                                book[i].locale[j] = ' ';
                            int code = atoi(&book[i].code);
                            rewind(fp);
                            fseek(fp, 4*code + (code - 1)*(l_buf-l_code), SEEK_SET);
                            fputs("                                                             ", fp);
                        }
                    }
                    break;
                }
            case '2':
                {
                    printf("¬ведите шифр книги: ");
                    gets(inputBuf);
                    for(int i = 0; i < l_books; i++)
                    {
                        if(strstr(book[i].code, inputBuf) && book[i].name[0] != ' ')
                        {
                            printf("Ўифр зан€т\n");
                            getch();
                            break;
                        }
                        if(strstr(book[i].code, inputBuf))
                        {
                            int code = atoi(&book[i].code);
                            rewind(fp);
                            fseek(fp, 4*code + (code - 1)*(l_buf-l_code), SEEK_SET);
                            printf("¬ведите автора: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_autor)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            for(int j = strlen(inputBuf); j < 80; j++)
                                inputBuf[j] = ' ';
                            strncpy(book[i].autor, inputBuf, l_autor);
                            book[i].autor[l_autor] = '\0';
                            printf("¬ведите название книги: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_name - 3)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            strncpy(book[i].name + 1, inputBuf, l_name);
                            book[i].name[0] = '"';
                            book[i].name[strlen(inputBuf)+1] = '"';
                            for(int j = strlen(inputBuf) + 2; j < l_name; j++)
                                book[i].name[j] = ' ';
                            book[i].name[l_name] = '\0';
                            printf("¬ведите год публикации: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_year)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            for(int j = strlen(inputBuf); j < 80; j++)
                                inputBuf[j] = ' ';
                            strncpy(book[i].year, inputBuf, l_year);
                            book[i].year[l_year] = '\0';
                            printf("¬ведите местоположение: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_locale)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            fputs(" ", fp);
                            fputs(book[i].autor, fp);
                            fputs(book[i].name, fp);
                            fputs(book[i].year, fp);
                            fputs(inputBuf, fp);
                            fputs("\n", fp);
                            for(int j = strlen(inputBuf); j < 80; j++)
                                inputBuf[j] = ' ';
                            strncpy(book[i].locale, inputBuf, l_locale);
                            book[i].locale[l_locale] = '\0';
                        }
                    }
                    break;
                }
            case '3':
                {
                    printf("¬ведите шифр книги: ");
                    gets(inputBuf);
                    for(int i = 0; i < l_books; i++)
                    {
                        if(strstr(book[i].code, inputBuf) && book[i].name[0] == ' ')
                        {
                            printf(" нига с данным шифром не существует\n");
                            getch();
                            break;
                        }
                        if(strstr(book[i].code, inputBuf))
                        {
                            int code = atoi(&book[i].code);
                            rewind(fp);
                            fseek(fp, 4*code + (code - 1)*(l_buf-l_code), SEEK_SET);
                            printf("¬ведите автора: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_autor)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            for(int j = strlen(inputBuf); j < 80; j++)
                                inputBuf[j] = ' ';
                            strncpy(book[i].autor, inputBuf, l_autor);
                            book[i].autor[l_autor] = '\0';
                            printf("¬ведите название книги: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_name - 3)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            strncpy(book[i].name + 1, inputBuf, l_name);
                            book[i].name[0] = '"';
                            book[i].name[strlen(inputBuf)+1] = '"';
                            for(int j = strlen(inputBuf) + 2; j < l_name; j++)
                                book[i].name[j] = ' ';
                            book[i].name[l_name] = '\0';
                            printf("¬ведите год публикации: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_year)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            for(int j = strlen(inputBuf); j < 80; j++)
                                inputBuf[j] = ' ';
                            strncpy(book[i].year, inputBuf, l_year);
                            book[i].year[l_year] = '\0';
                            printf("¬ведите местоположение: ");
                            gets(inputBuf);
                            if(strlen(inputBuf) >= l_locale)
                            {
                                printf("—лишком длинные вводимые данные\n");
                                getch();
                                break;
                            }
                            fputs(" ", fp);
                            fputs(book[i].autor, fp);
                            fputs(book[i].name, fp);
                            fputs(book[i].year, fp);
                            fputs(inputBuf, fp);
                            fputs("\n", fp);
                            for(int j = strlen(inputBuf); j < 80; j++)
                                inputBuf[j] = ' ';
                            strncpy(book[i].locale, inputBuf, l_locale);
                            book[i].locale[l_locale] = '\0';
                        }
                    }
                    break;
                }
            case '4':
                {
                    not_found = 1;
                    printf("¬ведите шифр книги: ");
                    gets(inputBuf);
                    for(int i = 0; i < l_books; i++)
                    {
                        if(strstr(book[i].code, inputBuf) && book[i].name[0] != ' ')
                        {
                            printf("%s %s %s %s %s\n", book[i].code, book[i].autor, book[i].name, book[i].year, book[i].locale);
                            not_found = 0;
                        }
                    }
                    if(not_found)
                        printf(" нига не найдена\n");
                    getch();
                    break;
                }
            case 'q':
                {
                    fclose(fp);
                    return 0;
                }
            case 'й':
                {
                    fclose(fp);
                    return 0;
                }
            default:
                system("cls");
                continue;
        }
    }
    fclose(fp);
    return 0;
}
