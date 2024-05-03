#include <iostream>
#include <windows.h>
#include "Animal.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");

    cout << endl  << "Размещение объектов в статической памяти:" << endl;
    {
        Animal a1;
        a1.show();
        Animal a2("Тигр", "Млекопитающие", "Хищные", 200);
        a2.show();
        Animal a3 = a2;
        a3.show();
    }

    cout << endl << "Размещение объектов в динамической памяти:" << endl;
    Animal *a4 = new Animal;
    a4->set("Северный олень", "Млекопитающие", "Парнокопытные", 170);
    a4->show();
    delete a4;

    cout << endl << "Размещение объектов в статическом массиве:" << endl;
    {
        Animal a5[2];
        a5[0].set("Слон", "Млекопитающие", "Хоботные", 6000);
        a5[1].set("Бегемот", "Млекопитающие", "Парнокопытные", 1500);
        a5[0].show();
        a5[1].show();
    }

    cout << endl << "Размещение объектов в динамическом массиве:" << endl;
    Animal *a6 = new Animal[2];
    a6[0].set("Белый медведь", "Млекопитающие", "Хищные", 450);
    a6[0].show();
    a6[1].set("Бурый медведь", "Млекопитающие", "Хищные", 500);
    a6[1].show();
    delete [] a6;

    cout << endl << "Установка и получение полей данных:" <<  endl;
    Animal a7;
    string name;
    string _class;
    string order;
    int averageWeight;
    cout << "Название: ";
    cin >> name;
    cout << "Класс: ";
    cin >> _class;
    cout << "Отряд: ";
    cin >> order;
    cout << "Средний вес: ";
    cin >> averageWeight;
    a7.setName(name);
    a7.setClass(_class);
    a7.setOrder(order);
    a7.setAverageWeight(averageWeight);
    cout << "Название: " << a7.getName() << endl;
    cout << "Класс: " << a7.getClass() << endl;
    cout << "Отряд: " << a7.getOrder() << endl;
    cout << "Средний вес: " << a7.getAverageWeight() << endl;

    cout << endl << "Дополнительные методы:" << endl;
    a7.show();
    a7.averageWeightDown(10);
    a7.show();
    a7.averageWeightUp(50);
    a7.show();
    return 0;
}
