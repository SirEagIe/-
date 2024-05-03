#include <iostream>
#include <cstring>
#include "Adres.h"

using namespace std;

//����������� ��� ����������
Adres::Adres(): name("---"), city("---"), street("---"), number(0)
{
	cout << "������ ������ ������ (" << this << "): ";
	show();
}

//����������� � �����������
Adres::Adres(char* _name, char* _city, char* _street, int _number)
{
	strcpy(name, _name);
	strcpy(city, _city);
	strcpy(street, _street);
	number = _number;
	cout << "������ ������ (" << this << "): ";
	show();
}

//����������� �����������
Adres::Adres(const Adres& adres)
{
	strcpy(name, adres.name);
	strcpy(city, adres.city);
	strcpy(street, adres.street);
	number = adres.number;
	cout << "������ ������ ���� ����������� (" << this << "): ";
	show();
}

//����������
Adres::~Adres()
{
	cout << "������ ����� (" << this << "): ";
	show();
}

//������ ��� ��������� ����� ������
void Adres::setName(char* _name)
{
	strcpy(name, _name);
}
void Adres::setCity(char* _city)
{
	strcpy(city, _city);
}
void Adres::setStreet(char* _street)
{
	strcpy(street, _street);
}
void Adres::setNumber(int _number)
{
	number = _number;
}
void Adres::set(char* _name, char* _city, char* _street, int _number)
{
    strcpy(name, _name);
	strcpy(city, _city);
	strcpy(street, _street);
	number = _number;
}

//������ ��� ��������� ����� ������
char* Adres::getName()
{
	return name;
}
char* Adres::getCity()
{
	return city;
}
char* Adres::getStreet()
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
