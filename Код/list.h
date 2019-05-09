#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct game {
	int id;				//���������� ����� � ������
	char *name;		//�������� ����
	char *genre;    //���� ����
	float fans;		//������ ������� (x �� 10)
	int critic;		//������ �������� (x �� 100)
	int me;			//��� ������	 (x �� 5)
	int data[3];	//���� ������ ����
	struct game *next;		//��������� �� ��������� ������� ������
}game;

typedef struct head {	//������������ ������� (��������� ������)
	int cnt;			//���������� ������ ������
	struct game *first;	//��������� �� ������ �������
	struct game *last;	//��������� �� ��������� �������
}head;

void read(head *h);			//���������� � �����
void print(head *h);		//����� ����� ������
void adding(head *h);		//���������� �������� ������ � ����������
void delete(head *h);		//�������� �������� ������
void edit(head *h);			//�������������� �������� ������
void search(head *h);		//����� �� ���������
void sorty(head *h);		//���������� �� ���������
void delall(head *h);		//�������� ����� ������

int menuid(head *h);	//���� ��� ��������� ������ ��������, � ������� ���� ��������
int task(); 	//������� ��� ������ ��������� ������
int menusort();		//���� ������ ��� ����������
#endif 
