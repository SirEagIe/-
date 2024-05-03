#include <iostream>
#include "windows.h"
#include "classes.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    cout << "----------------------------�������� �������----------------------------" << endl;
    {
        PrintEdition pe("�������� �������", 2010, 450);
        cout << endl;
        pe.showInfo();
        cout << endl;
    }
    cout << "---------------------------------������---------------------------------" << endl;
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
    cout << "---------------------------------�����----------------------------------" << endl;
    {
        Book b("����� � ���", 1996, 250, "�. �. �������");
        cout << endl;
        b.showInfo();
        cout << endl;
    }
    cout << "--------------------------------�������---------------------------------" << endl;
    {
        Textbook tb1("���� ���������������� C++", 1986, 350, "����� ����������", "����������������");
        Textbook tb2 = tb1;
        cout << endl;
        tb2.showInfo();
        cout << endl;
    }


    return 0;
}
