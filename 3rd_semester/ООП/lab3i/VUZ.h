#ifndef VUZH
#define VUZH
#include <iostream>

using namespace std;

class Student;

class VUZ
{
private:
    string name;
    string rectorName;
    int rankingPosition;
    int studentNumber;
    static int numVUZ;
    static int numStud;
public:
    VUZ();    //конструктор без параметров
    VUZ(string, string, int, int);    //конструктор с параметрами
    VUZ(const VUZ& vuz);  //конструктор копировани€
    ~VUZ();   //деструктор

    //методы дл€ установки значений данных объекта
    void setName(string);
    void setRectorName(string);
    void setRankingPosition(int);
    void setStudentNumber(int);
    void set(string, string, int, int);

    //методы дл€ получени€ значений данных объекта
    string getName();
    string getRectorName();
    int getRankingPosition();
    int getStudentNumber();
    void show();

    //дополнительные методы
    void upPosition();
    void downPosition();
    //перегрузка дополнительных методов
    void upPosition(int);
    void downPosition(int);

    //работа со статической компонентой
    static int avNumStud();

    //объ€вление функции oper дружественной
    friend void oper(VUZ&, Student&);
};

#endif
