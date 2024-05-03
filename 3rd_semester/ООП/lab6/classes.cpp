#include <iostream>
#include "classes.h"

using namespace std;

//конструкторы и деструктор
PrintEdition::PrintEdition() : name("0"), yearOfPublication(0), price(0)
{
    cout << "Создано печатное издание (конструктор без параметров) " << this << endl;
}

PrintEdition::PrintEdition(string _name, int _yearOfPublication, int _price) : name(_name), yearOfPublication(_yearOfPublication), price(_price)
{
    cout << "Создано печатное издание (конструктор с параметрами) " << this << endl;
}

PrintEdition::PrintEdition(PrintEdition& pe) : name(pe.name), yearOfPublication(pe.yearOfPublication), price(pe.price)
{
    cout << "Создано печатное издание (конструктор копирования) " << this << endl;
}

PrintEdition::~PrintEdition()
{
    cout << "Уничтожено печатное издание " << this << endl;
}

//методы получения и установки полей
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

//конструкторы и деструктор
Magazine::Magazine() : PrintEdition(), monthOfPublication(0)
{
    cout << "Создан журнал (конструктор без параметров) " << this << endl;
}

Magazine::Magazine(string _name, int _yearOfPublication, int _price, int _monthOfPublication) : PrintEdition(_name, _yearOfPublication, _price), monthOfPublication(_monthOfPublication)
{
    cout << "Создан журнал (конструктор с параметрами) " << this << endl;
}

Magazine::Magazine(Magazine& m) : PrintEdition(m), monthOfPublication(m.monthOfPublication)
{
    cout << "Создан журнал (конструктор копирования) " << this << endl;
}

Magazine::~Magazine()
{
    cout << "Уничтожен журнал " << this << endl;
}

//методы получения и установки полей
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
    cout << "\"" << name << "\"" << " " << yearOfPublication << "г. " << monthOfPublication << " месяц " << price << "р " << endl;
}

//конструкторы и деструктор
Book::Book() : PrintEdition(), authorName("0")
{
    cout << "Создана книга (конструктор без параметров) " << this << endl;
}

Book::Book(string _name, int _yearOfPublication, int _price, string _authorName) : PrintEdition(_name, _yearOfPublication, _price), authorName(_authorName)
{
    cout << "Создана книга (конструктор с параметрами) " << this << endl;
}

Book::Book(Book& b) : PrintEdition(b), authorName(b.authorName)
{
    cout << "Создана книга (конструктор копирования) " << this << endl;
}

Book::~Book()
{
    cout << "Уничтожена книга " << this << endl;
}

//методы получения и установки полей
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
    cout << authorName << " " << "\"" << name << "\"" << " " << yearOfPublication << "г. " << price << "р " << endl;
}

//конструкторы и деструктор
Textbook::Textbook() : Book(), subject("0")
{
    cout << "Создан учебник (конструктор без параметров) " << this << endl;
}

Textbook::Textbook(string _name, int _yearOfPublication, int _price, string _authorName, string _subject) : Book(_name, _yearOfPublication, _price, _authorName), subject(_subject)
{
    cout << "Создан учебник (конструктор с параметрами) " << this << endl;
}

Textbook::Textbook(Textbook& t) : Book(t), subject(t.subject)
{
    cout << "Создан учебник (конструктор копирования) " << this << endl;
}

Textbook::~Textbook()
{
    cout << "Уничтожен учебник " << this << endl;
}

//методы получения и установки полей
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
    cout << authorName << " " << "\"" << name << "\"" << " " << subject << " " << yearOfPublication << "г. " << price << "р " << endl;
}
