#include <iostream>
#include "Student.h"
#include "VUZ.h"

using namespace std;

void oper(VUZ&, Student&);

int main()
{
    system("chcp 1251");

    VUZ VUZ1("����", "��������� ������ ����������", 93, 17000);
    VUZ VUZ2("����", "������ ������� ��������", 25, 23000);
    VUZ VUZ3("���", "������ ��������� ����������", 13, 38000);
    //������������ ������ �� ����������� �����������
    cout << endl << "������� ���������� ���������: " << VUZ::avNumStud() << endl << endl;
    cout << "---------------------------------------" << endl;
    Student st("������� ���� ����������", "����");
    //������������ ������ � ������������� ��������
    oper(VUZ1, st);
    cout << endl;
    oper(VUZ2, st);
    cout << "---------------------------------------" << endl << endl;
    //������������ ������ � �����������
    VUZ1.upPosition();
    VUZ1.downPosition();

    VUZ1.upPosition(17);
    VUZ1.downPosition(13);
    cout << "---------------------------------------" << endl << endl;
    return 0;
}

void oper(VUZ& vuz, Student& stud)
{
    if(stud.vuz == vuz.name)
    {
        cout << stud.name << " ��������� � ���� " << vuz.name << endl;
        cout << "������� ���� � �������� - " << vuz.rankingPosition << endl;
    }
    else
    {
        cout << stud.name << " �� ��������� � ���� " << vuz.name << endl;
    }
}
