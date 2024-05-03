#include <stdio.h>
#include <string.h>
#include <locale.h>

int nxt_blnk(char* str, int pos);

int main()
{
    setlocale(LC_CTYPE, "rus");
    char text[100] = {0};                 //Тестовый текст
    int n;
    setlocale(LC_CTYPE, "rus");
    printf("Введите текст: \n");
    gets(text);
    printf("Введите номер символа: \n");
    scanf("%d", &n);
    printf("Первый пробел после %d символа - %d", n, nxt_blnk(text, n - 1));
    return 0;
}

int nxt_blnk(char* str, int pos)
{
    int result;
    if(pos < 0 || pos > strlen(str))
        return -1;
    for(int i = pos + 1; i < strlen(str); i++)
    {
        if(str[i] == ' ')
        {
            result = i;
            return result + 1;
        }
    }
    return 0;
}
