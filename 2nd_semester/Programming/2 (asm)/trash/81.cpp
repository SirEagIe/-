#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int l_name = 30, l_year = 5, l_pay = 10, l_buf = l_name + l_year + l_pay;

struct Man
{
	int birth_year;
	char name[l_name + 1];
	float pay;
};

int read_dbase(const char * filename, struct Man dbase[], const int l_dbase, int * n_record);
void print(struct Man m);
void select(struct Man dbase[], const int n_record, const int year);
void select(struct Man dbase[], const int n_record, const float pay);

int main()
{
	system("chcp 65001");
	const int l_dbase = 100;
	struct Man dbase[l_dbase];
	int n_record = 0;
	if(read_dbase("txt6.txt", dbase, l_dbase, &n_record) != 0)
		return 1;
	int option;
	int year;
	float pay;
	do
	{
		printf("----------------------------\n");
		printf("1 - Сведения по году рождения\n");
		printf("2 - Сведения по окладу\n");
		printf("3 - Выход\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("Введите год ");
				scanf("%d", &year);
				select(dbase, n_record, year);
				break;
			case 2:
				printf("Введите оклад ");
				scanf("%f", &pay);
				select(dbase, n_record, pay);
				break;
			case 3:
				return 0;
			default:
				printf("Надо вводить число от 1 до 3\n");
		}
	}
	while(1);
	return 0;
}

void select(struct Man dbase[], const int n_record, const int year)
{
	printf("Вывод сведений по году рождения\n");
	int success = 0;
	for(int i = 0; i < n_record; i++)
	{
		if(dbase[i].birth_year >= year)
		{
			print(dbase[i]);
			success = 1;
		}
	}
	if(!success)
		printf("Таких сотрудников нет\n");
}

void select(struct Man dbase[], const int n_record, const float pay)
{
	printf("Вывод сведений по окладу\n");
	int success = 0;
	for(int i = 0; i < n_record; i++)
	{
		if(dbase[i].pay >= pay)
		{
			print(dbase[i]);
			success = 1;
		}
	}
	if(!success)
		printf("Таких сотрудников нет\n");
}

void print(struct Man m)
{
	printf("%s%i %.2f\n", m.name, m.birth_year, m.pay);
}

int read_dbase(const char * filename, struct Man dbase[], const int l_dbase, int * n_record)
{
	char buf[l_buf + 1];
	FILE *fp;
	fp = fopen(filename, "r+");
	if(fp == NULL)
	{
		printf("Ошибка чтения файла\n");
		exit(1);
	}
	int i = 0;
	while(fgets(buf, l_buf, fp))
	{
		if( i >= l_dbase)
		{
			printf("Слишком большой файл\n");
			return 1;
		}
		strncpy(dbase[i].name, buf, l_name);
		dbase[i].name[l_name] = '\0';
		dbase[i].birth_year = atoi(&buf[l_name]);
		dbase[i].pay = atof(&buf[l_name + l_year]);
		i++;
	}
	*n_record = i;
	fclose(fp);
	return 0;
}