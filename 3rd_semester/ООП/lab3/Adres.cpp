#include <iostream>
#include "Adres.h"
#include "ManagementCompany.h"

using namespace std;

int Adres::numOnStreet = 0;

//конструктор без параметров
Adres::Adres(): name("---"), city("---"), street("---"), number(0) {}

//конструктор с параметрами
Adres::Adres(string _name, string _city, string _street, int _number)
{
	name = _name;
	city = _city;
	street = _street;
	number = _number;
	if(street == "ул. Пушкина")
        numOnStreet++;
}

//конструктор копирования
Adres::Adres(const Adres& adres)
{
	name = adres.name;
	city = adres.city;
	street = adres.street;
	number = adres.number;
	if(street == "ул. Пушкина")
        numOnStreet++;
}

//деструктор
Adres::~Adres()
{
	if(street == "ул. Пушкина")
        numOnStreet--;
}

//методы для установки полей данных
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
    if(street == "ул. Пушкина")
        numOnStreet--;
	street = _street;
	if(street == "ул. Пушкина")
        numOnStreet++;
}
void Adres::setNumber(int _number)
{
	number = _number;
}
void Adres::set(string _name, string _city, string _street, int _number)
{
    if(street == "ул. Пушкина")
        numOnStreet--;
    name = _name;
	city = _city;
	street = _street;
	number = _number;
	if(street == "ул. Пушкина")
        numOnStreet++;
}

//методы для получения полей данных
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

//дополнительный метод
void Adres::whoLivesHere()
{
    cout << "По адресу " << city << ", " << street << " " << number << " проживает " << name << endl;
}

int Adres::getNumOnStreet()
{
    return numOnStreet;
}

void Adres::setManagementCompany(ManagementCompany& mc)
{
    mc.adres[mc.count] = this;
    mc.count++;
    managementComp = mc.name;
}
