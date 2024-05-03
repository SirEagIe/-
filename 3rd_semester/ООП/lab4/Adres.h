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
        Adres();    //����������� ��� ����������
        Adres(string, string, string, int);    //����������� � �����������
        Adres(const Adres& adres);  //����������� �����������
        ~Adres();   //����������
        //������ ��� ��������� �������� ������ �������
        void setName(string);
        void setCity(string);
        void setStreet(string);
        void setNumber(int);
        void set(string, string, string, int);
        //������ ��� ��������� �������� ������ �������
        string getName();
        string getCity();
        string getStreet();
        int getNumber();
        void show();
        //�������������� �����
        void whoLivesHere();
        //������ �� ����������� �����������
        static int getNumOnStreet();
        //���������� ����������
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
