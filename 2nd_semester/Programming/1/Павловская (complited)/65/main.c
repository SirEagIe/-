#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("chcp 1251");
    system("cls");
    struct aeroflot
    {
        char name[20];
        int num;
        char type[20];
    };
    struct aeroflot plane[7];
    printf("Ввведите название, номер рейса и тип самолёта: ");
    for(int i = 0; i < 7; i++)
    {
        scanf("%s%d%s", &plane[i].name, &plane[i].num, &plane[i].type); //Хабаровск 1010 AirbusA320 Москва 1011 AirbusA320 Хабаровск 1012 AirbusA310 Москва 1013 AirbusA310 Санкт-Петербург 1014 AirbusA320 Санкт-Петербург 1015 AirbusA310 Хабаровск 1016 AirbusA320
    }

    for(int i = 0; i < 7; i++)
    {
        int imin = i;
        for(int j = i + 1; j < 7; j++)
            if(strcmpi(plane[j].name, plane[imin].name) < 0)
                imin= j;
        struct aeroflot a;
        a = plane[i];
        plane[i] = plane[imin];
        plane[imin] = a;
    }

    for(int i = 0; i < 7; i++)
    {
        printf("%-20s %-7d %s\n", plane[i].name, plane[i].num, plane[i].type);
    }
    printf("Введите тип самолёта: ");
    char buf[20];
    scanf("%s", &buf);                  //AirbusA320
    int not_found = 1;
    for(int i = 0; i < 7; i++)
    {
        if(strstr(plane[i].type, buf))
            {
                printf("%-20s %-7d %s\n", plane[i].name, plane[i].num, plane[i].type);
                not_found = 0;
            }
    }
    if(not_found == 1)
        printf("Рейсы не найдены\n");
    return 0;
}
