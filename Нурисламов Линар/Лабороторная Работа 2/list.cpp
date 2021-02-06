//1 вариант
//однонаправленный список

#include <iostream>
#include <limits>

class List 
{

static const int INF = std::numeric_limits<int>::min();

private:
	struct Node
	{
		int val;
		Node *next;
	};
	Node *first;
public:
	List();
	//Освобождение памяти
	~List();
	//Вставка элемента в конец списка
	void insertToEnd(int x);
	//Вставка элемента перед заданным индексом
	void insertToIndex(int x, int index);
	//Получение значения по индексу
	int getByIndex(int index);
	//Удаление значение по знаению
	bool deleteByValue(int x);
	//Печать всех элементов
	void showValues();
};

int main()
{
	List *list = new List();

	for (int i = 0; i < 10; i++) {
		list->insertToEnd(i);
	}
	std::cout << "Add items in list with insertToEnd method\n";
	list->showValues();


	std::cout << "Add items in list with insertToIndex method\n";
	std::cout << "11 in 0 index\n";
	list->insertToIndex(11, 0);
	list->showValues();
	std::cout << "13 in 5 index\n";
	list->insertToIndex(13, 5);
	list->showValues();

	std::cout << "Delete 0, 1, 11 values\n";
	list->deleteByValue(0);
	list->deleteByValue(1);
	list->deleteByValue(11);
	list->showValues();

	std::cout << "Show values from 0, 2 indexes with getByIndex\n";
	std::cout << list->getByIndex(0) << " " << list->getByIndex(2);
	std::cout << std::endl; 
}

List::List()
{
	first = NULL;
}

List::~List()
{
	while (first) {
		Node *del = first;
		first = first->next;
		delete del;
	}
}

void List::insertToEnd(int x)
{
	Node **node = &first;
	while (*node) {
		node = &(*node)->next;
	}
	*node = new Node;
	(*node)->next = NULL;
	(*node)->val = x;
}

void List::insertToIndex(int x, int index)
{
	Node **node = &first;
	for (int i = 0; i < index && *node; i++) {
		node = &(*node)->next;
	}
	Node *neww = new Node;
	neww->val = x;
	neww->next = *node;
	*node = neww;
}
	
int List::getByIndex(int index)
{
	Node *node = first;
	for (int i = 0; node && i < index; i++,node = node->next) {}
	if (node) {
		return node->val;
	} 
	return INF;
}
	
bool List::deleteByValue(int x)
{
	Node **node = &first;
	while (*node && (*node)->val != x) {
		node = &(*node)->next;
	}
	if (*node == NULL) {
		return false;
	}
	Node *del = *node;
	*node = (*node)->next;
	delete del;
	return true;
}

void List::showValues()
{
	for (Node *node = first; node; node = node->next) {
		std::cout << node->val << " ";
	}
	std::cout << std::endl;
}