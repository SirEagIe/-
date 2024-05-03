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
    Student();    //����������� ��� ����������
    Student(string, string);    //����������� � �����������
    Student(const Student&);  //����������� �����������
    ~Student();   //����������

    //������ ��� ��������� �������� ������ �������
    void setName(string);
    void setVUZ(string);
    void set(string, string);

    //������ ��� ��������� �������� ������ �������
    string getName();
    string getVUZ();
    void show();

    friend void oper(VUZ&, Student&);
};

#endif
