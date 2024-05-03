#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() : name("0"), vuz("0")
{
    cout << "����� ������������ ��� ���������� ��� �������� ������� " << this << endl;
}

Student::Student(string _name, string _vuz) : name(_name), vuz(_vuz)
{
    cout << "����� ������������ c ����������� ��� �������� ������� " << this << endl;
}

Student::Student(const Student& S) : name(S.name), vuz(S.vuz)
{
    cout << "����� ������������ ����������� ��� �������� ������� " << this << endl;
}

Student::~Student()
{
    cout << "����� ����������� ��� ������� " << this << endl;
}

//������ ��� ��������� �������� ������ �������
void Student::setName(string _name)
{
    name = _name;
}

void Student::setVUZ(string _vuz)
{
    vuz = _vuz;
}

void Student::set(string _name, string _vuz)
{
    name = _name;
    vuz = _vuz;
}

//������ ��� ��������� �������� ������ �������
string Student::getName()
{
    return name;
}

string Student::getVUZ()
{
    return vuz;
}

void Student::show()
{
    cout << name << " " << vuz << endl;
}
