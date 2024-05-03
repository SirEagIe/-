#ifndef ADRESH
#define ADRESH

class Adres
{
    private:
        char name[100];
        char city[100];
        char street[100];
        int number;
    public:
        Adres();    //конструктор без параметров
        Adres(char*, char*, char*, int);    //конструктор с параметрами
        Adres(const Adres& adres);  //конструктор копирования
        ~Adres();   //деструктор

        //методы для установки значений данных объекта
        void setName(char*);
        void setCity(char*);
        void setStreet(char*);
        void setNumber(int);
        void set(char*, char*, char*, int);

        //методы для получения значений данных объекта
        char* getName();
        char* getCity();
        char* getStreet();
        int getNumber();
        void show();

        //дополнительный метод
        void whoLivesHere();
};

#endif
