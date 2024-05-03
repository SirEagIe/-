#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*int n;
	int k;
	printf("Введите число вершин графа: ");
	scanf("%d", &n);
	printf("Введите число дуг графа: ");
	scanf("%d", &k);
	int b[n][k];
	for(int i = 0; i < n*k; i++)
	{
		printf("Введите значения %d-го столбца(для %d-й дуги)", i + 1, i + 1);
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &b[j][i]);
		}
	}*/
	int n = 0;
	int k = 0;
	//двумерный динамический массив
	
	char** b = (char**)malloc(50*sizeof(char*));
	for(int i = 0; i < 50; i++)
	{
		b[i] = (char*)malloc(50*sizeof(char));
	}
	
	FILE *fp;
    fp = fopen("graf.txt", "r+");
    if(fp == NULL)
    {
        printf("Ошибка чтения файла\n");
        exit(1);
    }
	
	char ch = getc(fp);
	
	for(int i = 0; ch != EOF; i++) //b[k][n]
	{
		for(int j = 0; ch != '\n' && ch != EOF; j++)
		{
			if(ch != ' ')
			{
				b[i][j] = ch;
				printf("%c\n", b[i][j]);
				k++;
			}
			ch = getc(fp);
			//printf("n = %d\n", n);
		}
		if(ch != EOF) //!!!
			ch = getc(fp);
		n++;
		//printf("k = %d\n", k);
	}
	
	/*b = (char**)realloc(b, n*sizeof(char*));
	for(int i = 0; i < n; i++)
	{
		b[i] = (char*)realloc(b[i], k*sizeof(char));
	}
	*/
	
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}*/
	
	for(int i = 0; i < n; i++)
	{
		free(b[i]);
	}
	free(b);
	fclose(fp);
	return 0;
}