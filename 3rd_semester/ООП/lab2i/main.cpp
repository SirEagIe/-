#include <iostream>
#include <windows.h>
#include "VUZ.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");

    cout << "������� � ����������� ������:" << endl << endl;
    {
        VUZ VUZ1;
        VUZ1.show();
        VUZ VUZ2("����", "��������� ������ ����������", 93, 17000);
        VUZ2.show();
        VUZ VUZ3 = VUZ2;
        VUZ3.show();
    }

    cout << endl << "������� � ������������ ������:" << endl << endl;
    VUZ *VUZ4 = new VUZ;
    VUZ4->show();
    VUZ *VUZ5 = new VUZ("����", "��������� ������ ����������", 93, 17000);
    VUZ5->show();
    VUZ *VUZ6 = new VUZ(*VUZ5);
    VUZ6->show();
    delete VUZ4;
    delete VUZ5;
    delete VUZ6;

    cout << endl << "������� � ����������� �������:" << endl << endl;
    {
        VUZ arr1[2] = {VUZ("����", "��������� ������ ����������", 93, 17000), VUZ("����", "	������ ������� ��������", 25, 23000)};
        arr1[0].set("����", "��������� ������ ����������", 93, 17000);
        arr1[0].show();
        arr1[1].set("����", "������ ������� ��������", 25, 23000);
        arr1[1].show();
    }

    cout << endl << "������� � ������������ �������:" << endl << endl;
    VUZ *arr2 = new VUZ[2];
    arr2[0].set("����", "��������� ������ ����������", 93, 17000);
    arr2[0].show();
    arr2[1].set("����", "������ ������� ��������", 25, 23000);
    arr2[1].show();
    delete [] arr2;

    cout << endl << "��������� � ��������� ����� ������:" << endl << endl;
    VUZ VUZ7;
    string name;
    string rectorName;
    int rankingPosition;
    int studentNumber;

    cout << "������� �������� ����: ";
    getline(cin, name, '\n');

    cout << "������� ��� �������: ";
    getline(cin, rectorName, '\n');

    cout << "������� ������� � ��������: ";
    cin >> rankingPosition;

    cout << "������� ���������� ���������: ";
    cin >> studentNumber;

    VUZ7.setName(name);
    VUZ7.setRectorName(rectorName);
    VUZ7.setRankingPosition(rankingPosition);
    VUZ7.setStudentNumber(studentNumber);

    cout << endl;

    cout << "�������� ����: " << VUZ7.getName() << endl;
    cout << "��� �������: " << VUZ7.getRectorName() << endl;
    cout << "������� � ��������: " << VUZ7.getRankingPosition() << endl;
    cout << "���������� ���������: " << VUZ7.getStudentNumber() << endl;

    cout << endl << "������������ �������������� �������, ��������������� ��������� �������:" << endl << endl;
    VUZ7.upPosition();
    VUZ7.downPosition();

    return 0;
}
