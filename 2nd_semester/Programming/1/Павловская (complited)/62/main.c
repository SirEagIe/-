#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");
    system("cls");
    const int l_name = 30, l_year = 5, l_pay = 10, l_buf = l_name + l_year + l_pay;
    struct Man {
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
    for(i = 0; i < n_record - 1; i++)
    {
        int imin = i;
        for(int j = i + 1; j < n_record; j++)
            if(dbase[j].birth_year < dbase[imin].birth_year)
                imin= j;
        struct Man a;
        a = dbase[i];
        dbase[i] = dbase[imin];
        dbase[imin] = a;
    }
    rewind(fp);
    for(i = 0; i < n_record; i++)
    {
        fputs(dbase[i].name, fp);
        fprintf(fp, "%d ", dbase[i].birth_year);
        fprintf(fp, "%d\n", (int)dbase[i].pay);
    }
    fclose(fp);
    printf("Сортировка базы данных завершена\n");
    return 0;
}
