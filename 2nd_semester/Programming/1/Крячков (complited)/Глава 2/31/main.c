#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int N, k1 = 0, k0 = 0, check;
    printf("������� ����� �������\n");
    scanf("%d", &N);
    int IM[N];
    printf("������� �������� �������\n");
    for(int i = 0; i < N; i++)      //���������� �������
        scanf("%d", &IM[i]);
    printf("�������� ������� �� ����������:\n");
    for(int i = 0; i < N; i++)      //����� ��������� ������� �� ����������
    {
        printf("%3d", IM[i]);
        if(IM[i] == 0)  k0++;       //������� 0
        else if(IM[i] == 1)  k1++;  //������� 1
        else                        //�������� �� ���������� � ������� ������ �����
        {
            printf("\n������� �������� ������\n");
            check = 0;
        }
    }
    if(check)                       //���� �������� ��������
    {
        for(int i = 0; i < k0; i++) //���������� �������
            IM[i] = 0;
        for( ; k0 < N; k0++)
            IM[k0] = 1;
        printf("\n�������� ������� ����� ����������:\n");
        for(int i = 0; i < N; i++)
        {
            printf("%3d", IM[i]);
        }
    }
    return 0;
}
