//Вариант 6
//Очередь
#include <iostream>
#include <fstream>

class Queue {

//начальный размер массива
static const int start_size = 10;
//коэффициент увеличения при переполнении
static const int resize_coefficient = 2;

public:
	//Инициализация
	Queue();
	//Освобождение памяти от структуры данных
	~Queue();
	//Вставка элемента
	void enqueue(int item);
	//Извлечение элемента
	bool dequeue(int & return_value);
	//Клонирование
	Queue* copy();
	void print();
private:
	int* array;
	int first, last, current_size;
	//если true массив пуст
	bool is_empty;

	Queue(const Queue * copy);
	void resize();
};

const char* default_file_name = {"task_b_test.txt"};

int main(int argc, char** argv)
{
	std::ifstream input_file;
	if (argc > 1) {
		input_file.open(argv[1]);
	} else {
		input_file.open(default_file_name);
	}
	int buf;
	Queue* queue_1 = new Queue();
	while (input_file >> buf) {
		queue_1->enqueue(buf);
	}
	Queue* queue_2 = queue_1->copy();
	while (queue_1->dequeue(buf)) {
		std::cout << buf << " ! ";
	}
	std::cout << std::endl;
	queue_2->print();
	input_file.close();
	delete queue_1;
	delete queue_2;
}

Queue::Queue() 
{
	array = new int[start_size];
	first = last = 0;
	current_size = start_size;
	is_empty = true;
}

Queue::Queue(const Queue * source)
{
	current_size = source->current_size;
	first = source->first;
	last = source->last;
	array = new int[current_size];
	int new_array_index = 0;
	int first_end = last < first ? current_size : last + 1;
	for (int i = first; i < first_end; ++i) {
		array[new_array_index++] = source->array[i];
	}
	if (last < first) {
		for (int i = 0; i <= last; ++i) {
			array[new_array_index++] = source->array[i];
		}
	}
	first = 0;
	last = new_array_index - 1;
}

Queue::~Queue() 
{
	delete [] array;
}

void Queue::enqueue(int item)
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
		//после resize в last индекс последнего элемента
		last++;
	}
	array[last] = item;
	is_empty = false;
}

bool Queue::dequeue(int & return_value)
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

Queue* Queue::copy() 
{
	Queue* buf = new Queue(this);
	return buf;
}

void Queue::resize()
{
	int* new_array = new int[current_size * resize_coefficient];
	int new_index = 0;
	for (int i = first; i < current_size; ++i) {
		new_array[new_index++] = array[i];
	}
	if (first != 0) {
		//т.к last == first сравнение через "<"
		for (int i = 0; i < last; ++i) {
			new_array[new_index++] = array[i];
		}
	}
	delete [] array;
	array = new_array;
	current_size *= resize_coefficient;
	first = 0;
	last = new_index - 1;
}

void Queue::print()
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