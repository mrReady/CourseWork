/*
 урсова€
V 1.5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
//#include <libintl.h> 
//#include <locale.h> 
//#define _(string) gettext (string)

int menu(int k);		// основное меню 
void refer(head *h);	//справка
void saveinfile(head *h);		//сохранение в новый файл

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
			read(&h);		//считывание с файла
		if (c == 2 && h.cnt)
			print(&h);		//вывод всего списка
		if ((c == 3 && h.cnt) || (c == 2 && !h.cnt))
			adding(&h);		//добавлени€ элемента списка с клавиатуры
		if (c == 4 && h.cnt)
			edit(&h);		//редактирование элемента списка
		if (c == 5 && h.cnt)
			delete(&h);		//удаление элемента списка
		if (c == 6 && h.cnt)
			search(&h);		//поиск по параметру
		if (c == 7 && h.cnt)
			sorty(&h);		//сортировка по параметру
		if (c == 8 && h.cnt)
			delall(&h);		//удаление всего списка
		if ((c == 9 && h.cnt) || (c == 3 && !h.cnt))
			refer(&h);		//справка
	}
	if (h.cnt)		//если есть что сохран€ть, то сохран€ю
		saveinfile(&h);		//сохранение в новый файл
	return 0;
}

//================================================================================================================================================================================================

int menu(int h) { // основное меню 
	int c;
	if (!h) {	//до считывани€ из файла
		puts("If you are working with a file, but you returned to this menu, you could delete all list or file is empty");
		puts("\nChoose what you want to do with the file?\n0 - Exit\n1 - Read\n2 - Add new card\n3 - Reference");
	}
	if (h) {	//после считывани€
		puts("\nChoose what you want to do with the cards ?\n0 - Exit\n1 - Read\n2 - Print all list\n3 - Add new card\n4 - Edit card\n5 - Delete one card\n6 - Search for parameter\n7 - Sort for parameter\n8 - Delete all list\n9 - Reference\n");
	}
	scanf("%d", &c);
	puts("Okey");
	getchar();
	return c;
}

int menuid(head *h) {		//меню дл€ получени€ номера элемента, с которым надо работать
	int k = -1;
	while (k > h->cnt || k < 0) {	//проверка на ошибочный ввод
		printf("\n0 - back to menu\nSelect id that you need from 1 to %d\n", h->cnt);
		scanf("%d", &k);
		puts("Okey\n");
		if (k > h->cnt || k < 0)
			puts("Please re-enter");
		getchar();
	}
	return k;			//возвращаю id элемента дл€ работы с ним
}

int task() {		//подменю дл€ выбора параметра списка
	int p = -1;
	while (p < 0 || p > 8) {	//проверка на ошибочный ввод
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
	while (q < 0 || q > 2) {	//проверка на ошибочный ввод
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

void saveinfile(head *h) {		//сохранение в новый файл
	FILE *f;
	game *l = h->first;
	if ((f = fopen("new game.csv", "a")) == NULL)
		puts("Cannot open file.");
	else {
		while (l != NULL) {	//пока не конец файла
			fprintf(f, "%s;%s;%.1f;%d;%d;%d;%d;%d\n", l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);	//добавл€ю по элементу
			l = l->next;
		}
		if (fclose(f) == EOF) puts("Cannot close file.");
	}
}