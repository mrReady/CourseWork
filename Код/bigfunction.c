#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#define MAX 500

void change(game *l1, game *l2);		//������ ������� ������

//================================================================================================================================================================================================

void adding(head *h) {		//���������� �������� ������ � ����������
	game *l = NULL;			//������ ����� �������
	l = (game*)malloc(sizeof(game));
	l->name = (char*)malloc(MAX * sizeof(char));
	l->genre = (char*)malloc(MAX * sizeof(char));
	if (l && l->name && l->genre) {		//�������� �� ������������ ������
		puts("Print name of game:");	//����� ������������ ������ ���������� �� ���� �� ������ ����
		gets(l->name);
		puts("Print genre of game:");
		gets(l->genre);
		do {
			puts("Print fans rating for this game from 0 to 10:");
			scanf("%f", &(l->fans));
			gets();		//������ ����� ��������, ������� �� ���������
			if (l->fans < 0 || l->fans > 10)			//�������� �� ���������� ����
				puts("Error of print.\nRe-enter please\n");
		} while (l->fans < 0 || l->fans > 10);
		do {
			puts("Print critic rating for this game from 0 to 100:");
			scanf("%d", &(l->critic));
			gets();
			if (l->critic < 0 || l->critic > 100)
				puts("Error of print.\nRe-enter please\n");
		} while (l->critic < 0 || l->critic > 100);
		do {
			puts("Print your rating for this game from 0 to 5:");
			scanf("%d", &(l->me));
			gets();
			if (l->me < 0 || l->me > 5)
				puts("Error of print.\nRe-enter please\n");
		} while (l->me < 0 || l->me > 5);
		do {
			puts("Print data of exit game in format \"day.month.year\" :");		
			scanf("%d.%d.%d", &(l->data[0]), &(l->data[1]), &(l->data[2]));		//��������, ��� ���� �������� � 1940 �� 2100, � ���� � ����� �� ����� ���� 0 
			gets();
			if (l->data[0] < 1 || l->data[0] > 31 || l->data[1] < 1 || l->data[1] > 12 || l->data[2] < 1940 || l->data[3] > 2100)
				puts("Error of print.\nRe-enter please");
		} while (l->data[0] < 1 || l->data[0] > 31 || l->data[1] < 1 || l->data[1] > 12 || l->data[2] < 1940 || l->data[3] > 2100);
		if (h->first == NULL) {	//���� ��� ����� ������ ������� � ������
			h->first = l;
		}
		else {
			h->last->next = l;  //�������� "���������" ������� � �����

		}
		l->id = ++(h->cnt);	//���������� ������� ����������� ��������� � ���������� ��� ����� � ������ ���������� �������� � ������
		l->next = NULL;		//��������� ������� � next ��������� �� NULL
		h->last = l;		//���� ������� ����� ��������� ��� ������ ������
	}
	else {
		puts("Error of memory!");		//������ ������ � ������������ ������, ���� ��������
		if (l)
			free(l);
		if (l->name)
			free(l->name);
		if (l->genre)
			free(l->genre);
	}
}

//================================================================================================================================================================================================

void edit(head *h) {		//�������������� �������� ������
	int n, k = menuid(h), p = task();		//����� ��������, ��� ������
	float f;
	if (k && p) {		//���� ������������ �� ���� ������� � ����, �� �������
		game *l = h->first;
		while (l->id != k)		//������ ������ �������
			l = l->next;
		puts("Now here is:\n");
		if (p == 1) {		//��� ������� �� ����������� ��������
			printf("%s\n\nEdit name game of card like you want: ", l->name);	//������ ��, ��� ��� ���� �� ������ ������, � ��������� �������� ���� �������
			gets(l->name);		//��������
		}
		if (p == 2) {		//���������� ������ ����������
			printf("%s\n\nEdit ganre of card like you want: ", l->genre);
			gets(l->genre);
		}
		if (p == 3) {
			printf("%f\n\nEdit fans rating of card like you want from 0 to 10: ", l->fans);
			do {
				scanf("%f", &f);
				gets();
				if (f < 0 || f > 10)			//�������� �� ���������� ����
					puts("Error of print.\nRe-enter please\n");
			} while (f < 0 || f > 10);
			l->fans = f;
		}
		if (p == 4) {
			printf("%d\n\nEdit critic rating of card like you want from 0 to 100: ", l->critic);
			do {
				scanf("%d", &n);
				gets();
				if (n < 0 || n > 100)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 0 || n > 100);
			l->critic = n;
		}
		if (p == 5) {
			printf("%d\n\nEdit my rating of card like you want from 0 to 5: ", l->me);
			do {
				scanf("%d", &n);
				gets();
				if (n < 0 || n > 5)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 0 || n > 5);
			l->me = n;
		}
		if (p == 6) {
			printf("%d\n\nEdit day game of card like you want from 1 to 31: ", l->data[0]);
			do {
				n = scanf("%d", &n);
				gets();
				if (n < 1 || n > 31)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 1 || n > 31);
			l->data[0] = n;
		}
		if (p == 7) {
			printf("%d\n\nEdit month game of card like you want from 1 to 12: ", l->data[1]);
			do {
				scanf("%d", &n);
				gets();
				if (n < 1 || n > 12)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 1 || n > 12);
			l->data[1] = n;
		}
		if (p == 8) {
			printf("%d\n\nEdit year game of card like you want from 1940 to 2100: ", l->data[2]);
			do {
				scanf("%d", &n);
				gets();
				if (n < 1940 || n > 2100)
					puts("Error of print.\nRe-enter please\n");
			} while (n < 1940 || n > 2100);
			l->data[2] = n;
		}
	}
}

//================================================================================================================================================================================================

void search(head *h) {		//����� �� ���������
	int p = task(), k = 0;	//������� ��������
	int n;
	float f;
	char *s = NULL;
	game *l = h->first;
	s = (char*)malloc(MAX * sizeof(char));
	if (s && p) {				// ���� ������������ �� ���� ������� � ���� � ������ ���� �� ������, �� �������
		puts("Enter that you're search in this parameter: ");
		gets(s);		//� s ������ ������
		n = atoi(s);	//� n ����� �����
		f = atof(s);	//� f ������������ �����
		printf("|%2s |%39s |%19s |%4s |%6s |%2s |%9s |\n", "Id", "Full name of game", "Genre of game", "Fans", "Critic", "Me", "Data");
		printf("+---+----------------------------------------+--------------------+-----+-------+---+----------+\n");
		for (int i = 1; i <= h->cnt; i++) {
				if (p == 1 && strstr(l->name, s)) {  //���� �������� ������ � �������� ���������� �� �������� (��� ��������� ����), �� ������
					printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
					k++;		//���� ���� ���-�� �������, �� ���� �� ����� 0
				}
				if (p == 2 && strstr(l->genre, s)) {	//����� ����������
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
		if (!k) {		//���� ���� = 0, �� ������� ��������� �� �������
			system("cls");
			puts("Sorry, but there is no what you're looking for.");
		}
	}
	else
		puts("Error of memory!");		//������ ������ 
	if (s)				//������������ ������, ���� ��������
		free(s);
	puts("Press Enter to continue.");
	getchar();
}

//================================================================================================================================================================================================

void sorty(head *h) {		//���������� �� ���������
	int p = task(), q = menusort();		//������������ ��� ���������, ��� ������
	game *l1 = h->first, *l2;
	if (p && q)		//���� ������������ �� ���� � ����, ��
		for (int i = 1; i < h->cnt; i++) {		//���������� ��������� (��������� 1 �� ����� ������� ��������, ����� ��������� 2 ....) 
			l2 = l1->next;
			for (int j = l2->id; j <= h->cnt; j++) {
				if (p == 1 && ((q == 1 && strcmp(l1->name, l2->name) > 0) || (q == 2 && strcmp(l1->name, l2->name) < 0)))	//��� ����������� ��� ��������� �� ������������
					change(l1, l2);		//������ ������� ������
				if (p == 2 && ((q == 1 && strcmp(l1->genre, l2->genre) > 0) || (q == 2 && strcmp(l1->genre, l2->genre) < 0)))	//����� ����������
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

void change(game *l1, game *l2) {		//������ ������� ������
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