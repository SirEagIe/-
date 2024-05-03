#ifndef ADRESH
#define ADRESH

using namespace std;

class Adres
{
    private:
        string name;
        string city;
        string street;
        int number;
        static int numOnStreet;
    public:
        Adres();    //конструктор без параметров
        Adres(string, string, string, int);    //конструктор с параметрами
        Adres(const Adres& adres);  //конструктор копирования
        ~Adres();   //деструктор
        //методы для установки значений данных объекта
        void setName(string);
        void setCity(string);
        void setStreet(string);
        void setNumber(int);
        void set(string, string, string, int);
        //методы для получения значений данных объекта
        string getName();
        string getCity();
        string getStreet();
        int getNumber();
        void show();
        //дополнительный метод
        void whoLivesHere();
        //работа со статической компонентой
        static int getNumOnStreet();
        //перегрузка операторов
        bool operator<(Adres&);
        bool operator>(Adres&);
        Adres& operator++();
        Adres& operator++(int);
        Adres& operator--();
        Adres& operator--(int);
        friend bool operator==(Adres&, Adres&);
        friend bool operator!=(Adres&, Adres&);
};

#endif
