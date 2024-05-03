#include <iostream>
#include "windows.h"
#include "Adres.h"
#include "ManagementCompany.h"

using namespace std;

void oper(ManagementCompany&);

int main()
{
    system("chcp 1251");
    system("cls");
    //Создание и инициализация управляющих компаний
    ManagementCompany CompA("CompA", "Вихорев Владлен Алексндрович");
    ManagementCompany CompB("CompB", "Кайпанов Капитон Леонидович");
    //Создание и инициализация адресов для первой компании
    Adres adres11("Умников Филипп Глебович", "Хабаровск", "ул. Гагарина", 1);
    adres11.setManagementCompany(CompA);
    Adres adres12("Верясов Юрий Ефремович", "Хабаровск", "ул. Гагарина", 2);
    adres12.setManagementCompany(CompA);
    Adres adres13("Колесов Панкратий Венедиктович", "Хабаровск", "ул. Гагарина", 3);
    adres13.setManagementCompany(CompA);
    //Создание и инициализация адресов для второй компании
    Adres adres21("Костомаров Игнат Климентович", "Хабаровск", "ул. Пушкина", 1);
    adres21.setManagementCompany(CompB);
    Adres adres22("Ягодников Валентин Саввевич", "Хабаровск", "ул. Пушкина", 2);
    adres22.setManagementCompany(CompB);
    Adres adres23("Добрынин Филимон Гордеевич", "Хабаровск", "ул. Пушкина", 3);
    adres23.setManagementCompany(CompB);
    //Реализация операции
    oper(CompA);
    cout << endl;
    //Работа со статической компонентой
    cout << "Количество людей, проживающий на ул. Пушкина: " << Adres::getNumOnStreet() << endl;
    cout << endl;
    //Реализация перегрузки функции
    CompA.find();
    cout << endl;
    CompB.find("Костомаров Игнат Климентович");
    cout << endl;
    return 0;
}

void oper(ManagementCompany& mc)
{
    cout << "Введите имя человека: " << endl;
    string tmpName;
    getline(cin, tmpName, '\n');
    int isFinded = false;
    for(int i = 0; i < mc.count; i++)
    {
        if(mc.adres[i]->getName() == tmpName)
        {
            isFinded = true;
            cout << "Имя директора компании " << mc.name << ", обслуживающей " << tmpName << " - " << mc.getNameDirector() << endl;
        }
    }
    if(!isFinded)
    {
        cout << tmpName << " не обслуживается в компании " << mc.name << endl;
    }
}

