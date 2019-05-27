#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 500

void addlist(head *h, FILE *f);		//добавление по элементу

//================================================================================================================================================================================================

void read(head *h) {					//считывание с файла
	FILE *f;
	if ((f = fopen("game.csv", "r")) == NULL)
		puts("Cannot open file.");
	else {
		while (!feof(f)) {	//пока не конец файла
			addlist(h, f);	//добавляю по элементу
		}
		if (fclose(f) == EOF) puts("Cannot close file.");
	}
}

void addlist(head *h, FILE *f) {		//добавление по элементу
	game *l;
	l = (game*)malloc(sizeof(game));
	l->name = (char*)malloc(MAX * sizeof(char));
	l->genre = (char*)malloc(MAX * sizeof(char));
	if (l && l->genre && l->name) {					//строчкой ниже заполняем лист списка информацией из файла	
		fscanf(f, "%[^;];%[^;];%f;%d;%d;%d;%d;%d", l->name, l->genre, &(l->fans), &(l->critic), &(l->me), &(l->data[0]), &(l->data[1]), &(l->data[2]));
		fgetc(f);				//считываю символ конца строки
		if (h->first != NULL) 	//если первый элемент списка есть, то...
			h->last->next = l;	//...то последний элемент будет заменён на новосчитанный 
		else {			//если это первый элемент списка, то он и будет замыкающим
			h->first = l;
			h->last = l;
		}
		l->id = ++(h->cnt);	//увиличиваю счётчик колличества элементов и присваиваю это число к номеру последнего элемента в списке
		l->next = NULL;		//последний элемент в next указывает на NULL
		h->last = l;		//этот элемент будет последним для головы списка
	}
	else {
		puts("error of memory!");
		if (l)
			free(l);
		if (l->name)
			free(l->name);
		if (l->genre)
			free(l->genre);
		f = NULL;
	}
}

//================================================================================================================================================================================================

void print(head *h) {		//Вывод всего списка
	game *l = h->first;		//выводим с первого элемента списка
	printf("|%2s |%39s |%19s |%4s |%6s |%2s |%9s |\n", "Id", "Full name of game", "Genre of game", "Fans", "Critic", "Me", "Data");
	printf("+---+----------------------------------------+--------------------+-----+-------+---+----------+\n");
	for (int i = 1; i <= h->cnt; i++) {
		printf("|%3d|%40s|%20s|%5.1f|%7d|%3d|%2d.%2d.%4d|\n", l->id, l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);
		l = l->next;		//переход на следующий элемент списка
	}
	puts("Press Enter to continue.");
	getchar();
}

//================================================================================================================================================================================================

void delete(head *h) {				//удаление элемента списка
	int k = menuid(h);					//получаю, какой элемент просит удалить пользователь
	game *l = h->first, *lprev = h->first;	//два элемента: удаляемый и стоящий перед ним элемент
	if (k != 0) {		//если попросили не выходить обратно в меню, то...
		if (l->id == k) {		//если надо удалить первый элемент
			h->first = l->next;	//тогда первый элемент будет вторым, а первый удалим
		}
		else if (h->last->id == k) {		//иначе, если надо удалить последний элемент
			while (lprev->next != h->last)	//тогда ищу предпоследний
				lprev = lprev->next;
			l = h->last;			//удаляемый будет последним
			h->last = lprev;		//а последним станет предыдущий
			lprev->next = NULL;		//который указывает на NULL
		}
		else {	//иначе надо удалить элемент в середине списка
			while (lprev->id != k - 1)		//ищем предыдущий элемент
				lprev = lprev->next;
			l = lprev->next;		//удаляемый это следующий
			lprev->next = l->next;	//предыдущий будет указывать через удаляемый элемент на следующий
		}
		if (l)
			free(l);		//удаляем выбранный элемент
		l = h->first;	//теперь от начала списка
		while (l != NULL) {
			if (l->id > k) 
				l->id--;	//уменьшаем номер элемента на -1, если элемент стоял перед удаляемым
			l = l->next;
		}
		h->cnt--;		//колличество элементов уменьшилось на 1
	}
}

void delall(head *h) {		//удаление всего списка
	game *l = h->first, *lnext = h->first->next;	//два элемента: удаляемый и стоящий следом за ним элемент
	while (h->last != l) {	//пока удаляем не последний
		if (l)
			free(l);		//удаление элемента из памяти
		l = lnext;			//переходим к следующему
		lnext = lnext->next;	//а следующий к "следующему"
	}
	if (l)			//удаляем последний
		free(l);
	h->cnt = 0;			//зануляем голову
	h->first = NULL;
	h->last = NULL;
}

//================================================================================================================================================================================================

void saveinfile(head *h) {		//сохранение в новый файл
	FILE *f = NULL;
	game *l = h->first;
	if ((f = fopen("new game.csv", "a")) == NULL)
		puts("Cannot open file.");
	else {
		while (l != NULL) {	//пока не конец файла
			fprintf(f, "%s;%s;%.1f;%d;%d;%d;%d;%d\n", l->name, l->genre, l->fans, l->critic, l->me, l->data[0], l->data[1], l->data[2]);	//добавляю по элементу
			l = l->next;
		}
		if (fclose(f) == EOF) puts("Cannot close file.");
	}
