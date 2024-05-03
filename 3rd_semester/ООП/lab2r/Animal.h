#ifndef ANIMALH
#define ANIMALH

#include <iostream>

using namespace std;

class Animal
{
private:
    string name;
    string _class;
    string order;
    int averageWeight;
public:
    //����������� ��� ����������, � �����������, ����������� � ����������
    Animal();
    Animal(string, string, string, int);
    Animal(Animal&);
    ~Animal();
    //������ ��� ��������� ����� ������
    void setName(string);
    void setClass(string);
    void setOrder(string);
    void setAverageWeight(int);
    void set(string, string, string, int);
    //������ ��� ��������� ����� ������
    string getName();
    string getClass();
    string getOrder();
    int getAverageWeight();
    void show();
    //�������������� ������ (���������� � ���������� ������� ����)
    void averageWeightUp(int);
    void averageWeightDown(int);
};

#endif
