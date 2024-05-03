#ifndef STUDENTH
#define STUDENTH
#include <iostream>
#include "VUZ.h"

using namespace std;

class Student
{
private:
    string name;
    string vuz;
public:
    Student();    //конструктор без параметров
    Student(string, string);    //конструктор с параметрами
    Student(const Student&);  //конструктор копирования
    ~Student();   //деструктор

    //методы для установки значений данных объекта
    void setName(string);
    void setVUZ(string);
    void set(string, string);

    //методы для получения значений данных объекта
    string getName();
    string getVUZ();
    void show();

    friend void oper(VUZ&, Student&);
};

#endif
