#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

void intersection(char* arr1, char* arr2, int len1, int len2, char* arrResult);				//функция, записывающая в множество результат пересечения
void _union(char* arr1, char* arr2, int len1, int len2, char* arrResult);					//функция, записывающая в множество результат объединения
void difference(char* arr1, char* arr2, int len1, int len2, char* arrResult);				//функция, записывающая в множество результат разности
void difference(char* arr1, char* arr2, int len1, int len2, char* arrResult);				//функция, записывающая в множество результат разности
void complements(char* arr, char* u, int len, int lenU, char* arrResult);					//функция, записывающая в множество результат дополнения
void symmetricDifference(char* arr1, char* arr2, int len1, int len2, char* arrResult);		//функция, записывающая в множество результат кольцевой суммы

int main()
{
	system("chcp 65001");
	int len1 = 0;
	int len2 = 0;
	char u[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};		//универсум
	printf("Элементы универсума:\n");
	for(int i = 0; i < 18; i++)
		printf("%c", u[i]);

	char* arr1 = (char*)malloc(100*sizeof(char));		//первое множество
	if(arr1 == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	char* arr2 = (char*)malloc(100*sizeof(char));		//второе множество
	if(arr2 == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	FILE *fp;
    fp = fopen("file.txt", "r+");						//открытие файла
    if(fp == NULL)
    {
        printf("Ошибка чтения файла\n");
        exit(1);
    }
	char ch = getc(fp);
	for(int i = 0; ch != '\n'; i++)						//считывание первого множества
	{
		arr1[i] = ch;
		len1++;
		ch = getc(fp);
	}
	arr1 = (char*)realloc(arr1, len1);
	ch = getc(fp);
	for(int i = 0; ch != EOF; i++)						//считывание второго множества
	{
		arr2[i] = ch;
		len2++;
		ch = getc(fp);
	}
	arr2 = (char*)realloc(arr2, len2);
	printf("\nЭлементы первого множества:\n", len1);	//вывод элементов первого множества
	for(int i = 0; i < len1; i++)
		printf("%c", arr1[i]);
	printf("\nЭлементы второго множества:\n", len2);	//вывод элементов второго множества
	for(int i = 0; i < len2; i++)
		printf("%c", arr2[i]);
		
	//Пересечение
	
	char* resultOfInter = (char*)malloc(min(len1, len2)*sizeof(char));				//массив, где хранятся элементы пересечения
	if(resultOfInter == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	intersection(arr1, arr2, len1, len2, resultOfInter);							//выполнение пересечения
	
	if((_msize(resultOfInter)/sizeof(char)) == -1)
	{
		printf("\nРезультат пересечения этих множеств:\nПустое множество\n\n");
	}
	else
	{
		printf("\nРезультат пересечения этих множеств:\n");
		for(int i = 0; i < _msize(resultOfInter)/sizeof(char); i++)					//вывод элементов пересечения
			printf("%c", resultOfInter[i]);
		printf("\n\n");
	}
	
	//Объединение
	
	char* resultOfUnion = (char*)malloc((len1 + len2)*sizeof(char));				//массив, где хранятся элементы объединения
	if(resultOfUnion == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	_union(arr1, arr2, len1, len2, resultOfUnion);									//выполнение объединения
	
	if((_msize(resultOfUnion)/sizeof(char)) == -1)
	{
		printf("Результат объединения этих множеств:\nПустое множество\n\n");
	}
	else
	{
		printf("Результат объединения этих множеств:\n");
		for(int i = 0; i < _msize(resultOfUnion)/sizeof(char); i++)					//вывод элементов объединения
			printf("%c", resultOfUnion[i]);
		printf("\n\n");
	}
	
	//Разность arr1\arr2
	
	char* resultOfDifference1 = (char*)malloc(len1*sizeof(char));					//массив, где хранятся элементы разности
	if(resultOfDifference1 == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	difference(arr1, arr2, len1, len2, resultOfDifference1);						//выполнение разности

	if((_msize(resultOfDifference1)/sizeof(char)) == -1)
	{
		printf("Результат разности первого и второго множества:\nПустое множество\n\n");
	}
	else
	{
		printf("Результат разности первого и второго множества:\n");
		for(int i = 0; i < _msize(resultOfDifference1)/sizeof(char); i++)			//вывод элементов разности
			printf("%c", resultOfDifference1[i]);
		printf("\n\n");
	}
	
	//Разность arr2\arr1
	
	char* resultOfDifference2 = (char*)malloc(len2*sizeof(char));					//массив, где хранятся элементы разности
	if(resultOfDifference2 == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	difference(arr2, arr1, len2, len1, resultOfDifference2);						//выполнение разности

	if((_msize(resultOfDifference2)/sizeof(char)) == -1)
	{
		printf("Результат разности первого и второго множества:\nПустое множество\n\n");
	}
	else
	{
		printf("Результат разности первого и второго множества:\n");
		for(int i = 0; i < _msize(resultOfDifference2)/sizeof(char); i++)			//вывод элементов разности
			printf("%c", resultOfDifference2[i]);
		printf("\n\n");
	}
	
	//Дополнение первого множества до универсума
	
	char* resultOfComplements1 = (char*)malloc(18*sizeof(char));					//массив, где хранятся элементы дополнения
	if(resultOfComplements1 == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	complements(arr1, u, len1, 18, resultOfComplements1);							//выполнение дополнения
	
	if((_msize(resultOfComplements1)/sizeof(char)) == -1)
	{
		printf("Результат дополнения первого множества до универсума:\nПустое множество\n\n");
	}
	else
	{
		printf("Результат дополнения первого множества до универсума:\n");
		for(int i = 0; i < _msize(resultOfComplements1)/sizeof(char); i++)			//вывод элементов дополнения
			printf("%c", resultOfComplements1[i]);
		printf("\n\n");
	}
	
	//Дополнение второго множества до универсума
	
	char* resultOfComplements2 = (char*)malloc(18*sizeof(char));					//массив, где хранятся элементы дополнения
	if(resultOfComplements2 == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
	
	complements(arr2, u, len2, 18, resultOfComplements2);							//выполнение дополнения
	
	if((_msize(resultOfComplements2)/sizeof(char)) == -1)
	{
		printf("Результат дополнения второго множества до универсума:\nПустое множество\n\n");
	}
	else
	{
		printf("Результат дополнения второго множества до универсума:\n");
		for(int i = 0; i < _msize(resultOfComplements2)/sizeof(char); i++)			//вывод элементов дополнения
			printf("%c", resultOfComplements2[i]);
		printf("\n\n");
	}
	
	//Кольцевая сумма
	
	char* resultOfSymmetricDifference = (char*)malloc((len1 + len2)*sizeof(char));	//массив, где хранятся элементы кольцевой суммы
	if(resultOfSymmetricDifference == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

	symmetricDifference(arr1, arr2, len1, len2, resultOfSymmetricDifference);		//выполнение кольцевой суммы

	if((_msize(resultOfSymmetricDifference)/sizeof(char)) == -1)
	{
		printf("Результат кольцевой суммы этих множеств:\nПустое множество\n\n");
	}
	else
	{
		printf("Результат кольцевой суммы этих множеств:\n");
		for(int i = 0; i < _msize(resultOfSymmetricDifference)/sizeof(char); i++)	//вывод элементов кольцевой суммы
			printf("%c", resultOfSymmetricDifference[i]);
		printf("\n\n");
	}
	
	free(arr1);
	free(arr2);
	free(resultOfInter);
	free(resultOfUnion);
	free(resultOfDifference1);
	free(resultOfDifference2);
	free(resultOfComplements1);
	free(resultOfComplements2);
	free(resultOfSymmetricDifference);
	fclose(fp);
	return 0;
}

void intersection(char* arr1, char* arr2, int len1, int len2, char* arrResult)
{
	int count = 0;
	for(int i = 0; i < len1; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				arrResult[count] = arr1[i];
				count++;
			}
		}
	}
	arrResult = (char*)realloc(arrResult, count);
}

void _union(char* arr1, char* arr2, int len1, int len2, char* arrResult)
{
	int count = 0;
	int flag;
	for(int i = 0; i < len1; i++)
	{
		arrResult[count] = arr1[i];
		count++;
	}
	for(int i = 0; i < len2; i++)
	{
		flag = 1;
		for(int j = 0; j < len1; j++)
		{
			if(arr2[i] == arr1[j])
			{
				flag = 0;
			}
		}
		if(flag == 1)
		{
			arrResult[count] = arr2[i];
			count++;
		}
	}
	arrResult = (char*)realloc(arrResult, count);
}

void difference(char* arr1, char* arr2, int len1, int len2, char* arrResult)
{
	int count = 0;
	int flag;
	for(int i = 0; i < len1; i++)
	{
		flag = 1;
		for(int j = 0; j < len2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				flag = 0;
			}
		}
		if(flag == 1)
		{
			arrResult[count] = arr1[i];
			count++;
		}
	}
	arrResult = (char*)realloc(arrResult, count);
}

void complements(char* arr, char* u, int len, int lenU, char* arrResult)
{
	int count = 0;
	int flag;
	for(int i = 0; i < lenU; i++)
	{
		flag = 1;
		for(int j = 0; j < len; j++)
		{
			if(u[i] == arr[j])
			{
				flag = 0;
			}
		}
		if(flag == 1)
		{
			arrResult[count] = u[i];
			count++;
		}
	}
	arrResult = (char*)realloc(arrResult, count);
}

void symmetricDifference(char* arr1, char* arr2, int len1, int len2, char* arrResult)
{
	int count = 0;
	int flag;
	for(int i = 0; i < len1; i++)
	{
		flag = 1;
		for(int j = 0; j < len2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				flag = 0;
			}
		}
		if(flag == 1)
		{
			arrResult[count] = arr1[i];
			count++;
		}
	}
	
	for(int i = 0; i < len2; i++)
	{
		flag = 1;
		for(int j = 0; j < len1; j++)
		{
			if(arr2[i] == arr1[j])
			{
				flag = 0;
			}
		}
		if(flag == 1)
		{
			arrResult[count] = arr2[i];
			count++;
		}
	}
	arrResult = (char*)realloc(arrResult, count);
}