#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int k, result = 0;
    printf("������� k < 20\n");
    scanf("%d", &k);
    int matrix[k][k];
    for(int i = 0; i < k; i++)      //���������� �������
    {
        printf("������� �������� %d-� ������ �������\n", i+1);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("������� �����: \n");
    for(int i = 0; i < k; i++)      //����� ��������� �������
    {
        for(int j = 0; j < k; j++)
            printf("%3d ", matrix[i][j]);
            printf("\n");
    }
    for(int d = 0; d < k; d++)
        result += matrix[d][k-d-1];
    printf("����� ��������� �� ���������, ������������� �������, ����� %d", result);
    return 0;
}
