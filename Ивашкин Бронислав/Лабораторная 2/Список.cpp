#include <iostream>
#include <limits>
class List
{
private:
	struct ListItem {int value; ListItem *next; };
	ListItem *first;
public:
	List();
	~List();
	void insertToEnd(int value, bool is_change_first = false);
	void insertToIndex(int value, int index);
	int getValue(int index);
	bool deleteValue(int value);
	void printItems();
};

int main()
{
	List *list = new List();
	for (int i = 0; i < 10; i++) {list->insertToEnd(i);}
	list->printItems();
	std::cout << "Delete 0, 2, 4 items\n";
	list->deleteValue(0);
	list->deleteValue(2);
	list->deleteValue(4);
	list->printItems();
	std::cout << "Insert 11 in 0 index\n";
	list->insertToIndex(11, 0);
	list->printItems();
	std::cout << "Insert 111 in 0 index\n";
	list->insertToIndex(111, 0);
	list->printItems();
	std::cout << "Insert 12 in 2 index\n";
	list->insertToIndex(12, 2);
	list->printItems();
	std::cout << "Insert 13 in 4 index\n";
	list->insertToIndex(13, 4);
	list->printItems();
	std::cout << "Show items from 7 and 1 indexes\n";
	std::cout << list->getValue(7) << " " << list->getValue(1) << std::endl;
	delete list;
	return 0;
}
List::List(){first = nullptr;}

List::~List()
{
	ListItem *iter_stop = first;
	first = first->next;
	while (first != iter_stop) {
		ListItem *buf = first;
		first = first->next;
		delete buf;
	}
	delete iter_stop;
	first = nullptr;
}

void List::insertToEnd(int value, bool is_change_first)
{
	ListItem *buf;
	if (!first) {
		first = new ListItem;
		first->next = first;
		first->value = value;
	} else {
		buf = first;
		while (buf->next != first) {buf = buf->next;}
		buf->next = new ListItem;
		buf->next->next = first;
		buf->next->value = value;
	}
	if (is_change_first) {first = buf->next;}
}

void List::insertToIndex(int value, int index)
{
	if (!first) {
		first = new ListItem;
		first->next = first;
		first->value = value;
	} else if (index == 0) {insertToEnd(value, true);
	} else {
		ListItem *buf = first;
		int i = 1;
		while (buf->next != first && i < index) {buf = buf->next;i++;}
		ListItem *new_item = new ListItem;
		new_item->value = value;
		new_item->next = buf->next;
		buf->next = new_item;
	}
}

int List::getValue(int index)
{
	if (!first) {return std::numeric_limits<int>::max();}
	ListItem *buf = first;
	int i = 0;
	while (buf->next != first && i < index) {buf = buf->next;i++;}
	if (i == index) {return buf->value;	
	} else {return std::numeric_limits<int>::max();}
}

bool List::deleteValue(int value)
{
	if (!first) {return false;}
	ListItem *buf;
	ListItem *del_item;
	if (first->value == value) {
		if (first == first->next) {
			delete first;
			first = nullptr;
			return true;
		}
		buf = first->next;
		while (buf->next != first) {buf = buf->next;}
		del_item = first;
		first = first->next;
		buf->next = first;
		delete del_item;
		return true;
	}
	buf = first;
	while (buf->next != first && buf->next->value != value) {buf = buf->next;}
	if (buf->next != first) {
		del_item = buf->next;
		buf->next = buf->next->next;
		delete del_item;
		return true;
	}
	return false;
}

void List::printItems()
{
	if (!first) {return;}
	ListItem *buf = first;
	do {
		std::cout << buf->value << " ";
		buf = buf->next;
	} while (buf != first);
	std::cout << std::endl;
}

