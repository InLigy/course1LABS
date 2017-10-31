#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#pragma warning (disable:4996)
using namespace std;


void vvod(bool *flagSetStrig, int *strSize, char **str);
void obrabotka(bool *flagSetStrig, int *strSize, char **str);
void vivod(bool *flagSetStrig, char **str, int *strSize);

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flagSetStrig = false;
	int strSize = 0;
	char *str = NULL;

	int menu = 0;
	while (true)
	{
		printf("\n1.Создать\n2.Обработать\n3.Вывести\n4.Выход\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
		{
			vvod(&flagSetStrig, &strSize, &str);
			break;
		}
		case 2:
		{
			obrabotka(&flagSetStrig, &strSize, &str);
			break;
		}
		case 3:
		{
			vivod(&flagSetStrig, &str, &strSize);
			break;
		}
		case 4:
		{
			printf("Пока D:");
			exit(0);
		}
		}
	}
	system("pause");
	return (0);
}


void vvod(bool *flagSetStrig, int *strSize, char **str)
{
	*flagSetStrig = true;
	printf("Введите строку\n");

	delete[] * str;
	char ch = ' ';
	*str = new char[1];
	int i = 0;
	ch = getchar();
	while ((ch = getchar()) != '\n')
	{
		(*str)[i++] = ch;

		char *copyStr = new char[i + 1];
		strncpy(copyStr, *str, i);

		delete[] * str;
		*str = copyStr;
	}

	(*str)[i++] = '\0';
	
	char *copyStr = new char[i + 1];
	strncpy(copyStr, *str, i);

	delete[] * str;
	*str = copyStr;

	
	*strSize = i;
}

void obrabotka(bool *flagSetStrig, int *strSize, char **str)
{
	char glas[] = "aeiouyаоиеёэыуюя";
	char tok[] = " ,.!?-";
	char *copyStr = new char[*strSize];
	
	for (int i = 0; i < *strSize; i++)
	{
		copyStr[i] = (*str)[i];
	}


	printf("\n%d\n", *strSize);
	if (*flagSetStrig)
	{
		char *pch = strtok(copyStr, tok);
		while (pch)
		{
			int gl = 0, sogl = 0;
			for (int i = 0; i < strlen(pch); i++)
			{
				if (strchr(glas, tolower(pch[i])))
				{
					gl+= 1;
				}
				else
				{
					sogl += 1;
				}
			}
			if (gl > sogl)
			{
				printf("%s ", pch);
			}
			pch = strtok(0, tok);
		}
	}
	else
	{
		printf("Введите строку!(1)\n");
	}
}

void vivod(bool *flagSetStrig, char **str, int *strSize)
{
	if (*flagSetStrig)
	{
		printf("\n");
		for (int i = 0; i < *strSize; i++)
		{
			printf("%c", (*str)[i]);
		}
	}
	else
	{
		printf("Введите строку!(1)\n");
	}
}
