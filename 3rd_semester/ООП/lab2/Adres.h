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
        Adres();    //����������� ��� ����������
        Adres(char*, char*, char*, int);    //����������� � �����������
        Adres(const Adres& adres);  //����������� �����������
        ~Adres();   //����������

        //������ ��� ��������� �������� ������ �������
        void setName(char*);
        void setCity(char*);
        void setStreet(char*);
        void setNumber(int);
        void set(char*, char*, char*, int);

        //������ ��� ��������� �������� ������ �������
        char* getName();
        char* getCity();
        char* getStreet();
        int getNumber();
        void show();

        //�������������� �����
        void whoLivesHere();
};

#endif
