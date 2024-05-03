#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() : name("0"), vuz("0")
{
    cout << "Вызов конструктора без параметров при создании объекта " << this << endl;
}

Student::Student(string _name, string _vuz) : name(_name), vuz(_vuz)
{
    cout << "Вызов конструктора c параметрами при создании объекта " << this << endl;
}

Student::Student(const Student& S) : name(S.name), vuz(S.vuz)
{
    cout << "Вызов конструктора копирования при создании объекта " << this << endl;
}

Student::~Student()
{
    cout << "Вызов деструктора для объекта " << this << endl;
}

//методы для установки значений данных объекта
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

//методы для получения значений данных объекта
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
