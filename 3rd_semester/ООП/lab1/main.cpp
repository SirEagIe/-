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
        cout << "Максимальное количество записей!" << endl;
    else
    {
        cout << "Начало маршрута: ";
        cin >> routes[*numRoutes].start;
        cout << "Конец маршрута: ";
        cin >> routes[*numRoutes].finish;
        cout << "Номер маршрута: ";
        cin >> routes[*numRoutes].num;
        cout << "Номер машины: ";
        cin >> routes[*numRoutes].carNumber;
        (*numRoutes)++;
        cout << "Маршрут добавлен" << endl;
    }
}

void del(s_route routes[], int* numRoutes)
{
    if(*numRoutes == 0)
        cout << "Нет записей" << endl;
    else
    {
        int num;
        for(int i = 0; i < *numRoutes; i++)
            cout << i+1 << ": " << routes[i].start << " - " << routes[i].finish << endl << "Номер маршрута: " << routes[i].num << endl << "Номер автомобиля: " << routes[i].carNumber << endl << "-------------------------------------" << endl;
        cout << "Введите номер записи, которую нужно удалить" << endl;
        cin >> num;
        if(num < 1 || num > *numRoutes)
        {
            cout << "Номер введён неправильно!" << endl;
            return;
        }
        num--;
        for(int i = 0; num + i + 1 < *numRoutes; i++)
        {
            routes[num + i] = routes[num + i + 1];
        }
        (*numRoutes)--;
        cout << "Запись удалена" << endl;
    }
}

void _sort(s_route routes[], int numRoutes)
{
    if(numRoutes == 0)
        cout << "Нет записей" << endl;
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
            cout << routes[i].start << " - " << routes[i].finish << endl << "Номер маршрута: " << routes[i].num << endl << "Номер автомобиля: " << routes[i].carNumber << endl << "-------------------------------------" << endl;
    }
}

void output(s_route routes[], int numRoutes)
{
    if(numRoutes == 0)
        cout << "Нет записей" << endl;
    else
    {
        string start;
        cout << "Введите пункт отправления: " << endl;
        cin >> start;
        cout << "Номера машин, отправляющихся из данного пункта: " << endl;
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
            cout << "Не найдено" << endl;
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
        cout << "1. Добавить маршрут" << endl;
        cout << "2. Удалить маршрут" << endl;
        cout << "3. Вывод списка маршрутов, отсортированного по названию конечного пункта" << endl;
        cout << "4. Вывод номеров машин, отправляющихся из указанного пункта" << endl;
        cout << "5. Выход" << endl << endl;
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
