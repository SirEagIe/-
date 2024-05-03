#include "VUZ.h"
#include <iostream>

using namespace std;

int VUZ::numVUZ = 0;
int VUZ::numStud = 0;

VUZ::VUZ() : name("0"), rectorName("0"), rankingPosition(0), studentNumber(0)
{
    cout << "Вызов конструктора без параметров при создании объекта " << this << endl;
    numVUZ++;
}

VUZ::VUZ(string _name, string _rectorName, int _rankingPosition, int _studentNumber) : name(_name), rectorName(_rectorName), rankingPosition(_rankingPosition), studentNumber(_studentNumber)
{
    cout << "Вызов конструктора c параметрами при создании объекта " << this << endl;
    numVUZ++;
    numStud += _studentNumber;
}

VUZ::VUZ(const VUZ& vuz) : name(vuz.name), rectorName(vuz.rectorName), rankingPosition(vuz.rankingPosition), studentNumber(vuz.studentNumber)
{
    cout << "Вызов конструктора копирования при создании объекта " << this << endl;
    numVUZ++;
    numStud += vuz.studentNumber;
}

VUZ::~VUZ()
{
    cout << "Вызов деструктора для объекта " << this << endl;
    numVUZ--;
}

//методы для установки значений данных объекта
void VUZ::setName(string _name)
{
    name = _name;
}

void VUZ::setRectorName(string _rectorName)
{
    rectorName = _rectorName;
}

void VUZ::setRankingPosition(int _rankingPosition)
{
    rankingPosition = _rankingPosition;
}

void VUZ::setStudentNumber(int _studentNumber)
{
    numStud -= studentNumber;
    studentNumber = _studentNumber;
    numStud += studentNumber;
}

void VUZ::set(string _name, string _rectorName, int _rankingPosition, int _studentNumber)
{
    numStud -= studentNumber;
    name = _name;
    rectorName = _rectorName;
    rankingPosition = _rankingPosition;
    studentNumber = _studentNumber;
    numStud += studentNumber;
}


//методы для получения значений данных объекта
string VUZ::getName()
{
    return name;
}

string VUZ::getRectorName()
{
    return rectorName;
}

int VUZ::getRankingPosition()
{
    return rankingPosition;
}

int VUZ::getStudentNumber()
{
    return studentNumber;
}

void VUZ::show()
{
    cout << name << " " << rectorName << " " << rankingPosition << " " << studentNumber << endl;
}


//дополнительные методы
void VUZ::upPosition()
{
    if(rankingPosition != 1)
    {
        rankingPosition--;
        cout << "Позиция ВУЗа в рейтинге поднялась с " << rankingPosition + 1 << " до " << rankingPosition << endl;
    }
}

void VUZ::downPosition()
{
    rankingPosition++;
    cout << "Позиция ВУЗа в рейтинге опустилась с " << rankingPosition - 1 << " до " << rankingPosition << endl;
}
//перегрузка дополнительных методов
void VUZ::upPosition(int num)
{
    if(rankingPosition - num > 0)
    {
        rankingPosition -= num;
        cout << "Позиция ВУЗа в рейтинге поднялась с " << rankingPosition + num << " до " << rankingPosition << endl;
    }
}

void VUZ::downPosition(int num)
{
    rankingPosition += num;
    cout << "Позиция ВУЗа в рейтинге опустилась с " << rankingPosition - num << " до " << rankingPosition << endl;
}

//работа со статической компонентой
int VUZ::avNumStud()
{
    return numStud/numVUZ;
}
