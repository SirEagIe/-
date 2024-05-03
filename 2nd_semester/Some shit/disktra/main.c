#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");

    int numOfNodes;                                 //Количество узлов графа
    int p;                                          //p - очередная упорядоченная вершина
    int s;                                          //Номер узла отправления пакета

    printf("Введите количество вершин графа: ");
    scanf("%d", &numOfNodes);

    int M[numOfNodes][numOfNodes];                  //Матрица связей
    int lable[numOfNodes][3];                       //Матрица, содержащее расстояние до узла, предыдущий номер узла маршрута, перманентность узла

    for(int i = 0; i < numOfNodes; i++)             //Цикл, устанавливающий расстояние до каждого узла -1 (бесконечность)
        lable[i][0] = -1;
    for(int i = 0; i < numOfNodes; i++)             //Цикл, устанавливающий значение перманентности метки каждого узла 0 (изначально все метки временные)
        lable[i][2] = 0;

    for(int i = 0; i < numOfNodes; i++)             //Ввод расстояний между узлами
    {
        M[i][i] = 0;
        for(int j = i + 1; j < numOfNodes; j++)
        {
            int tmp;
            printf("Введите растояние %d - %d: ", i + 1, j + 1);
            scanf("%d", &tmp);
            M[i][j] = tmp;
            M[j][i] = tmp;
        }
    }

    printf("Введите номер узла отправления пакета: ");
    scanf("%d", &s);
    s--;
    lable[s][0] = 0;
    lable[s][1] = s;
    lable[s][2] = 1;
    p = s;

    for(int i = 0; i < numOfNodes - 1; i++)
    {
        for(int  j = 0; j < numOfNodes; j++)              //Нахождение узлов, смежных p, и пересчитывание временных меток
        {
            if(M[p][j] != 0 && lable[j][2] == 0)
            {
                if(lable[j][0] == -1)
                    lable[j][0] = lable[p][0] + M[p][j];
                else
                    lable[j][0] = min(lable[j][0], lable[p][0] + M[p][j]);
                lable[j][1] = p;
            }
        }
        int minLable = -1;
        for(int  j = 0; j < numOfNodes; j++)              //Нахождение вершины с минимальной первой координатой
        {
            if(minLable == -1 && lable[j][2] == 0 && lable[j][0] != -1)
            {
                minLable = lable[j][0];
                p = j;
                continue;
            }
            if(minLable != -1 && minLable > lable[j][0] && lable[j][2] == 0 && lable[j][0] != -1)
            {
                minLable = lable[j][0];
                p = j;
            }
        }
        lable[p][2] = 1;
    }

    for(int i = 0; i < numOfNodes; i++)
        printf("Кратчайшее расстояние до %dго узла - %d\n", i + 1, lable[i][0]);

    getch();
    return 0;
}
