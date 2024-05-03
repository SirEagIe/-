#ifndef MANAGEMENTCOMPANYH
#define MANAGEMENTCOMPANYH
#include <string>
#include "Adres.h"

using namespace std;

class ManagementCompany
{
    string name;
    string nameDirector;
    Adres *adres[40];
    int count;
public:
    ManagementCompany();
    ManagementCompany(string, string);
    void setName(string);
    void setNameDirector(string);
    string getName();
    string getNameDirector();
    void find();
    void find(string);
    friend void Adres::setManagementCompany(ManagementCompany&);
    friend void oper(ManagementCompany&);
};

#endif
