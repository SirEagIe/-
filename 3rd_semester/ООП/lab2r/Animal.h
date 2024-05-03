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
    //конструктор без параметров, с параметрами, копирования и деструктор
    Animal();
    Animal(string, string, string, int);
    Animal(Animal&);
    ~Animal();
    //методы для изменения полей данных
    void setName(string);
    void setClass(string);
    void setOrder(string);
    void setAverageWeight(int);
    void set(string, string, string, int);
    //методы для просмотра полей данных
    string getName();
    string getClass();
    string getOrder();
    int getAverageWeight();
    void show();
    //дополнительные методы (увеличение и уменьшение среднго веса)
    void averageWeightUp(int);
    void averageWeightDown(int);
};

#endif
