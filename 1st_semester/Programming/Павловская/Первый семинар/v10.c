#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian");
	  float a, z1, z2;
  	printf("Введите a: ");
	  scanf("%f", &a);
  	if(sin(3*(a*M_PI/180)-M_PI) == 1 || sin(1.25*M_PI+1.5*(a*M_PI/180)) == 0)
  	{
  	    printf("При таком a нельзя определить z");
  	}
  	else
    {
        z1 = (sin(M_PI/2+3*(a*M_PI/180)))/(1-sin(3*(a*M_PI/180)-M_PI));
        z2 = (cos(1.25*M_PI+1.5*(a*M_PI/180)))/(sin(1.25*M_PI+1.5*(a*M_PI/180)));
        printf("z1 = %f\nz2 = %f", z1, z2);
  	}
  	return 0;
}
