#ifndef ADRESH
#define ADRESH

using namespace std;

class ManagementCompany;

class Adres
{
    private:
        string name;
        string city;
        string street;
        int number;
        string managementComp;
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

        static int getNumOnStreet();

        void setManagementCompany(ManagementCompany& mc);

};

#endif
