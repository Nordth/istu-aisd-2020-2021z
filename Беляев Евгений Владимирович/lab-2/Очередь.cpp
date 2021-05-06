#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "time.h"
#include <conio.h> 
#include <Windows.h>
#include <malloc.h>
using namespace std;

typedef struct queue
{
	int t;
	int maxSize;
	int* st;
	int i;
}queue;

void initqueue(queue* s, int length);
void push(queue* s, int elem);
int pop(queue* s);
void print(queue* s);
void clone(queue* s);
int size_s(queue* s);
int isEmpty(queue* s);


void main() {
	setlocale(LC_CTYPE, "rus");
	queue* s = malloc(sizeof(queue));
	int vib, length, elem;
	while (1)
	{
		cout << "1 - Создание очереди\n";
		cout << "2 - Push\n";
		cout << "3 - Pop\n";
		cout << "4 - Вывод очереди\n";
		cout << "5 - Клонирование\n";
		cout << "6 - Выход\n";
		cout << "Выберете\n";
		cin >> vib;
		switch (vib)
		{
		case 1:
			cout << "Введите размер очереди: ";
			cin >> length;
			initqueue(s, length);
			break;
		case 2:
			cout << "Введите элемент: ";
			cin >> elem;
			push(s, elem);
			break;
		case 3:
			pop(s);
			break;
		case 4:
			print(s);
			break;
		case 5:
			clone(s);
			break;
		case 6:
			exit(0);
		default:
			cout << "Неверный выбор";
		}
	}
}

void initqueue(queue* s, int length)
{
	s->st = malloc(sizeof(int) * length);
	s->maxSize = length;
	s->t = -1;
}

void push(queue* s, int elem)
{
	int* tmp, i;
	if (size_s(s) == s->maxSize)
	{
		s->maxSize = s->maxSize * 2;
		tmp = malloc(sizeof(int) * s->maxSize);
		for (int i = 0; i < size_s(s); i++);
		{
			tmp[i] = s->st[i];
		}
		free(s->st);
		s->st = tmp;
	}
	int t = s->t + 1;
	s->t = t;
	s->st[t] = elem;
}

int pop(queue* s)
{
	int element;
	if (isEmpty(s))
	{
		return -1;
	}
	element = s->st[s->t];
	s->t = s->t - 1;
	return element;
}

int size_s(queue* s)
{
	return (s->t) + 1;
}

int isEmpty(queue* s)
{
	if (s->t == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void clone(queue* s)
{
	int* new_queue;
	new_queue = malloc(sizeof(int) * s->maxSize);
	for (int i = 0; i < size_s(s); i++)
	{
		new_queue[i] = s->st[i];
	}
	cout << "Клонированная очередь: \n";
	for (int i = 0; i < size_s(s); i++)
	{
		cout << new_queue[i];
	}
	cout << "\n\n\n";


}

void print(queue* s)
{
	cout << "Длина:" << size_s(s) << "\n";
	cout << "максимальный размер\n" << s->maxSize << "\n";
	for (int i = 0; i < size_s(s); i++)
	{
		cout << s->st[i];
	}
	cout << "\n\n\n";
}
