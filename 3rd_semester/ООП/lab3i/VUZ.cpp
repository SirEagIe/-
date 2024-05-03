#include "VUZ.h"
#include <iostream>

using namespace std;

int VUZ::numVUZ = 0;
int VUZ::numStud = 0;

VUZ::VUZ() : name("0"), rectorName("0"), rankingPosition(0), studentNumber(0)
{
    cout << "����� ������������ ��� ���������� ��� �������� ������� " << this << endl;
    numVUZ++;
}

VUZ::VUZ(string _name, string _rectorName, int _rankingPosition, int _studentNumber) : name(_name), rectorName(_rectorName), rankingPosition(_rankingPosition), studentNumber(_studentNumber)
{
    cout << "����� ������������ c ����������� ��� �������� ������� " << this << endl;
    numVUZ++;
    numStud += _studentNumber;
}

VUZ::VUZ(const VUZ& vuz) : name(vuz.name), rectorName(vuz.rectorName), rankingPosition(vuz.rankingPosition), studentNumber(vuz.studentNumber)
{
    cout << "����� ������������ ����������� ��� �������� ������� " << this << endl;
    numVUZ++;
    numStud += vuz.studentNumber;
}

VUZ::~VUZ()
{
    cout << "����� ����������� ��� ������� " << this << endl;
    numVUZ--;
}

//������ ��� ��������� �������� ������ �������
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


//������ ��� ��������� �������� ������ �������
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


//�������������� ������
void VUZ::upPosition()
{
    if(rankingPosition != 1)
    {
        rankingPosition--;
        cout << "������� ���� � �������� ��������� � " << rankingPosition + 1 << " �� " << rankingPosition << endl;
    }
}

void VUZ::downPosition()
{
    rankingPosition++;
    cout << "������� ���� � �������� ���������� � " << rankingPosition - 1 << " �� " << rankingPosition << endl;
}
//���������� �������������� �������
void VUZ::upPosition(int num)
{
    if(rankingPosition - num > 0)
    {
        rankingPosition -= num;
        cout << "������� ���� � �������� ��������� � " << rankingPosition + num << " �� " << rankingPosition << endl;
    }
}

void VUZ::downPosition(int num)
{
    rankingPosition += num;
    cout << "������� ���� � �������� ���������� � " << rankingPosition - num << " �� " << rankingPosition << endl;
}

//������ �� ����������� �����������
int VUZ::avNumStud()
{
    return numStud/numVUZ;
}
