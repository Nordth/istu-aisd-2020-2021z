//двунаправленный список
//2 вариант
#include <iostream>
#include <limits>

class DoubleList
{
static const int INFINITY = std::numeric_limits<int>::max();

private:
	struct ListNode {
		int value;
		ListNode *next;
		ListNode *prev;
	};
	ListNode *first;
public:
	DoubleList();
	//Освобождение памяти
	~DoubleList();
	//Вставка элемента в конец
	void InsertInEnd(int value);
	//Вставка элемента перед заданным индексом
	void Insert(int value, int index);
	//Получение значения элемента по индексу
	int Get(int index);
	//Удаление жлемента по значению
	bool Delete(int value);
	//Печать всех элементов
	void Print();
};

int main()
{
	DoubleList *list = new DoubleList();

	std::cout << "Insert even numbers with InsertInEnd method\n";
	for (int i = 0; i < 20; i += 2) {
		list->InsertInEnd(i);
	}
	list->Print();

	std::cout << "Insert odd odd with Insert method\n";
	for (int i = 1; i < 20; i += 2) {
		list->Insert(i, i);
	}
	list->Print();

	std::cout << "Print every fifth number with Get method\n";
	for (int i = 0; i < 20; i += 5) {
		std::cout << list->Get(i) << " ";
	}
	std::cout << std::endl;

	std::cout << "Delete every fifth number with Delete method \n";
	for (int i = 0; i < 20; i += 5) {
		list->Delete(i);
	}
	list->Print();

	delete list;
}

DoubleList::DoubleList()
{
	first = nullptr;
}

DoubleList::~DoubleList()
{
	while (first) {
		ListNode *buf = first;
		first = first->next;
		delete buf;
	}
}

void DoubleList::InsertInEnd(int value)
{
	if (!first) {
		first = new ListNode;
		first->value = value;
		first->next = nullptr;
		first->prev = nullptr;
		return;
	}
  	ListNode *buf = first;
  	while (buf->next) {
  		buf = buf->next;
  	}
  	buf->next = new ListNode;
  	buf->next->value = value;
  	buf->next->next = nullptr;
  	buf->next->prev = buf;
}

void DoubleList::Insert(int value, int index)
{
	if (!first) {
		first = new ListNode;
		first->value = value;
		first->next = nullptr;
		first->prev = nullptr;
		return;
	}
	ListNode *buf = first;
	for (int i = 0; i < index && buf->next; i++, buf = buf->next) {}
	ListNode *insert_item = new ListNode;
	insert_item->value = value;
	insert_item->next = buf;
	insert_item->prev = buf->prev;
	if (buf == first) {
		first = insert_item;
	} else {
		buf->prev->next = insert_item;
	}
	buf->prev = insert_item;
}

int DoubleList::Get(int index)
{
	ListNode *buf = first;
	for (int i = 0; i < index && buf; i++, buf = buf->next) {}
	if (buf) {
		return buf->value;
	} else {
		return INFINITY;
	}
}

bool DoubleList::Delete(int value)
{
	if (!first) {
		return false;
	}
	ListNode **buf = &first;
	while (*buf && (*buf)->value != value) {
		 buf = &(*buf)->next;
	}
	if (*buf) {
		ListNode *delete_item = *buf;
		if ((*buf)->next) {
			(*buf)->next->prev = (*buf)->prev;
		}
		if ((*buf)->prev) {
			(*buf)->prev->next = (*buf)->next;
		} else {
			first = (*buf)->next;
		}
		delete delete_item;
		return true;
	} else {
		return false;
	}
}

void DoubleList::Print()
{
	for (ListNode *buf = first; buf; buf = buf->next) {
		std::cout << buf->value << " ";
	}
	std::cout << std::endl;
}