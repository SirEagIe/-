#include <iostream>
#include "conio.h"
#include "windows.h"

using namespace std;

struct s_route {
    string start;
    string finish;
    int num;
    string carNumber;
};

void input(s_route routes[], int* numRoutes)
{
    if(*numRoutes == 50)
        cout << "������������ ���������� �������!" << endl;
    else
    {
        cout << "������ ��������: ";
        cin >> routes[*numRoutes].start;
        cout << "����� ��������: ";
        cin >> routes[*numRoutes].finish;
        cout << "����� ��������: ";
        cin >> routes[*numRoutes].num;
        cout << "����� ������: ";
        cin >> routes[*numRoutes].carNumber;
        (*numRoutes)++;
        cout << "������� ��������" << endl;
    }
}

void del(s_route routes[], int* numRoutes)
{
    if(*numRoutes == 0)
        cout << "��� �������" << endl;
    else
    {
        int num;
        for(int i = 0; i < *numRoutes; i++)
            cout << i+1 << ": " << routes[i].start << " - " << routes[i].finish << endl << "����� ��������: " << routes[i].num << endl << "����� ����������: " << routes[i].carNumber << endl << "-------------------------------------" << endl;
        cout << "������� ����� ������, ������� ����� �������" << endl;
        cin >> num;
        if(num < 1 || num > *numRoutes)
        {
            cout << "����� ����� �����������!" << endl;
            return;
        }
        num--;
        for(int i = 0; num + i + 1 < *numRoutes; i++)
        {
            routes[num + i] = routes[num + i + 1];
        }
        (*numRoutes)--;
        cout << "������ �������" << endl;
    }
}

void _sort(s_route routes[], int numRoutes)
{
    if(numRoutes == 0)
        cout << "��� �������" << endl;
    else
    {
        s_route tmp;
        int flag = 1;
        while(flag == 1)
        {
            flag = 0;
            for(int i = 0; i < numRoutes - 1; i++)
            {
                if(routes[i].finish > routes[i + 1].finish)
                {
                    tmp = routes[i];
                    routes[i] = routes[i + 1];
                    routes[i + 1] = tmp;
                    flag = 1;
                }
            }
        }
        for(int i = 0; i < numRoutes; i++)
            cout << routes[i].start << " - " << routes[i].finish << endl << "����� ��������: " << routes[i].num << endl << "����� ����������: " << routes[i].carNumber << endl << "-------------------------------------" << endl;
    }
}

void output(s_route routes[], int numRoutes)
{
    if(numRoutes == 0)
        cout << "��� �������" << endl;
    else
    {
        string start;
        cout << "������� ����� �����������: " << endl;
        cin >> start;
        cout << "������ �����, �������������� �� ������� ������: " << endl;
        bool found = false;
        for(int i = 0; i < numRoutes; i++)
        {
            if(routes[i].start == start)
            {
                cout << routes[i].carNumber << endl;
                found = true;
            }
        }
        if(found == false)
            cout << "�� �������" << endl;
    }
}

int main()
{
    system("chcp 1251");
    system("cls");
    s_route routes[50];
    int numRoutes = 0;
    int key;
    while(true)
    {
        system("cls");
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ����� ������ ���������, ���������������� �� �������� ��������� ������" << endl;
        cout << "4. ����� ������� �����, �������������� �� ���������� ������" << endl;
        cout << "5. �����" << endl << endl;
        key = getch();
        switch(key)
        {
            case 49:
                system("cls");
                input(routes, &numRoutes);
                getch();
                break;
            case 50:
                system("cls");
                del(routes, &numRoutes);
                getch();
                break;
            case 51:
                system("cls");
                _sort(routes, numRoutes);
                getch();
                break;
            case 52:
                system("cls");
                output(routes, numRoutes);
                getch();
                break;
            case 53:
                return 0;
                break;
        }
    }
    return 0;
}
