#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};

void dateInterval();
void nDay();
void printnDay();

int main()
{
    system("chcp 1251");
    system("cls");
    while(1)
    {
        system("cls");
        printf("1 - вычисление интервала между датами\n2 - вычисление даты n-го дн¤\n3 - вывод n дней вперЄд от заданной даты\n");
        char ch = getch();
        switch(ch)
        {
            case '1':
                system("cls");
                dateInterval();
                getch();
                break;
            case '2':
                system("cls");
                nDay();
                getch();
                break;
            case '3':
                system("cls");
                printnDay();
                getch();
                break;
            case 'q':
                return 0;
                break;
            case 'й':
                return 0;
                break;
            default:
                continue;
        }
    }
    return 0;
}

void dateInterval()
{
    struct date date1;
    struct date date2;
    printf("¬ведите первую дату: ");
    scanf("%d%d%d", &date1.day, &date1.month, &date1.year);
    if(date1.day < 0 || date1.month < 0 || date1.year < 0 || date1.day > 31 || date1.month > 12)
    {
        printf("ќшибка ввода\n");
        exit(1);
    }
    printf("¬ведите вторую дату: ");
    scanf("%d%d%d", &date2.day, &date2.month, &date2.year);
    if(date2.day < 0 || date2.month < 0 || date2.year < 0 || date2.day > 31 || date2.month > 12)
    {
        printf("ќшибка ввода\n");
        exit(1);
    }
    int interval = 0;
    if(date1.year > date2.year || ((date1.year == date2.year) && date1.month > date2.month) || ((date1.year == date2.year) && (date1.month == date2.month) && date1.day > date2.day))
    {
        struct date temp;
        temp = date1;
        date1 = date2;
        date2 = temp;
    }
    for(int i = date1.year; i < date2.year; i++)
    {
        if(i % 4 == 0)
            interval += 366;
        else
            interval += 365;
    }
    if(date1.month > date2.month)
    {
        for(int i = date2.month; i < date1.month; i++)
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                interval += 31;
            if(i ==  4 || i == 6 || i == 9 || i == 11)
                interval += 30;
            if(i == 12)
                interval += 28;
        }
    }
    else
    {
        for(int i = date1.month; i < date2.month; i++)
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                interval += 31;
            if(i ==  4 || i == 6 || i == 9 || i == 11)
                interval += 30;
            if(i == 12)
                interval += 28;
        }
    }
    if(date1.day > date1.day)
        interval += date1.day - date2.day;
    else
        interval += date2.day - date1.day;
    printf("»нтервал - %d д.\n", interval);
}

void printnDay()
{
    int n;
    struct date date1;
    printf("¬ведите дату: ");
    scanf("%d%d%d", &date1.day, &date1.month, &date1.year);
    printf("¬ведите количество дней: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        date1.day++;
        if((date1.month == 1 || date1.month == 3 || date1.month == 5 || date1.month == 7 || date1.month == 8 || date1.month == 10 || date1.month == 12) && date1.day == 32)
        {
            date1.month++;
            date1.day = 1;
        }
        if((date1.month == 4 || date1.month == 6 || date1.month == 9 || date1.month == 11) && date1.day == 31)
        {
            date1.month++;
            date1.day = 1;
        }
        if((date1.month == 2) && (date1.year % 4 == 0) && date1.day == 30)
        {
            date1.month++;
            date1.day = 1;
        }
        if((date1.month == 2) && (date1.year % 4 != 0) && date1.day == 29)
        {
            date1.month++;
            date1.day = 1;
        }
        if(date1.month > 12)
        {
            date1.month = 1;
            date1.year++;
        }
        printf("%02d.%02d.%d\n", date1.day, date1.month, date1.year);
    }
}

void nDay()
{
    int n;
    struct date date1;
    printf("¬ведите пор¤дковый номер: ");
    scanf("%d", &n);
    if(n > 365)
        return 0;
    date1.day = 0;
    date1.month = 1;
    date1.year = 1;
    for(int i = 0; i < n; i++)
    {
        date1.day++;
        if((date1.month == 1 || date1.month == 3 || date1.month == 5 || date1.month == 7 || date1.month == 8 || date1.month == 10 || date1.month == 12) && date1.day == 32)
        {
            date1.month++;
            date1.day = 1;
        }
        if((date1.month == 4 || date1.month == 6 || date1.month == 9 || date1.month == 11) && date1.day == 31)
        {
            date1.month++;
            date1.day = 1;
        }
        if((date1.month == 2) && date1.day == 29)
        {
            date1.month++;
            date1.day = 1;
        }
    }
    printf("ƒата - %02d.%02d", date1.day, date1.month);
}
