#include <stdio.h>
void l2r(char **c, int n)
{
	int i, j;
	for(i = 0; i < n; c++, i++)
	{
		for(j = 0; j < i; j++)
			printf("\t");
		printf("%s\n", *c);
	}
}

void r2l(char **c, int n)
{
	int j;
	for( ; n > 0; n--, c++)
	{
		for(j = 1; j < n; j++)
			printf("\t");
		printf("%s\n", *c);
	}
}