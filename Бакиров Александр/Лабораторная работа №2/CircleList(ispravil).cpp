#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class CircleList
{
public:
	CircleList();
	/*
	* Конструктор для очистки памяти
	*/
	~CircleList();
	void AddToEnd(int data); // вставка элемента в конец списка
	void Print(); // печать всех элементов
	void AddOnIndex(int index, int data); // Добавление элемента в список по индексу
	bool DeleteValue(int data); // удаление элемента по его значению

	// получение значения элемента по индексу
	int SearchNum(int index);

	// структура узла списка
	struct Node
	{
		int data; // поле данных
		struct Node* next;// указатель на следующий элемент
	};
	// Указатели на первый и последующий элементы списка
	Node* Head;
	int count;
};

CircleList::CircleList() //изначальное значение элементов списка - NULL
{
	Head = nullptr;
	count = 0; // не знаю как сделат без счета элементов удаление по индексу. Подсчет переходов по указателям реализовать не смог...
}

CircleList::~CircleList()
{
	Node* second = Head->next;
	while (Head != second) {
		Node* temp2 = second;
		second = second->next;
		delete temp2;
	}
	delete Head;
	cout << "Память очищена" << endl;
}

void CircleList::AddToEnd(int data)
{
	// Выделение памяти для нового элемента
	Node* temp = new Node;
	temp->data = data;

	// Если присутствует первый элемент
	if (Head != nullptr)
	{
		Node** temp2 = &Head->next;
		while (*temp2 != Head)
		{
			temp2 = &(*temp2)->next;
		}
		*temp2 = temp;
		temp->next = Head;
	}
	// Если первого элемента нет, то нужно его создать
	else
	{
		Head = temp;
		Head->next = Head;
	}
	count++;
	cout << "\nЧисло " << data << " добавлено.";
}

void CircleList::AddOnIndex(const int index, const int data)
{
	// Если список пуст или индекс больше общего кол-ва элементов списка, то добавить новое значение в список
	if (Head == nullptr || index > count)
	{
		AddToEnd(data);
		return;
	}
	bool is_in_the_first_place = (index == 0) ? true : false;
	int iter_count = (index == 0) ? count : index;
	// создание ссылки на переменную temp  с типом Node*(для того,чтобы temp существовала не только в теле метода AddOnIndex)
	// как будто это глобальная переменная, т.е указатель на конкретную область памяти, а не команда для выделения нового участка
	// информация https://coderoad.ru/12124096
	Node** temp2 = &Head;

	for (int x = 1; x < iter_count; ++x)
	{
		temp2 = &((*temp2)->next);
	}
	// создание новой области памяти
	Node* t = new Node;
	// передача в нее значения для вставки
	t->data = data;
	// создание указателя на ссылку в области памяти
	t->next = *temp2;
	// вставка элемента
	*temp2 = t;
	if (is_in_the_first_place) {
		Head = t;
	}
	count++;
	cout << "\nЧисло " << data << " добавлено по индесу " << index;
}

int CircleList::SearchNum(int index)
{
	Node* temp;
	temp = Head;
	if (Head == NULL)
	{
		cout << "Список пуст" << endl;
		return -1;
	}
	else
	{
		for (int i = -2; i < index; ++i)
		{
			temp = temp->next;
			if (temp == Head)
			{
				break;
			}
		}
		cout << "\nЭлемент " << temp->data << " располагается по индексу " << index;
	}
	return temp->data;

}



bool CircleList::DeleteValue(int data)
{
	if (!Head) {
		return false;
	}

	Node** temp2 = &Head->next;
	if (Head->data == data) // Если удаляем первый элемент
	{
		for (; *temp2 != Head; temp2 = &(*temp2)->next) {}
		*temp2 = Head->next;
		delete Head;
		count--;
		if (count == 0)
		{
			Head = nullptr;
			cout << "Список пуст, удалять нечего...";
		}
		// иначе передвигаем указатель в поиске нужного значения
		else
		{
			Head = *temp2;
		}
		return true;
	}
	for (; *temp2 != Head; temp2 = &(*temp2)->next)
	{
		if ((*temp2)->data == data)
		{
			Node* DelNumber = *temp2;
			*temp2 = (*temp2)->next;
			delete DelNumber;
			count--;
			cout << "\nЭлемент " << data << " удален из списка.";
		}
	}
	return false;
	
}

void CircleList::Print()
{
	cout << endl << endl;
	if (Head == nullptr)
	{
		cout << "Список пуст";
		return;
	}
	else
	{
		cout << Head->data << " ";
		Node* temp2 = Head->next;
		for (; temp2 != Head; temp2 = temp2->next)
		{
			cout << temp2->data << " ";
		}
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
	circlelist->SearchNum(3);
	circlelist->SearchNum(6);
	

}