#include <iostream>
#include <conio.h>
#include "classes.h"

using namespace std;

int main()
{
    system("chcp 1251");
    while(true)
    {
        system("cls");
        cout << "Создать: " << endl << "1. Журнал" << endl << "2. Книгу" << endl << "3. Учебник" << endl << endl;
        char key;
        key = getch();
        if(key == '1')
        {
            string name = "Times";
            int yearOfPublication = 2020;
            int price = 350;
            int monthOfPublication = 12;
            PrintEdition *m = new Magazine(name, yearOfPublication, price, monthOfPublication);
            cout << endl;
            m->showInfo();
            cout << endl;
            delete m;
            system("pause");
        }
        if(key == '2')
        {
            string name = "Война и мир";
            int yearOfPublication = 1996;
            int price = 250;
            string authorName = "Л. Н. Толстой";
            PrintEdition *b = new Book(name, yearOfPublication, price, authorName);
            cout << endl;
            b->showInfo();
            cout << endl;
            delete b;
            system("pause");
        }
        if(key == '3')
        {
            string name = "Язык программирования C++";
            int yearOfPublication = 1986;
            int price = 350;
            string authorName = "Бьёрн Страуструп";
            string subject = "Программирование";
            PrintEdition *t = new Textbook(name, yearOfPublication, price, authorName, subject);
            cout << endl;
            t->showInfo();
            cout << endl;
            delete t;
            system("pause");
        }
        if(key == 'q')
            break;
    }
    return 0;
}
