//5 вариант
//двунаправленный список
#include <iostream>

class DoubleLinkedList
{
private:
	struct Item {
		Item* next;
		Item* prev;
		int value;
	};
	Item* first;
public:
	DoubleLinkedList();
	//осовобождение памяти
	~DoubleLinkedList();
	//вставка в конец
	void InsertItemAtEnd(int value);
	//вставка перед заданнным индексом
	void InsertItemAtIndex(int index, int value);
	//получение элемента по индексу
	int GetItem(int index);
	//удаление элемента по значению
	bool DeleteItemByValue(int value);
	//печать всех элементов
	void PrintItems();
};

int array[] = { 1, 2, 3, 4, 5, 6, 5, 8, 9, 0 };

int main()
{
	DoubleLinkedList* list = new DoubleLinkedList();
	int size = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		list->InsertItemAtEnd(array[i]);
	}
	list->PrintItems();
	list->InsertItemAtIndex(1, 11);
	list->InsertItemAtIndex(0, 13);
	list->InsertItemAtIndex(33, 77);
	list->PrintItems();
	
	list->DeleteItemByValue(5);
	list->DeleteItemByValue(0);
	list->DeleteItemByValue(13);
	list->PrintItems();

	std::cout << list->GetItem(1) << std::endl;
	std::cout << list->GetItem(3) << std::endl;
	
	delete list;
}

DoubleLinkedList::DoubleLinkedList()
{
	first = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
	Item* buf;
	while (first != nullptr) {
		buf = first;
		first = first->next;
		delete buf;
	}
}

void DoubleLinkedList::InsertItemAtEnd(int value)
{
	if (first == nullptr) {
		first = new Item;
		first->value = value;
		first->next = nullptr;
		first->prev = nullptr;
	} else {
		Item *buf = first;
		while (buf->next != nullptr) {
			buf = buf->next;
		}
		Item *new_item = new Item;
		new_item->value = value;
		new_item->next = nullptr;
		new_item->prev = buf;
		buf->next = new_item;
	}
}

void DoubleLinkedList::InsertItemAtIndex(int index, int value)
{
	if (first == nullptr) {
		first = new Item;
		first->value = value;
		first->next = nullptr;
		first->prev = nullptr;
		return;
	}
	Item* buf = first;
	for (int i = 0; i < index && buf->next != nullptr; i++) {
		buf = buf->next;
	}
	Item* new_item = new Item;
	new_item->value = value;
	new_item->next = buf;
	new_item->prev = buf->prev;
	if (buf != first) {
		buf->prev->next = new_item;
	} else {
		first = new_item;
	}
	buf->prev = new_item;
}

int DoubleLinkedList::GetItem(int index)
{
	Item* buf = first;
	for (int i = 0; i < index && buf->next != nullptr; i++) {
		buf = buf->next;
	}
	return buf->value;
}

bool DoubleLinkedList::DeleteItemByValue(int value)
{
	Item* buf = first;
	while (buf != nullptr) {
		if (buf->value == value) {
			if (buf == first) {
				first = buf->next;
				buf->next->prev = nullptr;
			} else if (buf->next == nullptr) { 
				buf->prev->next = nullptr;
			} else {
				buf->next->prev = buf->prev;
				buf->prev->next = buf->next;
			}
			Item* buf2 = buf;
			buf = buf->next;
			delete buf2;
			return true;
		} else {
			buf = buf->next;
		}
	}
	return false;
}

void DoubleLinkedList::PrintItems()
{
	Item* buf = first;
	while (buf != nullptr) {
		std::cout << buf->value << " ";
		buf = buf->next;
	}
	std::cout << std::endl;
}