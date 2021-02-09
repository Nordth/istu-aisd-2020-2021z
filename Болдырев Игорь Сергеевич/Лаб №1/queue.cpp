//6 вариант
//очередь

#include <iostream>

class Queue
{

static const int start_size = 3;

private:
	int *buffer;
	int first, last;
	int size;
public:
	//Инициализация
	Queue();
	//Освобождение от памяти
	~Queue();
	Queue(Queue *copy);
	//Вставка элемента
	void add(int number);
	//Извлечение элемента
	bool get(int &number);
	//Клонирование
	Queue* copy();
private:
	void resize();
};

int main()
{
	Queue *q1 = new Queue();

	for (int i = 0; i < 10; i++) {
		q1->add(i);
	}

	Queue *q2 = q1->copy();

	std::cout << "Print numbers of original queue\n";
	int tmp;
	while (q1->get(tmp)) {
		std::cout << tmp << " ";
	}
	std::cout << std::endl;

	std::cout << "Print numbers of copy queue\n";
	while (q2->get(tmp)) {
		std::cout << tmp << " ";
	}
	std::cout << std::endl;
}

Queue::Queue()
{
	buffer = new int[start_size];
	size = start_size;
	first = last = -1;
}

Queue::~Queue()
{
	delete[] buffer;
}

Queue::Queue(Queue *copy)
{
	size = copy->size;
	buffer = new int[size];
	int i = 0;
	for (int j = copy->first + 1; j <= copy->last; i++,j++) {
		buffer[i] = copy->buffer[j];
	}
	first = -1;
	last = i - 1;
}

void Queue::add(int number)
{
	last++;
	if (last >= size) {
		resize();
	}
	buffer[last] = number;
}

bool Queue::get(int &number)
{
	first++;
	if (first > last) {
		first = last = -1;
		return false;
	}
	number = buffer[first];
	return true;
}
	
Queue* Queue::copy()
{
	return new Queue(this);
}

void Queue::resize()
{
	int *new_buffer = new int[size * 2];
	int i = 0;
	for (int j = first + 1; j < last; i++,j++) {
		new_buffer[i] = buffer[j];
	}
	first = -1;
	size *= 2;
	delete[] buffer;
	buffer = new_buffer;
}