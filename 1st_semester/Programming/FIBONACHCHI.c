#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    int n, f1 = 0, f2 = 1, f3;
    printf("Enter n\n");
    scanf("%d", &n);    //ввод номера члена последовательности
    if(n == 1)      //если 1, выводим первый член
        printf("%d", f1);
    else if(n == 2) //если 2, выводим второй член
        printf("%d", f2);
    else    //иначе считаем
    {
        for(int i = 0; i < n - 2; i++)  //цикл с n-2 итерациями (n-2, т. к. 2 элемента уже есть)
        {
            f3 = f1 + f2;   //тут сам разберись :P
            f1 = f2;
            f2 = f3;
        }
        printf("%d", f3);
    }
    return 0;
}
