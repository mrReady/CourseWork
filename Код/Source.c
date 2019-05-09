/*
��������
V 1.5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
//#include <libintl.h> 
//#include <locale.h> 
//#define _(string) gettext (string)

int menu(int k);		// �������� ���� 
void refer(head *h);	//�������
void saveinfile(head *h);		//���������� � ����� ����

//================================================================================================================================================================================================

int main() {
//	setlocale(LC_ALL, "ru");
	int c = 1, k = 1;
	head h;
	h.first = NULL;
	h.last = NULL;
	h.cnt = 0;
	while (c) {
		system("cls");
		c = menu(h.cnt);
		if (c == 1)
			read(&h);		//���������� � �����
		if (c == 2 && h.cnt)
			print(&h);		//����� ����� ������
		if ((c == 3 && h.cnt) || (c == 2 && !h.cnt))
			adding(&h);		//���������� �������� ������ � ����������
		if (c == 4 && h.cnt)
			edit(&h);		//�������������� �������� ������
		if (c == 5 && h.cnt)
			delete(&h);		//�������� �������� ������
		if (c == 6 && h.cnt)
			search(&h);		//����� �� ���������
		if (c == 7 && h.cnt)
			sorty(&h);		//���������� �� ���������
		if (c == 8 && h.cnt)
			delall(&h);		//�������� ����� ������
		if ((c == 9 && h.cnt) || (c == 3 && !h.cnt))
			refer(&h);		//�������
	}
	if (h.cnt)		//���� ���� ��� ���������, �� ��������
		saveinfile(&h);		//���������� � ����� ����
	return 0;
}

//================================================================================================================================================================================================

int menu(int h) { // �������� ���� 
	int c;
	if (!h) {	//�� ���������� �� �����
		puts("If you are working with a file, but you returned to this menu, you could delete all list or file is empty");
		puts("\nChoose what you want to do with the file?\n0 - Exit\n1 - Read\n2 - Add new card\n3 - Reference");
	}
	if (h) {	//����� ����������
		puts("\nChoose what you want to do with the cards ?\n0 - Exit\n1 - Read\n2 - Print all list\n3 - Add new card\n4 - Edit card\n5 - Delete one card\n6 - Search for parameter\n7 - Sort for parameter\n8 - Delete all list\n9 - Reference\n");
	}
	scanf("%d", &c);
	puts("Okey");
	getchar();
	return c;
}

int menuid(head *h) {		//���� ��� ��������� ������ ��������, � ������� ���� ��������
	int k = -1;
	while (k > h->cnt || k < 0) {	//�������� �� ��������� ����
		printf("\n0 - back to menu\nSelect id that you need from 1 to %d\n", h->cnt);
		scanf("%d", &k);
		puts("Okey\n");
		if (k > h->cnt || k < 0)
			puts("Please re-enter");
		getchar();
	}
	return k;			//��������� id �������� ��� ������ � ���
}

int task() {		//������� ��� ������ ��������� ������
	int p = -1;
	while (p < 0 || p > 8) {	//�������� �� ��������� ����
		puts("Select the parameter that you need:\n0 - back to menu\n1 - Name\n2 - Genre\n3 - Fans rating\n4 - Critic rating\n5 - My rating\n6 - Day\n7 - Month\n8 - Year\n");
		scanf("%d", &p);
		puts("Okey\n");
		if (p > 8 || p < 0)
			puts("Please re-enter");
		getchar();
	}
	return p;
}

int menusort() {
	int q = -1;
	while (q < 0 || q > 2) {	//�������� �� ��������� ����
		puts("Select sort order that you need:\n0 - back to menu\n1 - In escending order\n2 - In reverse order\n");
		scanf("%d", &q);
		puts("Okey\n");
		if (q > 2 || q < 0)
			puts("Please re-enter");
		getchar();
	}
	return q;
}

void refer(head *h) {
	puts("\nReference");
	puts("The file with which you will work in the program must be in the same folder in the program and called \"game.csv\".\nAt the end of the program, the list you have modified will be saved as \"new game.csv\".\nIf you want to continue working with the list you changed again, just rename \"new game.csv\" to \"game.csv\".\nIf you do not open the list or delete all items from the list, the program will not create a new file. \nYou can only read the \"game.csv\" file once.");
	puts("Press Enter to continue.");
	getchar();
}

void saveinfile(head *h) {		//���������� � ����� ����
	FILE *f;
	game *l = h->first;
	if ((f = fopen("new game.csv", "a")) == NULL)
		puts("Cannot open file.");
	else {
		while (l != NULL) {	//���� �� ����� �����
			fprintf(f, "%s;%s;%.1f;%d;%d;%d;%d;%d\n", l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);	//�������� �� ��������
			l = l->next;
		}
		if (fclose(f) == EOF) puts("Cannot close file.");
	}
}