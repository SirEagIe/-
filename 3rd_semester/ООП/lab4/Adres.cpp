#include <iostream>
#include "Adres.h"

using namespace std;

int Adres::numOnStreet = 0;

//����������� ��� ����������
Adres::Adres(): name("---"), city("---"), street("---"), number(0) {}

//����������� � �����������
Adres::Adres(string _name, string _city, string _street, int _number)
{
	name = _name;
	city = _city;
	street = _street;
	number = _number;
	if(street == "��. �������")
        numOnStreet++;
}

//����������� �����������
Adres::Adres(const Adres& adres)
{
	name = adres.name;
	city = adres.city;
	street = adres.street;
	number = adres.number;
	if(street == "��. �������")
        numOnStreet++;
}

//����������
Adres::~Adres()
{
	if(street == "��. �������")
        numOnStreet--;
}

//������ ��� ��������� ����� ������
void Adres::setName(string _name)
{
	name = _name;
}
void Adres::setCity(string _city)
{
	city = _city;
}
void Adres::setStreet(string _street)
{
    if(street == "��. �������")
        numOnStreet--;
	street = _street;
	if(street == "��. �������")
        numOnStreet++;
}
void Adres::setNumber(int _number)
{
	number = _number;
}
void Adres::set(string _name, string _city, string _street, int _number)
{
    if(street == "��. �������")
        numOnStreet--;
    name = _name;
	city = _city;
	street = _street;
	number = _number;
	if(street == "��. �������")
        numOnStreet++;
}

//������ ��� ��������� ����� ������
string Adres::getName()
{
	return name;
}
string Adres::getCity()
{
	return city;
}
string Adres::getStreet()
{
	return street;
}
int Adres::getNumber()
{
	return number;
}
void Adres::show()
{
	cout << name << " - " << city << " - " << street << " " << number << endl;
}

//�������������� �����
void Adres::whoLivesHere()
{
    cout << "�� ������ " << city << ", " << street << " " << number << " ��������� " << name << endl;
}

//������ �� ����������� �����������
int Adres::getNumOnStreet()
{
    return numOnStreet;
}

//���������� ����������
bool Adres::operator<(Adres& a)
{
    if((city < a.city) || (city == a.city && street < a.street) || (city == a.city && street == a.street && number < a.number))
        return true;
    else
        return false;
}

bool Adres::operator>(Adres& a)
{
    if((city > a.city) || (city == a.city && street > a.street) || (city == a.city && street == a.street && number > a.number))
        return true;
    else
        return false;
}

Adres& Adres::operator++()
{
    number++;
    return *this;
}

Adres& Adres::operator++(int)
{
    Adres *tmp = this;
    ++*this;
    return *tmp;
}

Adres& Adres::operator--()
{
    if(number != 0)
        number--;
    return *this;
}

Adres& Adres::operator--(int)
{
    Adres *tmp = this;
    if(number != 0)
        --*this;
    return *tmp;
}
