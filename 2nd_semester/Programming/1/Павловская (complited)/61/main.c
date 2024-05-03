#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>

int main()
{
    system("chcp 1251");
    system("cls");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    const int l_name = 30, l_year = 5, l_pay = 10, l_buf = l_name + l_year + l_pay;
    struct Man
    {
        int birth_year;
        char name[l_name + 1];
        float pay;
    };
    const int l_dbase = 100;
    struct Man dbase[l_dbase];
    char buf[l_buf + 1];
    char name[l_name + 1];
    FILE *fp;
    fp = fopen("dbase.txt", "r+");
    if(fp == NULL)
    {
        printf("Ошибка чтения файла\n");
        exit(1);
    }
    int i = 0;
    while(fgets(buf, l_buf, fp))
    {
        if( i >= l_dbase)
        {
            printf("Слишком большой файл\n");
            return 1;
        }
        strncpy(dbase[i].name, buf, l_name);
        dbase[i].name[l_name] = '\0';
        dbase[i].birth_year = atoi(&buf[l_name]);
        dbase[i].pay = atof(&buf[l_name + l_year]);
        //printf("%s\n%d\n%f\n", dbase[i].name, dbase[i].birth_year, dbase[i].pay);
        i++;
    }
    int n_record = i;
    int n_man = 0;
    float mean_pay = 0;
    while(1)
    {
        printf("Введите фамилию: ");
        scanf("%s", &name);
        if(strcmp(name, "end") == 0)
            break;
        int not_found = 1;
        for(i = 0; i < n_record; i++)
        {
            if(strstr(dbase[i].name, name))
            {
                if(dbase[i].name[strlen(name)] == ' ')
                {
                    strcpy(name, dbase[i].name);
                    printf("%s%i %.2f\n", name, dbase[i].birth_year, dbase[i].pay);
                    n_man++;
                    mean_pay += dbase[i].pay;
                    not_found = 0;
                }
            }
        }
        if(not_found)
            printf("Такого сторудника нет\n");

    }
    if(n_man > 0)
        printf("Средний оклад - %.2f\n", mean_pay/n_man);
    fclose(fp);
    return 0;
}
