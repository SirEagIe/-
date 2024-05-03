#include <iostream>
#include "ManagementCompany.h"

using namespace std;

ManagementCompany::ManagementCompany()
{
    name = "---";
    nameDirector = "---";
    count = 0;
}

ManagementCompany::ManagementCompany(string _name, string _nameDirector)
{
    name = _name;
    nameDirector = _nameDirector;
    count = 0;
}

void ManagementCompany::setName(string _name)
{
    name = _name;
}

void ManagementCompany::setNameDirector(string _nameDirector)
{
    nameDirector = _nameDirector;
}

string ManagementCompany::getName()
{
    return name;
}

string ManagementCompany::getNameDirector()
{
    return nameDirector;
}

void ManagementCompany::find()
{
    cout << "¬ведите им€ человека: " << endl;
    string tmpName;
    getline(cin, tmpName, '\n');
    int isFinded = false;
    for(int i = 0; i < count; i++)
    {
        if(adres[i]->getName() == tmpName)
        {
            isFinded = true;
            cout << tmpName << " проживает по адресу " << adres[i]->getCity() << " " << adres[i]->getStreet() << " " << adres[i]->getNumber() << endl;
        }
    }
    if(!isFinded)
    {
        cout << tmpName << " не обслуживаетс€ в компании " << name << endl;
    }
}

void ManagementCompany::find(string tmpName)
{
    int isFinded = false;
    for(int i = 0; i < count; i++)
    {
        if(adres[i]->getName() == tmpName)
        {
            isFinded = true;
            cout << tmpName << " проживает по адресу " << adres[i]->getCity() << " " << adres[i]->getStreet() << " " << adres[i]->getNumber() << endl;
        }
    }
    if(!isFinded)
    {
        cout << tmpName << " не обслуживаетс€ в компании " << name << endl;
    }
}
