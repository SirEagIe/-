#include <iostream>
#include "windows.h"
#include "classes.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    cout << "----------------------------Печатное издание----------------------------" << endl;
    {
        PrintEdition pe("Толковый словарь", 2010, 450);
        cout << endl;
        pe.showInfo();
        cout << endl;
    }
    cout << "---------------------------------Журнал---------------------------------" << endl;
    {
        Magazine m;
        m.setName("Times");
        m.setYearOfPublication(2020);
        m.setPrice(350);
        m.setMonthOfPublication(12);
        cout << endl;
        m.showInfo();
        cout << endl;
    }
    cout << "---------------------------------Книга----------------------------------" << endl;
    {
        Book b("Война и мир", 1996, 250, "Л. Н. Толстой");
        cout << endl;
        b.showInfo();
        cout << endl;
    }
    cout << "--------------------------------Учебник---------------------------------" << endl;
    {
        Textbook tb1("Язык программирования C++", 1986, 350, "Бьёрн Страуструп", "Программирование");
        Textbook tb2 = tb1;
        cout << endl;
        tb2.showInfo();
        cout << endl;
    }


    return 0;
}
