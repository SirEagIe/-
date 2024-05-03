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
};

#endif
