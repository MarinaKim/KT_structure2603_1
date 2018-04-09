#include<stdio.h>
#include <locale.h>
#include<iostream>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#define size 20
using namespace std;
struct age {
	int year;
	int day;
	int month;
};
void generateAge(age *t)
{
	t->day = 1 + rand() % 30;
	t->month = 1 + rand() % 11;
	t->year = 1960 + rand() % 50;
}

void generateName(char *name)
{
	strcpy(name, "person #");
	int a = 1 + rand() % 30;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}
struct Group
{
	char *name;
	age *Age;
	int *ses;

};

void sortSes(int *a, int r)
{
	int k;
	for (int i = 0;i < r;i++)
	{
		for (int j = r - 1;j >= 0;j--)
		{
			if (*(a + j) < *(a - j))
			{
				k = *(a - j);
				*(a - j) = *a;
				*a = k;
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;

	do
	{
		printf("¬ведите номер задани€: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			//1.	ќписать структуру с именем GROUP, содержащую пол€: 
			//	a.Name Ц фамили€ и инициалы
				//	b.DAT Ц дата рождени€(год, мес€ц, число)
				//	c.SES Ц успеваемость(массив из трех элементов).

			//		Ќаписать программу, выполн€ющую:
			//	Х	ввод с клавиатуры данных в массив GR5, состо€щий из 10 структур типа GROUP; вывод на экран записей, упор€доченных по возрастанию пол€ SES;
			//	Х	вывод списка студентов, возраст которых на 01.12.2010 года не превышает 20 лет;
			//	Х	если таких студентов нет Ц выдать сообщение.

		case 1: {
			int count = 5 + rand() % 5;
			printf("кол-во студентов: %d\n", count);
			Group *students = NULL;
			students = (Group*)malloc(count * sizeof(Group));
			if (students != 0)
			{
				for (int i = 0;i < count;i++)
				{
					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name);

					(students + i)->Age = (age*)malloc(12 * sizeof(age));
					generateAge((students + i)->Age);

					int k = (0 + rand() % 10);
					(students + i)->ses = (int*)calloc(k, sizeof(int));

					if ((2018 - (students + i)->Age->year) <= 20)
					{
						printf("# %d \t %s \t %d.%d.%d\n", i + 1, (students + i)->name, (students + i)->Age->day, (students + i)->Age->month, (students + i)->Age->year);

						int sum = 0;
						for (int j = 0;j < k;j++)
						{
							(students + i)->ses[j] = 2 + rand() % 4;
							printf("-->%d\n", (students + i)->ses[j]);
							sum += ((students + i)->ses[j]);
						}

						printf("ѕќ—Ћ≈ —ќ–“»–ќ¬ »: \n");
						sortSes((students + i)->ses, k);
						for (int j = 0;j < k;j++)
						{
							printf("-->%d\n", (students + i)->ses[j]);
						}

						if (k != 0)
						{
							printf("-----------------------------------------------------------\n");
							printf("средн€€ оценка: %d\n", sum / k);
						}
					}
					else
						printf("—тудент 20 лет нет\n");
				}
			}
			else
			{
				printf("пам€ть не выделена\n");
				exit(EXIT_FAILURE);

			}
		}break;

		case 2: {

		}break;
		}
	} while (n > 0);
}