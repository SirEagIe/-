#ifndef CLASSESH
#define CLASSESH

#include <iostream>

using namespace std;

class PrintEdition
{
protected:
    string name;
    int yearOfPublication;
    int price;
public:
    //конструкторы и деструктор
    PrintEdition();
    PrintEdition(string _name, int _yearOfPublication, int _price);
    PrintEdition(PrintEdition& pe);
    ~PrintEdition();
    //методы получения и установки полей
    void setName(string);
    void setYearOfPublication(int);
    void setPrice(int);
    string getName();
    int getYearOfPublication();
    int getPrice();
    //
    void showInfo();
};

class Magazine : public PrintEdition
{
protected:
    int monthOfPublication;
public:
    //конструкторы и деструктор
    Magazine();
    Magazine(string _name, int _yearOfPublication, int _price, int _monthOfPublication);
    Magazine(Magazine& m);
    ~Magazine();
    //методы получения и установки полей
    void setMonthOfPublication(int);
    int getMonthOfPublication();
    //
    void showInfo();
};

class Book : public PrintEdition
{
protected:
    string authorName;
public:
    //конструкторы и деструктор
    Book();
    Book(string _name, int _yearOfPublication, int _price, string _authorName);
    Book(Book& b);
    ~Book();
    //методы получения и установки полей
    void setAuthorName(string);
    string getAuthorName();
    //
    void showInfo();
};

class Textbook : public Book
{
protected:
    string subject;
public:
    //конструкторы и деструктор
    Textbook();
    Textbook(string _name, int _yearOfPublication, int _price, string _authorName, string _subject);
    Textbook(Textbook& t);
    ~Textbook();
    //методы получения и установки полей
    void setSubject(string);
    string getSubject();
    //
    void showInfo();
};

#endif
