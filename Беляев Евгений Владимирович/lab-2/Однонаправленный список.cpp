#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "time.h"
#include <conio.h> 
#include <Windows.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

struct node* init(struct node* head, int data);
struct node* addNachalo(struct node* head, int data);
struct node* addConec(struct node* head, int data);
struct node* addNPosition(struct node* head, int data, int position);
struct node* deleteElement(struct node* head, int data);
void printList(struct node* head);

int main()
{
	setlocale(LC_CTYPE, "rus");
	struct node* head = NULL;
	int vib, data, position;
	while (1)
	{
		cout << "1 - Создание нового списка\n";
		cout << "2 - Добавление элемента в начало\n";
		cout << "3 - добавление элемента в конец\n";
		cout << "4 - Добавление элемента на позицию\n";
		cout << "5 - Вывод списка\n";
		cout << "6 - удаление элемента\n";
		cout << "7 - выход\n";
		cout << "Сделайте выбор\n";
		cin >> vib;
		switch (vib)
		{
		case 1:
			if (head != NULL)
			{
				cout << "Cписок пуст\n";
				break;
			}
			cout << "Введите элемент: ";
			cin >> data;
			head = init(head, data);
			break;
		case 2:
			if (head == NULL)
			{
				cout << "Список пуст, начните список\n";
				break;
			}
			cout << "Введите элемент: ";
			cin >> data;
			head = addNachalo(head, data);
			break;
		case 3:
			if (head == NULL)
			{
				cout << "Список пуст, начните список\n";
				break;
			}
			cout << "Введите элемент: ";
			cin >> data;
			head = addConec(head, data);
			break;
		case 4:
			if (head == NULL)
			{
				cout << "Список пуст, начните список\n";
				break;
			}
			cout << "Введите элемент: ";
			cin >> data;
			cout << "Введите позицию: ";
			cin >> position;
			head = addNPosition(head, data, position);
			break;
		case 5:
			printList(head);
			break;
		case 6:
			cout << "Введите элемент для удаления: ";
			cin >> data;
			head = deleteElement(head, data);
			break;
		case 7:
			exit(0);
		default:
			cout << "Ошибка выбора";
		}
	}
}

struct node* deleteElement(struct node* head, int data)
{
	struct node* p, * temp;
	if (head == NULL)
	{
		cout << "Список пуст\n";
		return head;
	}
	p = head;
	while (p->next != NULL)
	{
		if (p->next->data == data)
		{
			temp = p->next;
			p->next = temp->next;
			free(temp);
			return head;
		}
		p = p->next;
	}
	cout << "Элемент" << data << "не найден\n";
	return head;
}

struct node* init(struct node* head, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}
struct node* addNachalo(struct node* head, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}
struct node* addConec(struct node* head, int data)
{
	struct node* p, * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp->next = NULL;
	return head;
}
struct node* addNPosition(struct node* head, int data, int position)
{
	struct node* p, * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if (position == 1)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	p = head;
	for (int i = 1; i < position && p != NULL; i++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "Элементов меньше чем: " << position << "\n";
	}
	else
	{
		temp->next = p->next;
		p->next = temp;
	}
	return head;
}
void printList(struct node* head)
{
	struct node* p;
	if (head == NULL)
	{
		cout << "Список пуст";
	}
	else
	{
		p = head;
		cout << "Список: \n";
		while (p != NULL)
		{
			cout << p->data;
			p = p->next;
		}
		cout << "\n";
	}
}
