#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct game {
	int id;				//порядковый номер в списке
	char *name;		//Название игры
	char *genre;    //жанр игры
	float fans;		//оценка фанатов (x из 10)
	int critic;		//оценка критиков (x из 100)
	int me;			//моя оценка	 (x из 5)
	int data[3];	//дата выхода игры
	struct game *next;		//указатель на следующий элемент списка
}game;

typedef struct head {	//Заголовочный элемент (заголовок списка)
	int cnt;			//количество листов списка
	struct game *first;	//указатель на первый элемент
	struct game *last;	//указатель на последний элемент
}head;

void read(head *h);			//считывание с файла
void print(head *h);		//Вывод всего списка
void adding(head *h);		//добавления элемента списка с клавиатуры
void delete(head *h);		//удаление элемента списка
void edit(head *h);			//редактирование элемента списка
void search(head *h);		//поиск по параметру
void sorty(head *h);		//сортировка по параметру
void delall(head *h);		//удаление всего списка

int menuid(head *h);	//меню для получения номера элемента, с которым надо работать
int task(); 	//подменю для выбора параметра списка
int menusort();		//меню выбора для сортировки
#endif 
