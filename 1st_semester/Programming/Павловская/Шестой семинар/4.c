#include <stdio.h>
#include <stdlib.h>

struct Man
{
    int birth_year;
    char name[31];
    float pay;
};

int compare(const void *man1, const void *man2);

int main()
{
    system("chcp 1251");
    system("cls");
    FILE *fbin;
    fbin = fopen("dbase.bin", "r+");
    if(fbin == NULL)
    {
        printf("Ошибка чтения файла\n");
        exit(1);
    }
    fseek(fbin, 0, SEEK_END);
    int n_record = ftell(fbin) / sizeof(struct Man);
    fseek(fbin, 0, SEEK_SET);
    struct Man* man = (struct Man*)malloc(n_record * sizeof(struct Man));
    if(man == NULL)
    {
        printf("Ошибка распределения памяти\n");
        exit(1);
    }
    fread(man, sizeof(struct Man), n_record, fbin);
    fclose(fbin);
    qsort(man, n_record, sizeof(struct Man), compare);
    for(int i = 0; i < n_record; i++)
    {
        printf("%s%5i%10.2f\n", man[i].name, man[i].birth_year, man[i].pay);
    }
    free(man);
    return 0;
}

int compare(const void *man1, const void *man2)
{
    return strcmp(((struct Man*)man1)->name, ((struct Man*)man2)->name);
}
