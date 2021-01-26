//Вариант 6
//Однонаправленный циклический список
#include <iostream>
#include <fstream>

class CircularList {

public:
	CircularList();
	//Освобождение памяти от структуры данных
	~CircularList();
	//Вставка элемента в конец
	void insert_to_end(const int value);
	//Вставка элемента перед заданным индексом
	void insert_by_index(const int index, const int value);
	//Получение значения элемента по индексу
	const int get_by_index(const int index);
	const int operator[](const int index);
	//Удаление элемента по значению
	bool delete_by_value(const int value);
	//Печать всех элементов списка
	void print_all_items();
	int get_length();
private:
	struct ListNode {
		int value;
		ListNode* next;
	};
	ListNode* first;
	ListNode* last;
	int count;
};

const char* default_file_name = {"task_a_test.txt"};

int main(int argc, char** argv) 
{
	std::ifstream input_file;
	if (argc > 1) {
		input_file.open(argv[1]);
	} else {
		input_file.open(default_file_name);
	}
	CircularList* list = new CircularList();
	
	for (int i = 0; i < 8; ++i) {
		int new_value;
		input_file >> new_value;
		list->insert_to_end(new_value);
	}
	list->print_all_items();
	
	list->delete_by_value(1);
	list->delete_by_value(3);
	list->delete_by_value(8);
	list->print_all_items();

	list->insert_by_index(1, 0);
	list->insert_by_index(3, 2);
	list->insert_by_index(5, 4);
	list->insert_by_index(7, 6);
	list->insert_to_end(9);
	
	int len = list->get_length();
	for (int i = 0; i < len; ++i) {
		std::cout << (*list)[i] << " ";
	}
	std::cout << std::endl;

	delete list;
	input_file.close();
}

CircularList::CircularList()
{
	first = last = nullptr;
	count = 0;
}

//Освобождение памяти от структуры данных
CircularList::~CircularList()
{
	last->next = nullptr;
	while (first) {
		last = first;
		first = first->next;
		delete last;
	}
	last = nullptr;
}

//Вставка элемента в конец
void CircularList::insert_to_end(const int value)
{
	ListNode* buf = new ListNode;
	buf->value = value;
	if (first) {
		buf->next = first;
		last->next = buf;
		last = buf;
	} else {
		last = first = buf;
		buf->next = first;
	}
	count++;
}

//Вставка элемента перед заданным индексом
void CircularList::insert_by_index(const int index, 
	const int value)
{
	if (!first or index > count) {
		insert_to_end(value);
		return;
	}
	ListNode** buf = &first;
	for (int i = 1; i < index; ++i) {
		buf = &((*buf)->next);
	}
	ListNode* new_item = new ListNode;
	new_item->value = value;
	new_item->next = *buf;
	*buf = new_item;
	count++;
}

//Получение значения элемента по индексу
const int CircularList::get_by_index(const int index) 
{
	if (index >= count) {
		return last->value;
	}
	ListNode* buf = first;
	for (int i = 0; i < index; ++i) {
		buf = buf->next;
	}
	return buf->value;
}

//Получение значения элемента по индексу
const int CircularList::operator[](const int index)
{
	return get_by_index(index);
}

//Удаление элемента по значению
bool CircularList::delete_by_value(const int value) 
{
	if (!first) {
		return false;
	}
	if (first->value == value) {
		ListNode* delete_item = first;
		first = first->next;
		last->next = first;
		delete delete_item;
		count--;
		return true;
	}
	ListNode** buf = &first->next;
	while (*buf != first) {
		if ((*buf)->value == value) {
			ListNode* delete_item = *buf;
			*buf = (*buf)->next;
			delete delete_item;
			count--;
			return true;
		}
		buf = &(*buf)->next;
	} 
	return false;
}

////Печать всех элементов списка
void CircularList::print_all_items()
{
	if(!first) {
		return;
	}
	std::cout << first->value << " ";
	ListNode* buf = first->next;
	for ( ; buf != first; buf = buf->next) {
		std::cout << buf->value << " ";
	}
	std::cout << std::endl;
}

int CircularList::get_length() 
{
	return count;
}