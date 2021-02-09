//6 вариант
//однонаправленный циклический список
#include <iostream>

class CircleList
{
private:
	struct ListItem {
		int number;
		ListItem *next;
	};

	ListItem *first;
public:
	CircleList();
	//освобождение памяти
	~CircleList();
	//вставка элемента в конец
	void insertInEnd(int number);
	//вставка перед заданным индексом
	void insertInIndex(int number, int index);
	//получение знаения по индексу
	int getElement(int index);
	//удаление элемента по знаению
	bool deleteElement(int number);
	//Печать всех элементов
	void showElements();
};

int main()
{
	CircleList *list = new CircleList();

	std::cout << "Insert numbers in list with insertInEnd method\n";
	for (int i = 0; i < 10; i++) {
		list->insertInEnd(i);
	}
	list->showElements();

	std::cout << "Insert numbers in list with insertInIndex method\n";
	for (int i = 0; i < 10; i++) {
		list->insertInIndex(i * 10, i * 2);
	}
	list->showElements();

	std::cout << "Get numbers with getElement\n";
	for (int i = 0; i < 20; i++) {
		std::cout << list->getElement(i) << " ";
	}
	std::cout << std::endl;

	std::cout << "Delete numbers: 0 5 9\n";
	list->deleteElement(0);
	list->deleteElement(5);
	list->deleteElement(9);
	list->showElements();

	delete list;
}

CircleList::CircleList()
{
	first = NULL;
}

CircleList::~CircleList()
{
	if (first) {
		ListItem *stop = first;
		first = first->next;
		while (first != stop) {
			ListItem *del = first;
			first = first->next;
			delete del;
		}
		delete stop;
	}
}

void CircleList::CircleList::insertInEnd(int number)
{
	if (!first) {
		first = new ListItem;
		first->next = first;
		first->number = number;
		return;
	}
	ListItem *tmp = first;
	while (tmp->next != first) {
		tmp = tmp->next;
	}
	tmp->next = new ListItem;
	tmp->next->number = number;
	tmp->next->next = first;
}

void CircleList::insertInIndex(int number, int index)
{
	if (!first) {
		first = new ListItem;
		first->next = first;
		first->number = number;
		return;
	}
	ListItem *tmp = first;
	if (index == 0) {
		while (tmp->next != first) {
			tmp = tmp->next;
		}
		tmp->next = new ListItem;
		tmp->next->number = number;
		tmp->next->next = first;
		first = tmp->next;
		return;
	}
	while (index > 1 && tmp->next != first) {
		tmp = tmp->next;
		index--;
	}
	ListItem *insert_item = new ListItem;
	insert_item->number = number;
	insert_item->next = tmp->next;
	tmp->next = insert_item;
}

int CircleList::getElement(int index)
{
	if (!first) {
		return -1;
	}
	ListItem *tmp = first;
	int i = 0;
	while (tmp->next != first && i < index ) {
		tmp = tmp->next;
		i++;
	}
	if (i == index) {
		return tmp->number;	
	} else {
		return -1;
	}
}

bool CircleList::deleteElement(int number)
{
	if (!first) {
		return false;
	}
	ListItem** tmp = &first->next;
	if (first->number == number) {
		for ( ; *tmp != first; tmp = &(*tmp)->next) {}
		*tmp = first->next;
		ListItem *del = first;
		if (*tmp == first) {
			first = NULL;
		} else {
			first = first->next;
		}
		delete del;
		return true;
	} 
	for ( ; *tmp != first; tmp = &(*tmp)->next) {
		if ((*tmp)->number == number) {
			ListItem* del = *tmp;
			*tmp = (*tmp)->next;
			delete del;
			return true;
		}	
	}
	return false;
}

void CircleList::showElements()
{
	if (!first) {
		return;
	}
	ListItem *tmp = first;
	do {
		std::cout << tmp->number << " ";
		tmp = tmp->next;
	} while (tmp != first);
	std::cout << std::endl;
}