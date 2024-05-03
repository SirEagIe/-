#include <iostream>

using namespace std;

class Base
{
public:
     Base() { cout << "green";  }
};

class Derived : public Base
{
    int x;
public:
};

int main()
{
   Derived B;
   return 0;

}
