#include <iostream>
#include "Student.h"
#include "VUZ.h"

using namespace std;

void oper(VUZ&, Student&);

int main()
{
    system("chcp 1251");

    VUZ VUZ1("ТОГУ", "Иванченко Сергей Николаевич", 93, 17000);
    VUZ VUZ2("ДВФУ", "Никита Юрьевич Анисимов", 25, 23000);
    VUZ VUZ3("МГУ", "Виктор Антонович Садовничий", 13, 38000);
    //Демонстрация работы со статической компонентой
    cout << endl << "Среднее количество студентов: " << VUZ::avNumStud() << endl << endl;
    cout << "---------------------------------------" << endl;
    Student st("Никитин Юрий Георгиевич", "ТОГУ");
    //Демонстрация работы с дружественной функцией
    oper(VUZ1, st);
    cout << endl;
    oper(VUZ2, st);
    cout << "---------------------------------------" << endl << endl;
    //Демонстрация работы с перегрузкой
    VUZ1.upPosition();
    VUZ1.downPosition();

    VUZ1.upPosition(17);
    VUZ1.downPosition(13);
    cout << "---------------------------------------" << endl << endl;
    return 0;
}

void oper(VUZ& vuz, Student& stud)
{
    if(stud.vuz == vuz.name)
    {
        cout << stud.name << " обучается в вузе " << vuz.name << endl;
        cout << "Позиция вуза в рейтинге - " << vuz.rankingPosition << endl;
    }
    else
    {
        cout << stud.name << " не обучается в вузе " << vuz.name << endl;
    }
}
