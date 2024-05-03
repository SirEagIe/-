#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");
    system("cls");
    const int l_name = 30;
    struct
    {
        int birth_year;
        char name[l_name + 1];
        float pay;
    } man;
    FILE *fout;
    fout = fopen("dbase.bin", "r+");
    if(fout == NULL)
    {
        printf("Ошибка чтения файла\n");
        exit(1);
    }
    fseek(fout, 0, SEEK_END);
    int n_record = ftell(fout) / sizeof(man);
    int num;
    while(1)
    {
        puts("Введите номер записи или -1: ");
        scanf("%i", &num);
        if(num < 0 || num >= n_record)
            break;
        fseek(fout, num * sizeof(man), SEEK_SET);
        fread(&man, sizeof(man), 1, fout);
        printf("%s%5i%10.2f\n", man.name, man.birth_year, man.pay);
        puts("Введите новый оклад: ");
        scanf("%f", &man.pay);
        fseek(fout, num * sizeof(man), SEEK_SET);
        fwrite(&man, sizeof(man), 1, fout);
        printf("%s%5i%10.2f\n", man.name, man.birth_year, man.pay);
    }
    fclose(fout);
    printf("Корректировка завершена\n");
    return 0;
}
