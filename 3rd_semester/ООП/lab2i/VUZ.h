#ifndef VUZH
#define VUZH

#include <iostream>

using namespace std;

class VUZ
{
private:
    string name;
    string rectorName;
    int rankingPosition;
    int studentNumber;
public:
    VUZ();    //конструктор без параметров
    VUZ(string, string, int, int);    //конструктор с параметрами
    VUZ(const VUZ& vuz);  //конструктор копирования
    ~VUZ();   //деструктор

    //методы для установки значений данных объекта
    void setName(string);
    void setRectorName(string);
    void setRankingPosition(int);
    void setStudentNumber(int);
    void set(string, string, int, int);

    //методы для получения значений данных объекта
    string getName();
    string getRectorName();
    int getRankingPosition();
    int getStudentNumber();
    void show();

    //дополнительные методы
    void upPosition();
    void downPosition();
};

#endif
