#include <iostream>
#include <windows.h>
#include "Animal.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");

    cout << endl  << "���������� �������� � ����������� ������:" << endl;
    {
        Animal a1;
        a1.show();
        Animal a2("����", "�������������", "������", 200);
        a2.show();
        Animal a3 = a2;
        a3.show();
    }

    cout << endl << "���������� �������� � ������������ ������:" << endl;
    Animal *a4 = new Animal;
    a4->set("�������� �����", "�������������", "�������������", 170);
    a4->show();
    delete a4;

    cout << endl << "���������� �������� � ����������� �������:" << endl;
    {
        Animal a5[2];
        a5[0].set("����", "�������������", "��������", 6000);
        a5[1].set("�������", "�������������", "�������������", 1500);
        a5[0].show();
        a5[1].show();
    }

    cout << endl << "���������� �������� � ������������ �������:" << endl;
    Animal *a6 = new Animal[2];
    a6[0].set("����� �������", "�������������", "������", 450);
    a6[0].show();
    a6[1].set("����� �������", "�������������", "������", 500);
    a6[1].show();
    delete [] a6;

    cout << endl << "��������� � ��������� ����� ������:" <<  endl;
    Animal a7;
    string name;
    string _class;
    string order;
    int averageWeight;
    cout << "��������: ";
    cin >> name;
    cout << "�����: ";
    cin >> _class;
    cout << "�����: ";
    cin >> order;
    cout << "������� ���: ";
    cin >> averageWeight;
    a7.setName(name);
    a7.setClass(_class);
    a7.setOrder(order);
    a7.setAverageWeight(averageWeight);
    cout << "��������: " << a7.getName() << endl;
    cout << "�����: " << a7.getClass() << endl;
    cout << "�����: " << a7.getOrder() << endl;
    cout << "������� ���: " << a7.getAverageWeight() << endl;

    cout << endl << "�������������� ������:" << endl;
    a7.show();
    a7.averageWeightDown(10);
    a7.show();
    a7.averageWeightUp(50);
    a7.show();
    return 0;
}
