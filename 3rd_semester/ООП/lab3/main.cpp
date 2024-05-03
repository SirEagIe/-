#include <iostream>
#include "windows.h"
#include "Adres.h"
#include "ManagementCompany.h"

using namespace std;

void oper(ManagementCompany&);

int main()
{
    system("chcp 1251");
    system("cls");
    //�������� � ������������� ����������� ��������
    ManagementCompany CompA("CompA", "������� ������� ������������");
    ManagementCompany CompB("CompB", "�������� ������� ����������");
    //�������� � ������������� ������� ��� ������ ��������
    Adres adres11("������� ������ ��������", "���������", "��. ��������", 1);
    adres11.setManagementCompany(CompA);
    Adres adres12("������� ���� ���������", "���������", "��. ��������", 2);
    adres12.setManagementCompany(CompA);
    Adres adres13("������� ��������� ������������", "���������", "��. ��������", 3);
    adres13.setManagementCompany(CompA);
    //�������� � ������������� ������� ��� ������ ��������
    Adres adres21("���������� ����� �����������", "���������", "��. �������", 1);
    adres21.setManagementCompany(CompB);
    Adres adres22("��������� �������� ��������", "���������", "��. �������", 2);
    adres22.setManagementCompany(CompB);
    Adres adres23("�������� ������� ���������", "���������", "��. �������", 3);
    adres23.setManagementCompany(CompB);
    //���������� ��������
    oper(CompA);
    cout << endl;
    //������ �� ����������� �����������
    cout << "���������� �����, ����������� �� ��. �������: " << Adres::getNumOnStreet() << endl;
    cout << endl;
    //���������� ���������� �������
    CompA.find();
    cout << endl;
    CompB.find("���������� ����� �����������");
    cout << endl;
    return 0;
}

void oper(ManagementCompany& mc)
{
    cout << "������� ��� ��������: " << endl;
    string tmpName;
    getline(cin, tmpName, '\n');
    int isFinded = false;
    for(int i = 0; i < mc.count; i++)
    {
        if(mc.adres[i]->getName() == tmpName)
        {
            isFinded = true;
            cout << "��� ��������� �������� " << mc.name << ", ������������� " << tmpName << " - " << mc.getNameDirector() << endl;
        }
    }
    if(!isFinded)
    {
        cout << tmpName << " �� ������������� � �������� " << mc.name << endl;
    }
}

