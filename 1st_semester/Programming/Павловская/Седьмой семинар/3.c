#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int num_num(const char *str);

int main()
{
    setlocale(LC_CTYPE, "rus");
    char str[101];
    printf("Введите текст: \n");    //2 + 2 = 4
    gets(str);
    printf("В строке содержится %d чисел", num_num(str));
    return 0;
}

int num_num(const char *str)
{
    int count = 0;
    while(*str)
    {
        if(isdigit(*str) && ! isdigit(*(str + 1)) && *(str + 1) != '.')
            count++;
        str++;
    }
    return count;
}
