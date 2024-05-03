#include <iostream>
#include <windows.h>
#include "VUZ.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");

    cout << "Объекты в статической памяти:" << endl << endl;
    {
        VUZ VUZ1;
        VUZ1.show();
        VUZ VUZ2("ТОГУ", "Иванченко Сергей Николаевич", 93, 17000);
        VUZ2.show();
        VUZ VUZ3 = VUZ2;
        VUZ3.show();
    }

    cout << endl << "Объекты в динамической памяти:" << endl << endl;
    VUZ *VUZ4 = new VUZ;
    VUZ4->show();
    VUZ *VUZ5 = new VUZ("ТОГУ", "Иванченко Сергей Николаевич", 93, 17000);
    VUZ5->show();
    VUZ *VUZ6 = new VUZ(*VUZ5);
    VUZ6->show();
    delete VUZ4;
    delete VUZ5;
    delete VUZ6;

    cout << endl << "Объекты в статическом массиве:" << endl << endl;
    {
        VUZ arr1[2] = {VUZ("ТОГУ", "Иванченко Сергей Николаевич", 93, 17000), VUZ("ДВФУ", "	Никита Юрьевич Анисимов", 25, 23000)};
        arr1[0].set("ТОГУ", "Иванченко Сергей Николаевич", 93, 17000);
        arr1[0].show();
        arr1[1].set("ДВФУ", "Никита Юрьевич Анисимов", 25, 23000);
        arr1[1].show();
    }

    cout << endl << "Объекты в динамическом массиве:" << endl << endl;
    VUZ *arr2 = new VUZ[2];
    arr2[0].set("ТОГУ", "Иванченко Сергей Николаевич", 93, 17000);
    arr2[0].show();
    arr2[1].set("ДВФУ", "Никита Юрьевич Анисимов", 25, 23000);
    arr2[1].show();
    delete [] arr2;

    cout << endl << "Установка и получение полей данных:" << endl << endl;
    VUZ VUZ7;
    string name;
    string rectorName;
    int rankingPosition;
    int studentNumber;

    cout << "Введите название ВУЗа: ";
    getline(cin, name, '\n');

    cout << "Введите имя ректора: ";
    getline(cin, rectorName, '\n');

    cout << "Введите позицию в рейтинге: ";
    cin >> rankingPosition;

    cout << "Введите количество студентов: ";
    cin >> studentNumber;

    VUZ7.setName(name);
    VUZ7.setRectorName(rectorName);
    VUZ7.setRankingPosition(rankingPosition);
    VUZ7.setStudentNumber(studentNumber);

    cout << endl;

    cout << "Название ВУЗа: " << VUZ7.getName() << endl;
    cout << "Имя ректора: " << VUZ7.getRectorName() << endl;
    cout << "Позиция в рейтинге: " << VUZ7.getRankingPosition() << endl;
    cout << "Количество студентов: " << VUZ7.getStudentNumber() << endl;

    cout << endl << "Демонстрация дополнительных методов, соответствующих поведению объекта:" << endl << endl;
    VUZ7.upPosition();
    VUZ7.downPosition();

    return 0;
}
