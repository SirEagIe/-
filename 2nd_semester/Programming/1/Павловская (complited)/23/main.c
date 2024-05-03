#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()
{   while (1==1)
    {
    int key;
    setlocale(LC_ALL, "rus");
    printf("Нажмите на одну из курсорных клавишей:\n");
    key = getch();
    key = getch();
    switch(key){
        case 77: printf("стрелка вправо\n");
        break;
        case 75: printf("стрелка влево\n");
        break;
        case 72: printf("стрелка вверх\n");
        break;
        case 80: printf("стрелка вниз\n");
        break;
        default: printf("не стрелка\n");
    }
    }
    return 0;
}
