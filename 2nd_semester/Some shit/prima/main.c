#include <stdio.h>
#include <stdlib.h>

void swap(int **arr, int n1, int n2);
void sort(int **arr, int size);

int main()
{
    system("chcp 1251");
    int nNode;                              //���������� ������ �����
    int nEdge = 0;                          //���������� ���� �����
    printf("������� ���������� ������ �����:\n");
    scanf("%d", &nNode);
    printf("������� ���������� ���� �����:\n");
    scanf("%d", &nEdge);

    int qg[nEdge][3];                     //��������� ���� �����
    printf("������� ���� ����� � �� ���:\n");

    for(int i = 0; i < nEdge; i++)
        scanf("%d%d%d", &qg[i][0], &qg[i][1], &qg[i][2]);

    sort(qg, nEdge);                      //���������� ���� �� �� ����

    int qg2[nEdge][3];                    //��������� ���������� ����
    int iqg2 = 0;                             //������ ��� ����������� �� ��������� ���������� ����
    for(int i = 0; i < nEdge; i++)        //�������������� ��������� ��� ������
    {
        qg2[i][0] = -1;
        qg2[i][1] = -1;
        qg2[i][2] = -1;
    }

    int q[nEdge][3];                      //��������� ������ ������, nEdge (���������� ���� �����) - ������������ ���������� ������ ������
    int iq = 0;                           //������ ��� ����������� �� ��������� ������ ������

    int s;                                //������ ������
    printf("������� �������, ������� ����� �������� ������:\n");
    scanf("%d", &s);

    int X[nNode];                         //��������� ������ ������
    for(int i = 0; i < nNode; i++)        //�������������� ��������� ��� ������
        X[i] = -1;

    int iX = 0;                           //������ ��� ����������� �� ��������� ������ ������

    X[iX] = s;                            //��������� � ������� ������ ������
    iX++;

    printf("������������� ����: \n");
    for(int i = 0; i < nEdge; i++)
    {
        printf("%d - %d (%d)\n", qg[i][0], qg[i][1], qg[i][2]);
    }

    int flag;

    for(int i = 0; i < nEdge; i++)
    {
        printf("��������� X:\n");
        printf("{");
        for(int j = 0; j < iX; j++)
            printf("%d, ", X[j]);
        printf("\b\b}\n");

        printf("������������� ����� %d - %d\n", qg[i][0], qg[i][1]);

        flag = 0;
        for(int j = 0; j < iX; j++)
        {
            if(qg[i][0] == X[j])
                flag = 1;
        }

        for(int j = 0; j < iX; j++)
        {
            if(qg[i][1] == X[j])
            {
                if(flag == 0)
                    flag = 2;
                if(flag == 1)
                    flag = 3;
            }
        }

        if(flag == 3)
        {
            printf("���������� ����� ������� ����\n");
            continue;
        }
        if(flag == 1)
        {
            printf("����� ���������� ������� �� X, ������� ��������� ������ �����\n");
            X[iX] = qg[i][1];
            iX++;
            q[iq][0] = qg[i][0];
            q[iq][1] = qg[i][1];
            q[iq][2] = qg[i][2];
            iq++;
        }
        if(flag == 2)
        {
            printf("����� ���������� ������� �� X, ������� ��������� ������ �����\n");
            X[iX] = qg[i][0];
            iX++;
            q[iq][0] = qg[i][0];
            q[iq][1] = qg[i][1];
            q[iq][2] = qg[i][2];
            iq++;
        }
        if(flag == 0)
        {
            printf("����� �� ���������� �� ����� ������� �� X, ������� ������� ������ �����\n");
            qg2[iqg2][0] = qg[i][0];
            qg2[iqg2][1] = qg[i][1];
            qg2[iqg2][2] = qg[i][2];
            iqg2++;
        }

        for(int j = 0; j < iqg2; j++)        //������������� ��� ���������� ����
        {
            printf("��������� X:\n");
            printf("{");
            for(int j = 0; j < iX; j++)
                if(X[j] != -1)
                    printf("%d, ", X[j]);
            printf("\b\b}\n");
            flag = 0;
            printf("������������� ���������� ����� %d - %d\n", qg2[j][0], qg2[j][1]);
            flag = 0;
            for(int k = 0; k < iX; k++)
            {
                if(qg2[j][0] == X[k])
                    flag = 1;
            }

            for(int k = 0; k < iX; k++)
            {
                if(qg2[j][1] == X[k])
                {
                    if(flag == 0)
                        flag = 2;
                    if(flag == 1)
                        flag = 3;
                }
            }

            if(flag == 3)
            {
                printf("���������� ����� ������� ����\n");
                continue;
            }
            if(flag == 1)
            {
                printf("����� ���������� ������� �� X, ������� ��������� ������ �����\n");
                X[iX] = qg2[j][1];
                iX++;
                q[iq][0] = qg2[j][0];
                q[iq][1] = qg2[j][1];
                q[iq][2] = qg2[j][2];
                iq++;

                qg2[j][0] = -1;                 //������� ����� �� ����������
                qg2[j][1] = -1;
                qg2[j][2] = -1;
                for(int k = j; k < nEdge - 1; k++)
                    swap(qg2, k, k + 1);
                iqg2--;
                j = -1;                         //������������� ��� ���������� ���� ������
            }
            if(flag == 2)
            {
                printf("����� ���������� ������� �� X, ������� ��������� ������ �����\n");
                X[iX] = qg2[j][0];
                iX++;
                q[iq][0] = qg2[j][0];
                q[iq][1] = qg2[j][1];
                q[iq][2] = qg2[j][2];
                iq++;

                qg2[j][0] = -1;                 //������� ����� �� ����������
                qg2[j][1] = -1;
                qg2[j][2] = -1;
                for(int k = j; k < nEdge - 1; k++)
                    swap(qg2, k, k + 1);
                iqg2--;
                j = -1;                         //������������� ��� ���������� ���� ������
            }

            if(flag == 0)                       //��������� ����� � ���������� � ����������
                printf("����� �� ���������� �� ����� ������� �� X, ������� ������� ������ �����\n");
        }
    }
    printf("����� ������: \n");
    for(int i = 0; i < iq; i++)
        printf("%d - %d (%d)\n", q[i][0], q[i][1], q[i][2]);

    return 0;
}

void swap(int **arr, int n1, int n2)
{
    int temp0 = arr[n1*3 + 0];
    int temp1 = arr[n1*3 + 1];
    int temp2 = arr[n1*3 + 2];
    arr[n1*3 + 0] = arr[n2*3 + 0];
    arr[n1*3 + 1] = arr[n2*3 + 1];
    arr[n1*3 + 2] = arr[n2*3 + 2];
    arr[n2*3 + 0] = temp0;
    arr[n2*3 + 1] = temp1;
    arr[n2*3 + 2] = temp2;
}

void sort(int **arr, int size)
{
    int leftBorder = 0, rightBorder = size - 1, flag = 2;
    while(flag != 0)
    {
        flag = 0;
        for(int i = leftBorder; i < rightBorder; i++)
        {
            if(arr[i*3 + 2] > arr[(i + 1)*3 + 2])
            {
                swap(arr, i, i + 1);
                flag = 1;
            }
        }
        rightBorder--;
        for(int i = rightBorder ; i > leftBorder; i--)
        {
            if(arr[i*3 + 2] < arr[(i - 1)*3 + 2])
            {
                swap(arr, i, i - 1);
                flag = 1;
            }
        }
        leftBorder++;
    }
}
