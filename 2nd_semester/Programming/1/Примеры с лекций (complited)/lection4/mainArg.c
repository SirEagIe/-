#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	system("chcp 65001");
	system("cls");
	printf("Программа '%s'\nЧисло параметров при запуске - %d", argv[0], argc - 1);
	for(int i = 0; i < argc; i++)
		printf("\n%d-й параметр: %s", i, argv[i]);
	printf("\n\nСписок переменных окружения:");
	for(int i = 1; i < envp[i]; i++)
		printf("\n%s", envp[i]);
	return 0;
}