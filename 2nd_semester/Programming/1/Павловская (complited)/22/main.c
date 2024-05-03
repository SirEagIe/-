#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    float x, y;
    printf("Введите значения x и y\n");
    scanf("%f%f", &x, &y);
    if(x*x+y*y <= 1 || x <= 0 && y <= 0 && y >= -x-2)
        printf("Точка попадает в область\n");
    else
        printf("Точка не попадает в область\n");
    return 0;
}
