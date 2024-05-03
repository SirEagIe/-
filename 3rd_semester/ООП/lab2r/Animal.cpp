#include "Animal.h"

//конструктор без параметров, с параметрами, копирования и деструктор
Animal::Animal() : name("0"), _class("0"), order("0"), averageWeight(0)
{
    cout << "Объект " << this << " был создан конструктором без параметров" << endl;
}

Animal::Animal(string nm, string cls, string ord, int avW) : name(nm), _class(cls), order(ord), averageWeight(avW)
{
    cout << "Объект " << this << " был создан конструктором с параметрами" << endl;
}

Animal::Animal(Animal& a) : name(a.name), _class(a._class), order(a.order), averageWeight(a.averageWeight)
{
    cout << "Объект " << this << " был создан конструктором копирования" << endl;
}

Animal::~Animal()
{
    cout << "Объект " << this << " был уничтожен" << endl;
}

//методы для изменения полей данных
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

//методы для просмотра полей данных
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

//дополнительные методы
void Animal::averageWeightUp(int num)
{
    averageWeight += num;
}

void Animal::averageWeightDown(int num)
{
    averageWeight -= num;
}
