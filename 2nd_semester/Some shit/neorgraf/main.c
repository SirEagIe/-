#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");
    int nNode;  //���������� ������ �����
    int nEdge;  //���������� ���� �����
    printf("������� ���������� ������ �����:\n");
    scanf("%d", &nNode);
    printf("������� ���������� ���� �����:\n");
    scanf("%d", &nEdge);
    int X[nNode];   //��������� ������� ������
    int iX = 0;     //������ ��� ����������� �� ��������� ������ ������

    for(int i = 0; i < nNode; i++)  //�������������� ��������� ������ ������ ��� "������" ���������
        X[i] = -1;

    int qg[nEdge][2];   //��������� ���� �����

    printf("������� ���� �����:\n");

    for(int i = 0; i < nEdge; i++)
        scanf("%d%d", &qg[i][0], &qg[i][1]);

    int q[nEdge][2];   //��������� ������ ������
    int iq = 0;        //������ ��� ����������� �� ��������� ������ ������

    int p;  //������ ������
    int arrP[nNode];    //�������� ������, ������� ��� ���� ������� ������
    int iarrP = 0;      //������ ��� ����������� �� ���������
    for(int i = 0; i < nNode; i++)  //�������������� ��������� ��� "������" ���������
        arrP[i] = -1;

    printf("���������� ����� ������:\n");
    scanf("%d", &p);
    arrP[iarrP] = p;    //��������� ������� p �� �������� ������, ������� ��� ���� ������� ������
    iarrP++;
    X[iX] = p;          //��������� p �� ��������� ������ ������
    iX++;

    for(int k = 0; k < nNode; k++)
    {
        for(int i = 0; i < nEdge; i++)
        {
            if(qg[i][0] == p || qg[i][1] == p)   //������� ���� {u n, u n+1}, ����������� � ������� p
            {
                int flag = 0;

                for(int j = 0; j < iX; j++)      //���������, ��� u n+1 �� ����������� �������� ������ ������
                    if((qg[i][0] == p && X[j] == qg[i][1]) || (qg[i][1] == p && X[j] == qg[i][0]))
                        flag = 1;

                if(flag == 1)
                    continue;

                if(qg[i][0] == p)                ////��������� ����� � ������
                {
                    q[iq][0] = p;
                    q[iq][1] = qg[i][1];
                }
                if(qg[i][1] == p)
                {
                    q[iq][0] = p;
                    q[iq][1] = qg[i][0];
                }
                iq++;
                if(qg[i][0] == p)                //��������� ������� � ������
                    X[iX] = qg[i][1];
                if(qg[i][1] == p)                //��������� ������� � ������
                    X[iX] = qg[i][0];
                iX++;                            //����������� ������
            }
        }

        for(int i = 0; i < nNode; i++)           //���������� ������ p
        {
            int flag = 1;
            for(int j = 0; j < nNode; j++)
            {
                if(X[i] == arrP[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                p = X[i];
                arrP[iarrP] = p;
                iarrP++;
                break;
            }
        }
    }

    printf("����� ������: \n");
    for(int i = 0; i < iq; i++)
        printf("%d - %d\n", q[i][0], q[i][1]);

    getch();
    return 0;
}
