#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    float x, y;
    printf("������� �������� x � y\n");
    scanf("%f%f", &x, &y);
    if(x*x+y*y <= 1 || x <= 0 && y <= 0 && y >= -x-2)
        printf("����� �������� � �������\n");
    else
        printf("����� �� �������� � �������\n");
    return 0;
}
