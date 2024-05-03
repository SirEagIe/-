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
    VUZ();    //����������� ��� ����������
    VUZ(string, string, int, int);    //����������� � �����������
    VUZ(const VUZ& vuz);  //����������� �����������
    ~VUZ();   //����������

    //������ ��� ��������� �������� ������ �������
    void setName(string);
    void setRectorName(string);
    void setRankingPosition(int);
    void setStudentNumber(int);
    void set(string, string, int, int);

    //������ ��� ��������� �������� ������ �������
    string getName();
    string getRectorName();
    int getRankingPosition();
    int getStudentNumber();
    void show();

    //�������������� ������
    void upPosition();
    void downPosition();
    //���������� �������������� �������
    void upPosition(int);
    void downPosition(int);

    //������ �� ����������� �����������
    static int avNumStud();

    //���������� ������� oper �������������
    friend void oper(VUZ&, Student&);
};

#endif
