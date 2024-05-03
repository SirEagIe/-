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
    //������������ � ����������
    PrintEdition();
    PrintEdition(string _name, int _yearOfPublication, int _price);
    PrintEdition(PrintEdition& pe);
    ~PrintEdition();
    //������ ��������� � ��������� �����
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
    //������������ � ����������
    Magazine();
    Magazine(string _name, int _yearOfPublication, int _price, int _monthOfPublication);
    Magazine(Magazine& m);
    ~Magazine();
    //������ ��������� � ��������� �����
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
    //������������ � ����������
    Book();
    Book(string _name, int _yearOfPublication, int _price, string _authorName);
    Book(Book& b);
    ~Book();
    //������ ��������� � ��������� �����
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
    //������������ � ����������
    Textbook();
    Textbook(string _name, int _yearOfPublication, int _price, string _authorName, string _subject);
    Textbook(Textbook& t);
    ~Textbook();
    //������ ��������� � ��������� �����
    void setSubject(string);
    string getSubject();
    //
    void showInfo();
};

#endif
