#include <stdio.h>
#include "superprint.h"
#define N 5
int main()
{
	char strs[N][10];
	char *p[N];
	int i;
	for(i = 0; i < N; i++)
	{
		scanf("%s", strs[i]);
		p[i] = &strs[i][0];
	}
	l2r(p, N);
	r2l(p, N);
	return 0;
}