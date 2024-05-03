#include <stdio.h>
#include <stdlib.h>

struct graph {
    int nNode;
    int nEdge;
    int* node;
    int* edge;
};

struct graph initGraph();
void addNode();
void deleteNode();
void addEdge();
void deleteEdge();
void identNode();
void unionGraphs();
void interGraphs();
void compGraphs();
void addGraphs();

int main()
{
    system("chcp 65001");
    int option;
    while(1)
    {
        printf("======================================\n");
        printf("1 - добавить вершину\n");
        printf("2 - удалить вершину\n");
        printf("3 - добавить ребро\n");
        printf("4 - удалить ребро\n");
        printf("5 - отождествление вершин\n");
        printf("6 - объединение графов\n");
        printf("7 - пересечение графов\n");
        printf("8 - дополнение графа\n");
        printf("9 - сложение (соединение) графов\n");
        printf("10 - выход\n");
        printf("======================================\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                addNode();
                getch();
                break;
            case 2:
                deleteNode();
                getch();
                break;
            case 3:
                addEdge();
                getch();
                break;
            case 4:
                deleteEdge();
                getch();
                break;
            case 5:
                identNode();
                getch();
                break;
            case 6:
                unionGraphs();
                getch();
                break;
            case 7:
                interGraphs();
                getch();
                break;
            case 8:
                compGraphs();
                getch();
                break;
            case 9:
                addGraphs();
                getch();
                break;
            case 10:
                return 0;
            default:
                printf("Неверные данные!\n");
                getch();
                break;
        }
    }
    return 0;
}

struct graph initGraph()	//инициализация графа
{
    struct graph G;
    printf("Введите количество вершин графа: ");
    scanf("%d", &G.nNode);
    printf("Введите количество рёбер графа: ");
    scanf("%d", &G.nEdge);
    G.node = (int*)malloc(G.nNode*sizeof(int));
    G.edge = (int*)malloc(3*G.nEdge*sizeof(int));
    printf("Введите список вершин: \n");
    for(int i = 0; i < G.nNode; i++)
        scanf("%d", &G.node[i]);
    printf("Введите список рёбер: \n");
    for(int i = 0; i < G.nEdge*3; i += 3)
        scanf("%d%d%d", &G.edge[i], &G.edge[i+1], &G.edge[i+2]);
    return G;
}

void addNode()	//добавление вершины
{
    struct graph G = initGraph();
    int node;
    printf("Введите имя новой вершины: ");
    scanf("%d", &node);
    printf("Граф с добавленной вершиной: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G.nNode; i++)
        printf("%d, ", G.node[i]);
    printf("%d\n", node);
    printf("Список рёбер: ");
    for(int i = 0; i < G.nEdge*3; i += 3)
        printf("%d: %d - %d, ", G.edge[i], G.edge[i+1], G.edge[i+2]);
    printf("\b\b  \n");
    free(G.node);
    free(G.edge);
}

void deleteNode()	//удаление вершины
{
    struct graph G = initGraph();
    int node;
    printf("Введите имя вершины, которую нужно удалить: ");
    scanf("%d", &node);
    printf("Граф с удалённой вершиной: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G.nNode; i++)
    {
        if(node == G.node[i])
            continue;
        printf("%d, ", G.node[i]);
    }
    printf("\b\b  \n");
    printf("Список рёбер: ");
    for(int i = 0; i < G.nEdge*3; i += 3)
    {
        if(G.edge[i+1] == node || G.edge[i+2] == node)
            continue;
        printf("%d: %d - %d, ", G.edge[i], G.edge[i+1], G.edge[i+2]);
    }
    printf("\b\b  \n");
    free(G.node);
    free(G.edge);
}

void addEdge()	//добавление ребра
{
    struct graph G = initGraph();
    int edge, node1, node2;
    printf("Введите новое ребро: ");
    scanf("%d%d%d", &edge, &node1, &node2);
    printf("Граф с добавленным ребром: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G.nNode; i++)
        printf("%d, ", G.node[i]);
    printf("\b\b  \n");
    printf("Список рёбер: ");
    for(int i = 0; i < G.nEdge*3; i += 3)
        printf("%d: %d - %d, ", G.edge[i], G.edge[i+1], G.edge[i+2]);
    printf("%d: %d - %d\n", edge, node1, node2);
    free(G.node);
    free(G.edge);
}

void deleteEdge()	//удаление ребра
{
    struct graph G = initGraph();
    int edge;
    printf("Введите ребро, которое нужно удалить: ");
    scanf("%d", &edge);
    printf("Граф с удалённым ребром: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G.nNode; i++)
        printf("%d, ", G.node[i]);
    printf("\b\b  \n");
    printf("Список рёбер: ");
    for(int i = 0; i < G.nEdge*3; i += 3)
    {
        if(G.edge[i] == edge)
            continue;
        printf("%d: %d - %d, ", G.edge[i], G.edge[i+1], G.edge[i+2]);
    }
    printf("\b\b  \n");
    free(G.node);
    free(G.edge);
}

void identNode()	//отождествление вершин
{
    struct graph G = initGraph();
    int node1, node2, node3;
    printf("Введите вершины, которые нужно отождествить, и имя новой вершины: ");
    scanf("%d%d%d", &node1, &node2, &node3);
    printf("Граф с отождествлёнными вершинами: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G.nNode; i++)
    {
        if(G.node[i] == node1 || G.node[i] == node2)
            continue;
        printf("%d, ", G.node[i]);
    }
    printf("%d\n", node3);
    printf("Список рёбер: ");
    for(int i = 0; i < G.nEdge*3; i += 3)
    {
        if(G.edge[i+1] == node1 || G.edge[i+1] == node2 || G.edge[i+2] == node1 || G.edge[i+2] == node2)
            continue;
        printf("%d: %d - %d, ", G.edge[i], G.edge[i+1], G.edge[i+2]);
    }
    for(int i = 0; i < G.nEdge*3; i += 3)
    {
        if(G.edge[i+1] == node1 && G.edge[i+2] == node2 || G.edge[i+2] == node1 && G.edge[i+1] == node2)
            continue;
        if(G.edge[i+1] == node1 || G.edge[i+1] == node2)
        {
            printf("%d: %d - %d, ", G.edge[i], node3, G.edge[i+2]);
        }
        if(G.edge[i+2] == node1 || G.edge[i+2] == node2)
        {
            printf("%d: %d - %d, ", G.edge[i], G.edge[i+1], node3);
        }
    }
    printf("\b\b  \n");
    free(G.node);
    free(G.edge);
}

void unionGraphs()	//объединение графов
{
    printf("Первый граф:\n");
    struct graph G1 = initGraph();
    printf("Второй граф:\n");
    struct graph G2 = initGraph();
    printf("Результат объединения графов: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G1.nNode; i++)
    {
        printf("%d, ", G1.node[i]);
    }
    int flag;
    for(int i = 0; i < G2.nNode; i++)
    {
        flag = 0;
        for(int j = 0; j < G1.nNode; j++)
            if(G2.node[i] == G1.node[j])
                flag = 1;
        if(flag == 1)
            continue;
        printf("%d, ", G2.node[i]);
    }
    printf("\b\b  ");
    printf("Список рёбер: ");
    for(int i = 0; i < G1.nEdge*3; i += 3)
    {
        printf("%d: %d - %d, ", G1.edge[i], G1.edge[i+1], G1.edge[i+2]);
    }
    for(int i = 0; i < G2.nEdge*3; i += 3)
    {
        flag = 0;
        for(int j = 0; j < 3*G1.nEdge; j += 3)
            if(G2.edge[i] == G1.edge[j] && G2.edge[i+1] == G1.edge[j+1] && G2.edge[i+2] == G1.edge[j+2])
                flag = 1;
        if(flag == 1)
            continue;
        printf("%d: %d - %d, ", G2.edge[i], G2.edge[i+1], G2.edge[i+2]);
    }
    printf("\b\b  \n");
    free(G1.node);
    free(G1.edge);
    free(G2.node);
    free(G2.edge);
}

void interGraphs()	//пересечение графов
{
    printf("Первый граф:\n");
    struct graph G1 = initGraph();
    printf("Второй граф:\n");
    struct graph G2 = initGraph();
    printf("Результат пересечения графов: \n");
    printf("Список вершин: ");
    int flag;
    for(int i = 0; i < G1.nNode; i++)
    {
        flag = 0;
        for(int j = 0; j < G2.nNode; j++)
            if(G1.node[i] == G2.node[j])
                flag = 1;
        if(flag == 1)
            printf("%d, ", G2.node[i]);
    }
    printf("\b\b  \n");
    printf("Список рёбер: ");
    for(int i = 0; i < G1.nEdge*3; i += 3)
    {
        flag = 0;
        for(int j = 0; j < 3*G2.nEdge; j += 3)
            if(G1.edge[i] == G2.edge[j] && G1.edge[i+1] == G2.edge[j+1] && G1.edge[i+2] == G2.edge[j+2])
                flag = 1;
        if(flag == 1)
            printf("%d: %d - %d, ", G2.edge[i], G2.edge[i+1], G2.edge[i+2]);
    }
    printf("\b\b  \n");
    free(G1.node);
    free(G1.edge);
    free(G2.node);
    free(G2.edge);
}

void compGraphs()	//дополнение графа
{
    struct graph G = initGraph();

    printf("Результат операции дополнения: \n");
    printf("Список вершин: ");
    int flag;
    for(int i = 0; i < G.nNode; i++)
        printf("%d, ", G.node[i]);
    printf("\b\b  \n");

    printf("Список рёбер: ");
    for(int i = 0; i < G.nNode; i++)
    {
        for(int j = i + 1; j < G.nNode; j++)
        {
            flag = 0;
            for(int k = 0; k < G.nEdge*3; k += 3)
                if((G.edge[k+1] == (i+1) && G.edge[k+2] == (j+1)) || (G.edge[k+2] == (i+1) && G.edge[k+1] == (j+1)))
                    flag = 1;
            if(flag == 1)
                continue;
            printf("%d - %d, ", i+1, j+1);
        }
    }
    printf("\b\b  \n");
    free(G.node);
    free(G.edge);
}

void addGraphs()	//соединение графа
{
    printf("Первый граф:\n");
    struct graph G1 = initGraph();
    printf("Второй граф:\n");
    struct graph G2 = initGraph();
    printf("Результат соединения графов: \n");
    printf("Список вершин: ");
    for(int i = 0; i < G1.nNode; i++)
    {
        printf("%d, ", G1.node[i]);
    }
    for(int i = 0; i < G2.nNode; i++)
    {
        printf("%d, ", G2.node[i]);
    }
    printf("\b\b  ");
    printf("Список рёбер: ");
    int flag;
    for(int i = 0; i < G1.nEdge*3; i += 3)
    {
        printf("%d: %d - %d, ", G1.edge[i], G1.edge[i+1], G1.edge[i+2]);
    }
    for(int i = 0; i < G2.nEdge*3; i += 3)
    {
        printf("%d: %d - %d, ", G2.edge[i], G2.edge[i+1], G2.edge[i+2]);
    }
    for(int i = 0; i < G1.nNode; i++)
    {
        for(int j = 0; j < G2.nNode; j++)
        {
            printf("%d - %d, ", G1.node[i], G2.node[j]);
        }
    }
    printf("\b\b  \n");
    free(G1.node);
    free(G1.edge);
    free(G2.node);
    free(G2.edge);
}
