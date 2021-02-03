
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class CircleList
{
public:
	CircleList();
	/*
	* Конструктор для очисти памяти
	*/
	~CircleList();

	void AddToEnd(int data); // вставка элемента в конец списка
	void Print(); // печать всех элементов
	void AddOnIndex(int index, int data); // Добавление элемента в список по индексу
	void DeleteValue(int data); // удаление элемента по его значению

	// получение значения элемента по индексу
	 void SearchNum(int index);

	// структура узла списка
	struct Node
	{
		int data; // поле данных
		struct Node* next;// указатель на следующий элемент
	};
	// Указатели на первый и последующий элементы списка
	Node* Head;
	Node* Tail;
	//переменная для фиксации кол-ва элементов
	int count;

};

CircleList::CircleList() //изначальное значение элементов списка - NULL
{
	Head = Tail = NULL;
	count = 0;
}


void CircleList::AddToEnd(int data)
{
	// Выделение памяти для нового элемента
	Node* temp = new Node;
	temp->data = data;

	// Если присутствует первый элемент
	if (Head != NULL)
	{
		temp->next = Head;
		Tail->next = temp;
		Tail = temp;
	}
	// Если первого элемента нет, то нужно его создать
	else
	{
		Tail = Head = temp;
		temp->next = Head;
	}
	count++;
	cout << "\nЧисло " << data << " добавлено.";
}


void CircleList::DeleteValue(int data)
{
	if (Head->data == data) // Если удаляем первый элемент
	{
		Node* temp = Head;
		Head = Head->next;
		Tail->next = Head;
		delete temp;
		count--;
	}
	else
	{
		Node** temp2 = &Head->next; // создаем ссылку на выделяемую область памяти для указателя элемента идущего за первым
		while (*temp2 != Head) // пробегаем по списку в поисках удаляемого значения
		{
			if ((*temp2)->data == data)
			{
				// переприсваиваем указатели перед удалением
				Node* temp = *temp2;
				*temp2 = (*temp2)->next;
				delete temp;
				count--;
			}
			temp2 = &(*temp2)->next;
		}
	}
	cout << "\nЭлемент " << data << " удален из списка.";
}


void CircleList::AddOnIndex(const int index, const int data)
{
	// Если список пуст или индекс больше общего кол-ва элементов списка, то добавить новое значение в список
	if (Head == NULL || index > count)
	{
		AddToEnd(data);
		return;
	}
	// создание ссылки на переменную temp  с типом Node*(для того,чтобы temp существовала не только в теле метода AddOnIndex)
	// как будто это глобальная переменная, т.е указатель на конкретную область памяти, а не команда для выделения нового участка
	// информация https://coderoad.ru/12124096
	Node** temp = &Head;

	for (int x = 1; x < index; ++x)
	{
		temp = &((*temp)->next);
	}
	// создание новой области памяти
	Node* t = new Node;
	// передача в нее значения для вставки
	t->data = data;
	// создание указателя на ссылку в области памяти
	t->next = *temp;
	// вставка элемента
	*temp = t;
	count++;
	cout << "\nЧисло " << data << " добавлено по индесу " << index;
}


void CircleList::SearchNum(int index)
{
	Node* temp;
	temp = Head;
	if (Head == NULL)
	{
		cout << "Лист пуст" << endl;
		return;
	}
	else if (index>count)
	{
		cout << "\nПо индексу " << index << " элементов не существует";
	}
	else
	{
		for (int i = 0; i != index; i++)
		{
			temp = temp->next;
		}
		cout << "\nЭлемент " << temp->data << " располагается по индексу " << index;
	}
	
}


CircleList::~CircleList()
{
	Tail->next = nullptr;
	while (Head != NULL) {
		Tail = Head;
		Head = Head->next;
		delete Tail;
	}
	Tail = nullptr;
	cout << "Память очищена" << endl;
}

void CircleList::Print()
{
	cout << endl << endl;
	if (Head == NULL)
	{
		cout << "Список пуст";
		return;
	}
	else
	{
		cout << Head->data << " ";
		Node* temp = Head->next;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;

		} while (temp != Head);	
	}
	cout << endl;
}

int main()
{
	

	CircleList* circlelist = new CircleList();
	setlocale(LC_ALL, "Russian");
	circlelist->AddToEnd(4);
	circlelist->AddToEnd(5);
	circlelist->AddToEnd(5);
	circlelist->Print();
	circlelist->~CircleList();
	circlelist->AddToEnd(7);
	circlelist->AddToEnd(8);
	circlelist->AddToEnd(9);
	circlelist->AddToEnd(10);
	circlelist->AddToEnd(5);
	circlelist->AddToEnd(3);
	circlelist->AddToEnd(1);
	circlelist->Print();
	circlelist->DeleteValue(9);
	circlelist->Print();
	circlelist->DeleteValue(7);
	circlelist->Print();
	circlelist->AddOnIndex(1, 12);
	circlelist->AddOnIndex(2, 13);
	circlelist->DeleteValue(12);
	circlelist->Print();
	circlelist->SearchNum(10);
	circlelist->SearchNum(2);
	
}


