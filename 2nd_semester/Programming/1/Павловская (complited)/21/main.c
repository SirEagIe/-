#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    float x, y;
    printf("������� �������� ���������:\n");
    scanf("%f", &x);
    if (x < -2)            y = 0;
    if (x >= -2 && x < -1) y = -x - 2;
    if (x >= -1 && x < 1)  y = x;
    if (x >= 1 && x < 2)   y = -x + 2;
    if (x >= 2)            y = 0;
    printf("���  x = %5.2f �������� ������� y = %5.2f\n", x, y);
    return 0;
}
