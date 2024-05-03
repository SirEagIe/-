#include <stdio.h>
#include <stdlib.h>

int lenOfIntersection(char arr1[], char arr2[], int len1, int len2);							//функция, вычисляющая количество элементов в пересечении
void intersection(char arr1[], char arr2[], int len1, int len2, char arrResult[]);				//функция, записывающая в множество результат пересечения

int lenOfUnion(char arr1[], char arr2[], int len1, int len2);									//функция, вычисляющая количество элементов в объединении
void _union(char arr1[], char arr2[], int len1, int len2, char arrResult[]);					//функция, записывающая в множество результат объединения

int lenOfDifference(char arr1[], char arr2[], int len1, int len2);								//функция, вычисляющая количество элементов в разности
void difference(char arr1[], char arr2[], int len1, int len2, char arrResult[]);				//функция, записывающая в множество результат разности

int lenOfDifference(char arr1[], char arr2[], int len1, int len2);								//функция, вычисляющая количество элементов в разности
void difference(char arr1[], char arr2[], int len1, int len2, char arrResult[]);				//функция, записывающая в множество результат разности

int lenOfComplements(char arr[], char u[], int len, int lenU);									//функция, вычисляющая количество элементов в дополнении
void complements(char arr[], char u[], int len, int lenU, char arrResult[]);					//функция, записывающая в множество результат дополнения

int lenOfSymmetricDifference(char arr1[], char arr2[], int len1, int len2);						//функция, вычисляющая количество элементов в кольцевой сумме
void symmetricDifference(char arr1[], char arr2[], int len1, int len2, char arrResult[]);		//функция, записывающая в множество результат кольцевой суммы

int main()
{
	system("chcp 65001");
	int len1;
	int len2;
	printf("Введите размер первого множества: ");
	scanf("%d", &len1);
	if(len1 > 18)
	{
		printf("Слишком большой размер!");
		exit(1);
	}
	printf("Введите размер второго множества: ");
	scanf("%d", &len2);
	getchar();
	if(len1 > 18)
	{
		printf("Слишком большой размер!");
		exit(1);
	}
	
	int lenResult;
	char arr1[len1];		//первое множество
	char arr2[len2];		//второе множество
	char u[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};		//универсум
	printf("\nЭлементы универсума:\n");
	for(int i = 0; i < 18; i++)
		printf("%c", u[i]);
	printf("\nВведите элементы первого множества\n");
	for(int i = 0; i < len1; i++)		//ввод элементов первого множества
		arr1[i] = getchar();
	getchar();
	printf("Введите элементы второго множества\n");
	for(int i = 0; i < len2; i++)		//ввод элементов второго множества
		arr2[i] = getchar();
		
	//Пересечение
	
    lenResult = lenOfIntersection(arr1, arr2, len1, len2);				//вычисление количества элементов в пересечении
	if(lenResult == 0)
	{
		printf("\nРезультат пересечения этих множеств:\nПустое множество\n\n");
	}
	else
	{
		char resultOfInter[lenResult];									//массив, где хранятся элементы пересечения

		intersection(arr1, arr2, len1, len2, resultOfInter);			//выполнение пересечения

		printf("\nРезультат пересечения этих множеств:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов пересечения
			printf("%c", resultOfInter[i]);
		printf("\n\n");
	}
	
	//Объединение
	
	lenResult = lenOfUnion(arr1, arr2, len1, len2);						//вычисление количества элементов в объединении
	if(lenResult == 0)
	{
		printf("\nРезультат объединения этих множеств:\nПустое множество\n\n");
	}
	else
	{
		char resultOfUnion[lenResult];									//массив, где хранятся элементы объединения

		_union(arr1, arr2, len1, len2, resultOfUnion);					//выполнение объединения

		printf("Результат объединения этих множеств:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов объединения
			printf("%c", resultOfUnion[i]);
		printf("\n\n");
	}
	
	//Разность arr1\arr2
	
	lenResult = lenOfDifference(arr1, arr2, len1, len2);				//вычисление количества элементов в разности
	if(lenResult == 0)
	{
		printf("Результат разности первого и второго множества:\nПустое множество\n\n");
	}
	else
	{
		char resultOfDifference1[lenResult];							//массив, где хранятся элементы разности

		difference(arr1, arr2, len1, len2, resultOfDifference1);		//выполнение разности

		printf("Результат разности первого и второго множества:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов разности
			printf("%c", resultOfDifference1[i]);
		printf("\n\n");
	}
	
	//Разность arr2\arr1
	
	lenResult = lenOfDifference(arr2, arr1, len2, len1);				//вычисление количества элементов в разности
	if(lenResult == 0)
	{
		printf("Результат разности второго и первого множества:\nПустое множество\n\n");
	}
	else
	{
		char resultOfDifference2[lenResult];							//массив, где хранятся элементы разности

		difference(arr2, arr1, len2, len1, resultOfDifference2);		//выполнение разности

		printf("Результат разности второго и первого множества:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов разности
			printf("%c", resultOfDifference2[i]);
		printf("\n\n");
	}
	
	//Дополнение первого множества до универсума
	
	lenResult = lenOfComplements(arr1, u, len1, 18);					//вычисление количества элементов в дополнении
	if(lenResult == 0)
	{
		printf("Результат дополнения первого множества до универсума:\nПустое множество\n\n");
	}
	else
	{
		char resultOfComplements1[lenResult];							//массив, где хранятся элементы дополнения
		
		complements(arr1, u, len1, 18, resultOfComplements1);			//выполнение дополнения
		
		printf("Результат дополнения первого множества до универсума:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов дополнения
			printf("%c", resultOfComplements1[i]);
		printf("\n\n");
	}
	
	//Дополнение второго множества до универсума
	
	lenResult = lenOfComplements(arr2, u, len2, 18);					//вычисление количества элементов в дополнении
	if(lenResult == 0)
	{
		printf("Результат дополнения второго множества до универсума:\nПустое множество\n\n");
	}
	else
	{
		char resultOfComplements2[lenResult];							//массив, где хранятся элементы дополнения
		
		complements(arr2, u, len2, 18, resultOfComplements2);			//выполнение дополнения
		
		printf("Результат дополнения второго множества до универсума:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов дополнения
			printf("%c", resultOfComplements2[i]);
		printf("\n\n");
	}
	
	//Кольцевая сумма
	
	lenResult = lenOfSymmetricDifference(arr1, arr2, len1, len2);		//вычисление количества элементов в кольцевой сумме
	if(lenResult == 0)
	{
		printf("Результат кольцевой суммы этих множеств:\nПустое множество\n\n");
	}
	else
	{
		char resultOfSymmetricDifference[lenResult];					//массив, где хранятся элементы кольцевой суммы

		symmetricDifference(arr1, arr2, len1, len2, resultOfSymmetricDifference);		//выполнение кольцевой суммы

		printf("Результат кольцевой суммы этих множеств:\n");
		for(int i = 0; i < lenResult; i++)								//вывод элементов кольцевой суммы
			printf("%c", resultOfSymmetricDifference[i]);
		printf("\n\n");
	}
	
	return 0;
}

int lenOfIntersection(char arr1[], char arr2[], int len1, int len2)
{
	int lenResult = 0;
	for(int i = 0; i < len1; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				lenResult++;
			}
		}
	}
	return lenResult;
}

void intersection(char arr1[], char arr2[], int len1, int len2, char arrResult[])
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
}

int lenOfUnion(char arr1[], char arr2[], int len1, int len2)
{
	int lenResult = 0;
	int flag;
	lenResult += len1;
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
			lenResult++;
		}
	}
	return lenResult;
}

void _union(char arr1[], char arr2[], int len1, int len2, char arrResult[])
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
}

int lenOfDifference(char arr1[], char arr2[], int len1, int len2)
{
	int lenResult = len1;
	for(int i = 0; i < len1; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				lenResult--;
			}
		}
	}
	return lenResult;
	
}

void difference(char arr1[], char arr2[], int len1, int len2, char arrResult[])
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
}

int lenOfComplements(char arr[], char u[], int len, int lenU)
{
	int lenResult = lenU - len;
	return lenResult;
}

void complements(char arr[], char u[], int len, int lenU, char arrResult[])
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
}

int lenOfSymmetricDifference(char arr1[], char arr2[], int len1, int len2)
{
	int lenResult = len1 + len2;
	for(int i = 0; i < len1; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				lenResult -= 2;
			}
		}
	}
	return lenResult;
}

void symmetricDifference(char arr1[], char arr2[], int len1, int len2, char arrResult[])
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
}