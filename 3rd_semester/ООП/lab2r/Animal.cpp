#include "Animal.h"

//����������� ��� ����������, � �����������, ����������� � ����������
Animal::Animal() : name("0"), _class("0"), order("0"), averageWeight(0)
{
    cout << "������ " << this << " ��� ������ ������������� ��� ����������" << endl;
}

Animal::Animal(string nm, string cls, string ord, int avW) : name(nm), _class(cls), order(ord), averageWeight(avW)
{
    cout << "������ " << this << " ��� ������ ������������� � �����������" << endl;
}

Animal::Animal(Animal& a) : name(a.name), _class(a._class), order(a.order), averageWeight(a.averageWeight)
{
    cout << "������ " << this << " ��� ������ ������������� �����������" << endl;
}

Animal::~Animal()
{
    cout << "������ " << this << " ��� ���������" << endl;
}

//������ ��� ��������� ����� ������
void Animal::setName(string nm)
{
    name = nm;
}

void Animal::setClass(string cls)
{
    _class = cls;
}

void Animal::setOrder(string ord)
{
    order = ord;
}

void Animal::setAverageWeight(int avW)
{
    averageWeight = avW;
}

void Animal::set(string nm, string cls, string ord, int avW)
{
    name = nm;
    _class = cls;
    order = ord;
    averageWeight = avW;
}

//������ ��� ��������� ����� ������
string Animal::getName()
{
    return name;
}

string Animal::getClass()
{
    return _class;
}

string Animal::getOrder()
{
    return order;
}

int Animal::getAverageWeight()
{
    return averageWeight;
}

void Animal::show()
{
    cout << name << " - " << _class << " - " << order << " - " << averageWeight << endl;
}

//�������������� ������
void Animal::averageWeightUp(int num)
{
    averageWeight += num;
}

void Animal::averageWeightDown(int num)
{
    averageWeight -= num;
}
