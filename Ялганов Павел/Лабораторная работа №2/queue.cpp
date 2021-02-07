//Вариант 6
//Очередь
#include <iostream>
#include <fstream>

class MyQueue {

//начальный размер массива
static const int start_size = 10;
//коэффициент увеличения при переполнении
static const int resize_coefficient = 2;

public:
	//Инициализация
	MyQueue();
	//Освобождение памяти 
	~MyQueue();
	//Вставка элемента
	void enqueue(int item);
	//Извлечение элемента
	bool dequeue(int & return_value);
	//Клонирование
	MyQueue* create_copy();
	void print();
	void resize();

	int* array;
	int first, last, current_size;
	//если true массив пуст
	bool is_empty;
};

const int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, };

int main(int argc, char** argv)
{
	MyQueue* q1 = new MyQueue();
	int arr_size = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < arr_size; i++) {
		q1->enqueue(array[i]);
	}
	int buf;
	MyQueue* q2 = q1->create_copy();
	while (q1->dequeue(buf)) {
		std::cout << buf << " ";
	}
	std::cout << std::endl;
	q2->print();
	delete q1;
	delete q2;
}

MyQueue::MyQueue() 
{
	array = new int[start_size];
	first = last = 0;
	current_size = start_size;
	is_empty = true;
}

MyQueue::~MyQueue() 
{
	delete [] array;
}

void MyQueue::enqueue(int item)
{
	if (is_empty) {
		array[first] = item;
		is_empty = false;
		return;
	}
	last++;
	if (last >= current_size) {
		last = 0;
	}
	if (last == first) {
		resize();
	}
	array[last] = item;
	is_empty = false;
}

bool MyQueue::dequeue(int & return_value)
{
	if (is_empty) {
		return false;
	}
	return_value = array[first];
	if (first == last) {
		first = last = 0;
		is_empty = true;
	} else {
		first++;
		if (first >= current_size) {
			first = 0;
		}
	}
	return true;
}

MyQueue* MyQueue::create_copy() 
{
	MyQueue* buf = new MyQueue();
	buf->current_size = current_size;
	buf->first = first;
	buf->last = last;
	buf->array = new int[current_size];
	int new_array_index = 0;
	int first_end = last < first ? current_size : last + 1;
	for (int i = first; i < first_end; ++i) {
		buf->array[new_array_index++] = array[i];
	}
	if (last < first) {
		for (int i = 0; i <= last; ++i) {
			buf->array[new_array_index++] = array[i];
		}
	}
	buf->first = 0;
	buf->last = new_array_index - 1;
	return buf;
}

void MyQueue::resize()
{
	int* new_array = new int[current_size * resize_coefficient];
	int new_index = 0;
	for (int i = first; i < current_size; ++i) {
		new_array[new_index++] = array[i];
	}
	if (first != 0) {
		for (int i = 0; i < last; ++i) {
			new_array[new_index++] = array[i];
		}
	}
	delete [] array;
	array = new_array;
	current_size *= resize_coefficient;
	first = 0;
	last = new_index;
}

void MyQueue::print()
{
	int first_end = last < first ? current_size : last + 1;
	for (int i = first; i < first_end; ++i) {
		std::cout << array[i] << " ";
	}
	if (last < first) {
		for (int i = 0; i <= last; ++i) {
			std::cout << array[i] << " ";
		}
	}
	std::cout << std::endl;
}