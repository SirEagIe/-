#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int l_name = 30;
    struct
    {
        int birth_year;
        char name[l_name + 1];
        float pay;
    } man;
    FILE *fin;
    fin = fopen("dbase.txt", "r");
    if(fin == NULL)
    {
        printf("ќшибка чтени¤ файла\n");
        exit(1);
    }
    FILE *fout;
    fout = fopen("dbase.bin", "wb");
    if(fout == NULL)
    {
        printf("ќшибка чтени¤ файла\n");
        exit(1);
    }
    while(!feof(fin))
    {
        fgets(man.name, l_name, fin);
        fscanf(fin, "%i%f\n", &man.birth_year, &man.pay);
        printf("%s%5i%10.2f\n", man.name, man.birth_year, man.pay);
        fwrite(&man, sizeof(man), 1, fout);
    }
    fclose(fout);
    printf("Ѕинарный файл записан\n");
    return 0;
}
