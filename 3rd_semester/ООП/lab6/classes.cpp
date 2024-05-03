#include <iostream>
#include "classes.h"

using namespace std;

//������������ � ����������
PrintEdition::PrintEdition() : name("0"), yearOfPublication(0), price(0)
{
    cout << "������� �������� ������� (����������� ��� ����������) " << this << endl;
}

PrintEdition::PrintEdition(string _name, int _yearOfPublication, int _price) : name(_name), yearOfPublication(_yearOfPublication), price(_price)
{
    cout << "������� �������� ������� (����������� � �����������) " << this << endl;
}

PrintEdition::PrintEdition(PrintEdition& pe) : name(pe.name), yearOfPublication(pe.yearOfPublication), price(pe.price)
{
    cout << "������� �������� ������� (����������� �����������) " << this << endl;
}

PrintEdition::~PrintEdition()
{
    cout << "���������� �������� ������� " << this << endl;
}

//������ ��������� � ��������� �����
void PrintEdition::setName(string _name)
{
    name = _name;
}

void PrintEdition::setYearOfPublication(int _yearOfPublication)
{
    yearOfPublication = _yearOfPublication;
}

void PrintEdition::setPrice(int _price)
{
    price = _price;
}

string PrintEdition::getName()
{
    return name;
}

int PrintEdition::getYearOfPublication()
{
    return yearOfPublication;
}

int PrintEdition::getPrice()
{
    return price;
}

//������������ � ����������
Magazine::Magazine() : PrintEdition(), monthOfPublication(0)
{
    cout << "������ ������ (����������� ��� ����������) " << this << endl;
}

Magazine::Magazine(string _name, int _yearOfPublication, int _price, int _monthOfPublication) : PrintEdition(_name, _yearOfPublication, _price), monthOfPublication(_monthOfPublication)
{
    cout << "������ ������ (����������� � �����������) " << this << endl;
}

Magazine::Magazine(Magazine& m) : PrintEdition(m), monthOfPublication(m.monthOfPublication)
{
    cout << "������ ������ (����������� �����������) " << this << endl;
}

Magazine::~Magazine()
{
    cout << "��������� ������ " << this << endl;
}

//������ ��������� � ��������� �����
void Magazine::setMonthOfPublication(int _monthOfPublication)
{
    monthOfPublication = _monthOfPublication;
}

int Magazine::getMonthOfPublication()
{
    return monthOfPublication;
}

//
void Magazine::showInfo()
{
    cout << "\"" << name << "\"" << " " << yearOfPublication << "�. " << monthOfPublication << " ����� " << price << "� " << endl;
}

//������������ � ����������
Book::Book() : PrintEdition(), authorName("0")
{
    cout << "������� ����� (����������� ��� ����������) " << this << endl;
}

Book::Book(string _name, int _yearOfPublication, int _price, string _authorName) : PrintEdition(_name, _yearOfPublication, _price), authorName(_authorName)
{
    cout << "������� ����� (����������� � �����������) " << this << endl;
}

Book::Book(Book& b) : PrintEdition(b), authorName(b.authorName)
{
    cout << "������� ����� (����������� �����������) " << this << endl;
}

Book::~Book()
{
    cout << "���������� ����� " << this << endl;
}

//������ ��������� � ��������� �����
void Book::setAuthorName(string _authorName)
{
    authorName = _authorName;
}

string Book::getAuthorName()
{
    return authorName;
}

//
void Book::showInfo()
{
    cout << authorName << " " << "\"" << name << "\"" << " " << yearOfPublication << "�. " << price << "� " << endl;
}

//������������ � ����������
Textbook::Textbook() : Book(), subject("0")
{
    cout << "������ ������� (����������� ��� ����������) " << this << endl;
}

Textbook::Textbook(string _name, int _yearOfPublication, int _price, string _authorName, string _subject) : Book(_name, _yearOfPublication, _price, _authorName), subject(_subject)
{
    cout << "������ ������� (����������� � �����������) " << this << endl;
}

Textbook::Textbook(Textbook& t) : Book(t), subject(t.subject)
{
    cout << "������ ������� (����������� �����������) " << this << endl;
}

Textbook::~Textbook()
{
    cout << "��������� ������� " << this << endl;
}

//������ ��������� � ��������� �����
void Textbook::setSubject(string _subject)
{
    subject = _subject;
}

string Textbook::getSubject()
{
    return subject;
}

//
void Textbook::showInfo()
{
    cout << authorName << " " << "\"" << name << "\"" << " " << subject << " " << yearOfPublication << "�. " << price << "� " << endl;
}
