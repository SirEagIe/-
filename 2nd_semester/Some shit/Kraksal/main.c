#include <stdio.h>
#include <stdlib.h>

void swap(int **arr, int n1, int n2);
void sort(int **arr, int size);

int main()
{
    system("chcp 1251");
    int nNode;                              //количество вершин графа
    int nEdge = 0;                          //количество рЄбер графа
    printf("¬ведите количество вершин графа:\n");
    scanf("%d", &nNode);
    printf("¬ведите количество рЄбер графа:\n");
    scanf("%d", &nEdge);

    int qg[nEdge][3];                     //множество рЄбер графа
    printf("¬ведите рЄбра графа и их вес:\n");

    for(int i = 0; i < nEdge; i++)
        scanf("%d%d%d", &qg[i][0], &qg[i][1], &qg[i][2]);

    sort(qg, nEdge);                      //сортировка рЄбер по их весу

    int q[nEdge][3];                      //множество ветвей дерева, nEdge (количество рЄбер графа) - максимальное количество ветвей дерева
    int iq = 0;                           //индекс дл€ перемещени€ по множеству ветвей дерева

    int V[nNode/2][nNode];                //множества с рассмотренными вершинами (максимально возможное клоичество множеств, которое может понадобитьс€ - кол-во вершин/2)

    for(int i = 0; i < nNode/2; i++)      //инициализируем множества как пустые
        for(int j = 0; j < nNode; j++)
            V[i][j] = -1;

    int iiV = -1;                         //индекс дл€ перемещени€ между множествами
    int iV[nNode/2];                      //множество индексов дл€ перемещени€ по множествам
    for(int i = 0; i < nNode/2; i++)
        iV[i] = 0;

    int flag;
    int iiV1;
    int iiV2;

    for(int i = 0; i < nEdge; i++)
    {
        flag = 0;

        printf("–ассматриваем ребро %d - %d\n", qg[i][0], qg[i][1]);

        for(int j = 0; j < nNode/2; j++)
        //вы€вление нахождени€ обоих концов ни в одном из множеств (flag = 0)/обоих концов в одном множестве (flag = 2)/
        //одного конца в множестве (flag = 3)/одного конца в одном множестве, второго - в другом (flag = 4)
        {
            for(int k = 0; k < nNode; k++)
            {
                if(qg[i][0] == V[j][k] || qg[i][1] == V[j][k])
                {
                    if(flag == 1)
                    {
                        flag = 2;
                        break;
                    }
                    if(flag == 3)
                    {
                        flag = 4;
                        iiV2 = j;
                    }
                    if(flag == 0)
                    {
                        flag = 1;
                        iiV1 = j;
                    }
                }
            }

            if(flag == 1)
                flag = 3;

            if(flag == 2)
                break;
        }

        if(flag == 0)
        {
            printf(" онцы ребра не принадлежат ни одному множеству, поэтому добавл€ем ребро и добавл€ем концы ребра в новое множество\n");
            iiV++;
            V[iiV][iV[iiV]] = qg[i][0];
            (iV[iiV])++;
            V[iiV][iV[iiV]] = qg[i][1];
            (iV[iiV])++;

            q[iq][0] = qg[i][0];
            q[iq][1] = qg[i][1];
            q[iq][2] = qg[i][2];
            iq++;
        }

        if(flag == 2)
        {
            printf("ƒобавление ребра создаст цикл, поэтому данное ребро не добавл€ем\n");
            continue;
        }

        if(flag == 3)
        {
            int flag2 = 0;
            printf("ќдин конец ребра уже присутствует во множестве, поэтому добавл€ем ребро и второй конец добавл€ем в множество\n");

            for(int j = 0; j < nNode/2; j++)
            {
                for(int k = 0; k < nNode; k++)
                {
                    if(qg[i][0] == V[j][k])
                    {
                        V[iiV1][iV[iiV1]] = qg[i][1];
                        (iV[iiV1])++;
                        flag2 = 1;
                        break;
                    }
                }
                if(flag2 == 1)
                    break;
            }

            if(flag2 != 1)
            {
                for(int j = 0; j < nNode/2; j++)
                {
                    for(int k = 0; k < nNode; k++)
                    {
                        if(qg[i][1] == V[j][k])
                        {
                            V[iiV1][iV[iiV1]] = qg[i][0];
                            (iV[iiV1])++;
                            flag2 = 1;
                            break;
                        }
                    }
                }
            }

            q[iq][0] = qg[i][0];
            q[iq][1] = qg[i][1];
            q[iq][2] = qg[i][2];
            iq++;
        }

        if(flag == 4)
        {
            printf(" онцы ребра наход€тс€ в разных множествах, поэтому добавл€ем ребро и объедин€ем эти множества\n");
            for(int j = 0; j < iV[iiV2]; j++)
            {
                V[iiV1][iV[iiV1]] = V[iiV2][j];
                (iV[iiV1])++;
            }

            for(int j = iiV2; j < nNode/2; j++)
            {
                for(int k = 0; k < nNode; k++)
                {
                    V[j][k] = V[j + 1][k];
                }
            }

            for(int j = 0; j < nNode; j++)
                V[(nNode/2) - 1][j] = -1;

            iV[iiV2] = 0;
            iiV--;

            q[iq][0] = qg[i][0];
            q[iq][1] = qg[i][1];
            q[iq][2] = qg[i][2];
            iq++;
        }

        printf("ƒополнительные множества:\n");
        for(int j = 0; j < nNode/2; j++)
        {
            int flag3 = 0;
            for(int k = 0; k < nNode; k++)
                if(V[j][k] != -1)
                    flag3 = 1;

            if(flag3 == 1)
            {
                printf("V%d: ", j + 1);
                for(int k = 0; k < nNode; k++)
                {
                    if(V[j][k] != -1)
                        printf("%3d", V[j][k]);
                    else
                        printf("%3c", ' ');
                }
                printf("\n");
            }
        }
    }

    printf("¬етви дерева: \n");
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
