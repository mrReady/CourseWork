#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <string.h>
#define MAX 500

void change(game *l1, game *l2);		//замена местами данных

//================================================================================================================================================================================================

void adding(head *h) {		//добавления элемента списка с клавиатуры
	game *l = NULL;			//создаю новый элемент
    int len;
	l = (game*)malloc(sizeof(game));
	l->name = (char*)malloc(MAX * sizeof(char));
	l->genre = (char*)malloc(MAX * sizeof(char));
	if (l && l->name && l->genre) {		//проверка на выделившуюся память
		puts("Print name of game:");	//прошу пользователя ввести информацию об игре по одному полю
		fgets(l->name,MAX*sizeof(char),stdin);
		len = strlen(l->name);
		l->name[len - 1] = '\0';
		puts("Print genre of game:");
		fgets(l->genre,MAX*sizeof(char),stdin);
		len = strlen(l->genre);
		l->genre[len - 1] = '\0';
		do {
			puts("Print fans rating for this game from 0 to 10:");
			scanf("%f", &(l->fans));
			fgets(stdin,MAX*sizeof(char),stdin);		//Очищаю поток символов, которые не считались
			if (l->fans < 0 || l->fans > 10)			//проверка на допустимый ввод
				puts("Error of print.\nRe-enter please\n");
		} while (l->fans < 0 || l->fans > 10);
		do {
			puts("Print critic rating for this game from 0 to 100:");
			scanf("%d", &(l->critic));
			fgets(stdin,MAX*sizeof(char),stdin);
			if (l->critic < 0 || l->critic > 100)
				puts("Error of print.\nRe-enter please\n");
		} while (l->critic < 0 || l->critic > 100);
		do {
			puts("Print your rating for this game from 0 to 5:");
			scanf("%d", &(l->me));
			fgets(stdin,MAX*sizeof(char),stdin);
			if (l->me < 0 || l->me > 5)
				puts("Error of print.\nRe-enter please\n");
		} while (l->me < 0 || l->me > 5);
		do {
			puts("Print data of exit game in format \"day.month.year\" :");
			scanf("%d.%d.%d", &(l->data[0]), &(l->data[1]), &(l->data[2]));		//допускаю, что игры выходили с 1940 до 2100, и день и месяц не могут быть 0
			fgets(stdin,MAX*sizeof(char),stdin);
			if (l->data[0] < 1 || l->data[0] > 31 || l->data[1] < 1 || l->data[1] > 12 || l->data[2] < 1940 || l->data[3] > 2100)
				puts("Error of print.\nRe-enter please");
		} while (l->data[0] < 1 || l->data[0] > 31 || l->data[1] < 1 || l->data[1] > 12 || l->data[2] < 1940 || l->data[3] > 2100);
		if (h->first == NULL) {	//если это будет первый элемент в списке
			h->first = l;
		}
		else {
			h->last->next = l;  //соединяю "последний" элемент с новым

		}
		l->id = ++(h->cnt);	//увиличиваю счётчик колличества элементов и присваиваю это число к номеру последнего элемента в списке
		l->next = NULL;		//последний элемент в next указывает на NULL
		h->last = l;		//этот элемент будет последним для головы списка
	}
	else {
		puts("Error of memory!");		//ошибка памяти и освобождение памяти, если осталась
		if (l)
			free(l);
		if (l->name)
			free(l->name);
		if (l->genre)
			free(l->genre);
	}
}

//================================================================================================================================================================================================

void edit(head *h) {		//редактирование элемента списка
	int n, k = menuid(h), p = task();		//прошу уточнить, что менять
	float f;
	if (k && p) {		//если пользователю не надо обратно в меню, то работаю
		game *l = h->first;
		while (l->id != k)		//нахожу нужный элемент
			l = l->next;
		puts("Now here is:\n");
		if (p == 1) {		//тут условие на необходимый параметр
			printf("%s\n\nEdit name game of card like you want: ", l->name);	//вывожу то, что тут есть на данный момент, и предлагаю написать свой вариант
			fgets(l->name,MAX*sizeof(char),stdin);		//считываю
		}
		if (p == 2) {		//аналогично другим параметрам
			printf("%s\n\nEdit ganre of card like you want: ", l->genre);
			fgets(l->genre,MAX*sizeof(char),stdin);
		}
		if (p == 3) {
			printf("%f\n\nEdit fans rating of card like you want from 0 to 10: ", l->fans);
			do {
				scanf("%f", &f);
				fgets(stdin,MAX*sizeof(char),stdin);
				if (f < 0 || f > 10)			//проверка на допустимый ввод
					puts("Error of print.\nRe-enter please\n");
			} while (f < 0 || f > 10);
			l->fans = f;
		}
		if (p == 4) {
			printf("%d\n\nEdit critic rating of card like you want from 0 to 100: ", l->critic);
			do {
				scanf("%d", &n);
				fgets(stdin,MAX*sizeof(char),stdin);
				if (n < 0 || n > 100)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 0 || n > 100);
			l->critic = n;
		}
		if (p == 5) {
			printf("%d\n\nEdit my rating of card like you want from 0 to 5: ", l->me);
			do {
				scanf("%d", &n);
				fgets(stdin,MAX*sizeof(char),stdin);
				if (n < 0 || n > 5)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 0 || n > 5);
			l->me = n;
		}
		if (p == 6) {
			printf("%d\n\nEdit day game of card like you want from 1 to 31: ", l->data[0]);
			do {
				n = scanf("%d", &n);
				fgets(stdin,MAX*sizeof(char),stdin);
				if (n < 1 || n > 31)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 1 || n > 31);
			l->data[0] = n;
		}
		if (p == 7) {
			printf("%d\n\nEdit month game of card like you want from 1 to 12: ", l->data[1]);
			do {
				scanf("%d", &n);
				fgets(stdin,MAX*sizeof(char),stdin);
				if (n < 1 || n > 12)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 1 || n > 12);
			l->data[1] = n;
		}
		if (p == 8) {
			printf("%d\n\nEdit year game of card like you want from 1940 to 2100: ", l->data[2]);
			do {
				scanf("%d", &n);
				fgets(stdin,MAX*sizeof(char),stdin);
				if (n < 1940 || n > 2100)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 1940 || n > 2100);
			l->data[2] = n;
		}
	}
}

//================================================================================================================================================================================================

void search(head *h) {		//поиск по параметру
	int p = task(), k = 0;	//получаю параметр
	int n;
	float f;
	char *s = NULL;
	game *l = h->first;
	s = (char*)malloc(MAX * sizeof(char));
	if (s && p) {				// если пользователю не надо обратно в меню и память есть на строку, то работаю
		puts("Enter that you're search in this parameter: ");
		gets(s);		//в s строка текста
		n = atoi(s);	//в n целое число
		f = atof(s);	//в f вещественное число
		printf("|%2s |%39s |%19s |%4s |%6s |%2s |%9s |\n", "Id", "Full name of game", "Genre of game", "Fans", "Critic", "Me", "Data");
		printf("+---+----------------------------------------+--------------------+-----+-------+---+----------+\n");
		for (int i = 1; i <= h->cnt; i++) {
				if (p == 1 && strstr(l->name, s)) {  //если параметр совпал и найднена совпадение по строчкам (или равенство цифр), то вывожу
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;		//если хоть что-то нашлось, то ключ не равен 0
				}
				if (p == 2 && strstr(l->genre, s)) {	//далее аналогично
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
				if (p == 3 && l->fans == f) {
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
				if (p == 4 && l->critic == n) {
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
				if (p == 5 && l->me == n) {
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
				if (p == 6 && l->data[0] == n) {
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
				if (p == 7 && l->data[1] == n) {
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
				if (p == 8 && l->data[2] == n) {
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;
				}
			l = l->next;
		}
		if (!k) {		//если ключ = 0, то никаких элементов не найдено
			system("cls");
			puts("Sorry, but there is no what you're looking for.");
		}
	}
	else
		puts("Error of memory!");		//ошибка памяти
	if (s)				//освобождение памяти, если осталась
		free(s);
	puts("Press Enter to continue.");
	getchar();
}

//================================================================================================================================================================================================

void sorty(head *h) {		//сортировка по параметру
	int p = task(), q = menusort();		//пользователь даёт настройки, что делать
	game *l1 = h->first, *l2;
	if (p && q)		//если пользователю не надо в меню, то
		for (int i = 1; i < h->cnt; i++) {		//сортировка пузырьком (сравниваю 1 со всеми впереди стоящими, потом сравниваю 2 ....)
			l2 = l1->next;
			for (int j = l2->id; j <= h->cnt; j++) {
				if (p == 1 && ((q == 1 && strcmp(l1->name, l2->name) > 0) || (q == 2 && strcmp(l1->name, l2->name) < 0)))	//тут учитываются все настройки от пользователя
					change(l1, l2);		//замена местами данных
				if (p == 2 && ((q == 1 && strcmp(l1->genre, l2->genre) > 0) || (q == 2 && strcmp(l1->genre, l2->genre) < 0)))	//далее аналогично
					change(l1, l2);
				if (p == 3 && ((q == 1 && l1->fans > l2->fans) || (q == 2 && l1->fans < l2->fans)))
					change(l1, l2);
				if (p == 4 && ((q == 1 && l1->critic > l2->critic) || (q == 2 && l1->critic < l2->critic)))
					change(l1, l2);
				if (p == 5 && ((q == 1 && l1->me > l2->me) || (q == 2 && l1->me < l2->me)))
					change(l1, l2);
				if (p == 6 && ((q == 1 && l1->data[0] > l2->data[0]) || (q == 2 && l1->data[0] < l2->data[0])))
					change(l1, l2);
				if (p == 7 && ((q == 1 && l1->data[1] > l2->data[1]) || (q == 2 && l1->data[1] < l2->data[1])))
					change(l1, l2);
				if (p == 8 && ((q == 1 && l1->data[2] > l2->data[2]) || (q == 2 && l1->data[2] < l2->data[2])))
					change(l1, l2);
				l2 = l2->next;
			}
			l1 = l1->next;
		}
}

void change(game *l1, game *l2) {		//замена местами данных
	int n;
	float f;
	char *s;
	s = l1->name;
	l1->name = l2->name;
	l2->name = s;

	s = l1->genre;
	l1->genre = l2->genre;
	l2->genre = s;

	f = l1->fans;
	l1->fans = l2->fans;
	l2->fans = f;

	n = l1->critic;
	l1->critic = l2->critic;
	l2->critic = n;

	n = l1->me;
	l1->me = l2->me;
	l2->me = n;

	n = l1->data[0];
	l1->data[0] = l2->data[0];
	l2->data[0] = n;

	n = l1->data[1];
	l1->data[1] = l2->data[1];
	l2->data[1] = n;

	n = l1->data[2];
	l1->data[2] = l2->data[2];
	l2->data[2] = n;
}
