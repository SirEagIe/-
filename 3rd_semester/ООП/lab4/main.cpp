#include <iostream>
#include <windows.h>
#include "Adres.h"

using namespace std;

bool operator==(Adres& a1, Adres& a2);
bool operator!=(Adres& a1, Adres& a2);

int main()
{
    system("chcp 1251");
    system("cls");
    //===================Объявление и инициализация массива адресов===================
    Adres adres[10];
    adres[0].set("Стародубов Осип Модестович", "Москва", "Центральная", 5);
    adres[1].set("Курочкин Григорий Евгениевич", "Хабаровск", "Набережная", 60);
    adres[2].set("Казьмин Дмитрий Трофимович", "Хабаровск", "Набережная", 68);
    adres[3].set("Бенедиктов Станислав Адамович", "Москва", "Центральная", 10);
    adres[4].set("Житков Никифор Потапович", "Хабаровск", "Набережная", 46);
    adres[5].set("Жиренков Игорь Тихонович", "Москва", "Центральная", 23);
    adres[6].set("Зубарев Фока Эдуардович", "Москва", "Центральная", 36);
    adres[7].set("Каипов Сидор Григориевич", "Хабаровск", "Садовая", 42);
    adres[8].set("Чичерин Иван Данилевич", "Хабаровск", "Садовая", 92);
    adres[9].set("Аношкин Кондрат Родионович", "Москва", "Центральная", 13);
    //==============================Вывод списка адресов==============================
    cout << "Неотсортированные адреса: " << endl << endl;
    for(int i = 0; i < 10; i++)
        adres[i].show();
    //=======================Сорторовка адресов по возрастанию========================
    bool isSort = false;
    while(isSort == false)
    {
        isSort = true;
        for(int i = 0; i < 9; i++)
        {
            if(adres[i] > adres[i+1])
            {
                Adres tmp = adres[i];
                adres[i] = adres[i+1];
                adres[i+1] = tmp;
                isSort = false;
            }
        }
    }
    //==============================Вывод списка адресов==============================
    cout << endl << "Адреса, отсортированные по возрастанию: " << endl << endl;
    for(int i = 0; i < 10; i++)
        adres[i].show();
    //=========================Сорторовка адресов по убыванию=========================
    isSort = false;
    while(isSort == false)
    {
        isSort = true;
        for(int i = 0; i < 9; i++)
        {
            if(adres[i] < adres[i+1])
            {
                Adres tmp = adres[i];
                adres[i] = adres[i+1];
                adres[i+1] = tmp;
                isSort = false;
            }
        }
    }
    //==============================Вывод списка адресов==============================
    cout << endl << "Адреса, отсортированные по убыванию: " << endl << endl;
    for(int i = 0; i < 10; i++)
        adres[i].show();
    //========================Демонстрация операторов ++ и --=========================
    cout << endl << "Демонстрация операторов ++ и --: " << endl << endl;
    cout << "adres[0]: ";
    adres[0].show();
    cout << "adres[0]++: ";
    (adres[0]++).show();
    cout << "++adres[0]: ";
    (++adres[0]).show();
    cout << "adres[0]--: ";
    (adres[0]--).show();
    cout << "--adres[0]: ";
    (--adres[0]).show();
    //================= Дружественныые операторные функции == и != ===================
    if(adres[0] == adres[1])
    {
        cout << endl << "Адреса" << endl;
        adres[0].show();
        cout << "и" << endl;
        adres[1].show();
        cout << "равны" << endl;
    }
    if(adres[0] != adres[1])
    {
        cout << endl << "Адреса" << endl;
        adres[0].show();
        cout << "и" << endl;
        adres[1].show();
        cout << "не равны" << endl;
    }
    return 0;
}

bool operator==(Adres& a1, Adres& a2)
{
    if(a1.city == a2.city && a1.street == a2.street && a1.number == a2.number)
        return true;
    else
        return false;
}

bool operator!=(Adres& a1, Adres& a2)
{
    if(a1.city == a2.city && a1.street == a2.street && a1.number == a2.number)
        return false;
    else
        return true;
}
