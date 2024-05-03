#include <iostream>
#include <windows.h>
#include "Adres.h"

using namespace std;

bool operator==(Adres& a1, Adres& a2);
bool operator!=(Adres& a1, Adres& a2);

int main()
{
    system("chcp 1251");
    system("cls");
    //===================���������� � ������������� ������� �������===================
    Adres adres[10];
    adres[0].set("���������� ���� ����������", "������", "�����������", 5);
    adres[1].set("�������� �������� ����������", "���������", "����������", 60);
    adres[2].set("������� ������� ����������", "���������", "����������", 68);
    adres[3].set("���������� ��������� ��������", "������", "�����������", 10);
    adres[4].set("������ ������� ���������", "���������", "����������", 46);
    adres[5].set("�������� ����� ���������", "������", "�����������", 23);
    adres[6].set("������� ���� ����������", "������", "�����������", 36);
    adres[7].set("������ ����� �����������", "���������", "�������", 42);
    adres[8].set("������� ���� ���������", "���������", "�������", 92);
    adres[9].set("������� ������� ����������", "������", "�����������", 13);
    //==============================����� ������ �������==============================
    cout << "����������������� ������: " << endl << endl;
    for(int i = 0; i < 10; i++)
        adres[i].show();
    //=======================���������� ������� �� �����������========================
    bool isSort = false;
    while(isSort == false)
    {
        isSort = true;
        for(int i = 0; i < 9; i++)
        {
            if(adres[i] > adres[i+1])
            {
                Adres tmp = adres[i];
                adres[i] = adres[i+1];
                adres[i+1] = tmp;
                isSort = false;
            }
        }
    }
    //==============================����� ������ �������==============================
    cout << endl << "������, ��������������� �� �����������: " << endl << endl;
    for(int i = 0; i < 10; i++)
        adres[i].show();
    //=========================���������� ������� �� ��������=========================
    isSort = false;
    while(isSort == false)
    {
        isSort = true;
        for(int i = 0; i < 9; i++)
        {
            if(adres[i] < adres[i+1])
            {
                Adres tmp = adres[i];
                adres[i] = adres[i+1];
                adres[i+1] = tmp;
                isSort = false;
            }
        }
    }
    //==============================����� ������ �������==============================
    cout << endl << "������, ��������������� �� ��������: " << endl << endl;
    for(int i = 0; i < 10; i++)
        adres[i].show();
    //========================������������ ���������� ++ � --=========================
    cout << endl << "������������ ���������� ++ � --: " << endl << endl;
    cout << "adres[0]: ";
    adres[0].show();
    cout << "adres[0]++: ";
    (adres[0]++).show();
    cout << "++adres[0]: ";
    (++adres[0]).show();
    cout << "adres[0]--: ";
    (adres[0]--).show();
    cout << "--adres[0]: ";
    (--adres[0]).show();
    //================= �������������� ����������� ������� == � != ===================
    if(adres[0] == adres[1])
    {
        cout << endl << "������" << endl;
        adres[0].show();
        cout << "�" << endl;
        adres[1].show();
        cout << "�����" << endl;
    }
    if(adres[0] != adres[1])
    {
        cout << endl << "������" << endl;
        adres[0].show();
        cout << "�" << endl;
        adres[1].show();
        cout << "�� �����" << endl;
    }
    return 0;
}

bool operator==(Adres& a1, Adres& a2)
{
    if(a1.city == a2.city && a1.street == a2.street && a1.number == a2.number)
        return true;
    else
        return false;
}

bool operator!=(Adres& a1, Adres& a2)
{
    if(a1.city == a2.city && a1.street == a2.street && a1.number == a2.number)
        return false;
    else
        return true;
}
