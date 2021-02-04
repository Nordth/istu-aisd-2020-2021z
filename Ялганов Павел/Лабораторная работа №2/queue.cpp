//Вариант 5
//Очередь
#include <iostream>

class MyQueue {

//начальный размер массива
static const int init_len = 5;
private:
	int *buffer;
	int first;
	int last;
	int length;
	void resize();
public:
	//Инициализация
	MyQueue();
	//Освобождение памяти 
	~MyQueue();
	//Вставка элемента
	void addItem(int item);
	//Извлечение элемента
	bool getItem(int & return_value);
	//Клонирование
	MyQueue* copy();
	
	void printItems();
};

const int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int main(int argc, char** argv)
{
	MyQueue* q1 = new MyQueue();
	int arr_size = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < arr_size; i++) {
		q1->addItem(array[i]);
	}
	q1->printItems();
	
	int buf;
	MyQueue* q2 = q1->copy();
	q2->printItems();

	for (int i = 0; i < 5; i++) {
		q2->getItem(buf);
	}
	q2->printItems();

	for (int i = 20; i < 30; i++) {
		q2->addItem(i);
	}
	q2->printItems();

	while (q1->getItem(buf)) {
		std::cout << buf << " - ";
	}
	std::cout << std::endl;
	
	delete q1;
	delete q2;
}

MyQueue::MyQueue() 
{
	buffer = new int[init_len];
	first = last = -1;
	length = init_len;
}

MyQueue::~MyQueue() 
{
	delete [] buffer;
}

void MyQueue::addItem(int item)
{
	if (last == -1) {
		buffer[++last] = item;
	} else {
		last++;
		if (last >= length) {
			last = 0;
		}
		if (last == first + 1) {
			resize();
			last++;
		}
		buffer[last] = item;
	}
}

bool MyQueue::getItem(int & item)
{
	if (last == -1) {
		return false;
	}
	item = buffer[first + 1];
	if (first + 1 == last) {
		first = last = -1;
	} else {
		first++;
		if (first >= length - 1) {
			first = -1;
		}
	}
	return true;
}

MyQueue* MyQueue::copy() 
{
	MyQueue* buf = new MyQueue();
	buf->length = length;
	buf->first = first;
	buf->last = last;
	buf->buffer = new int[length];
	if (last == -1) {
		return buf;
	}
	int buffer_end;
	if (first + 1 > last) {
		buffer_end = length;
	} else {
		buffer_end = last + 1;
	}
	int buf_index = 0;
	for (int i = first + 1; i < buffer_end; i++) {
		buf->buffer[buf_index++] = buffer[i];
	}
	if (last <= first) {
		for (int i = 0; i <= last; ++i) {
			buf->buffer[buf_index++] = buffer[i];
		}
	}
	buf->first = -1;
	buf->last = buf_index - 1;
	return buf;
}

void MyQueue::resize()
{
	int* new_buffer = new int[length * 2];
	int new_buf_index = 0;
	for (int i = first + 1; i < length; i++,new_buf_index++) {
		new_buffer[new_buf_index] = buffer[i];
	}
	if (first != -1) {
		for (int i = 0; i <= last; ++i) {
			new_buffer[new_buf_index++] = buffer[i];
		}
	}
	delete [] buffer;
	buffer = new_buffer;
	length *= 2;
	first = -1;
	last = new_buf_index - 1;
}

void MyQueue::printItems()
{
	int buffer_end = last < first + 1 ? length : last + 1;
	for (int i = first + 1; i < buffer_end; ++i) {
		std::cout << buffer[i] << " ";
	}
	if (last < first + 1) {
		for (int i = 0; i <= last; ++i) {
			std::cout << buffer[i] << " ";
		}
	}
	std::cout << std::endl;
}