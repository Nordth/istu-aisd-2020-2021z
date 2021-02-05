#include <iostream>
#include <fstream>

class Queue {

static const int start_size = 10;//начальный размер массива
static const int resize_coefficient = 2;//коэффициент увеличения при переполнении

public:
	Queue();//Инициализация
	~Queue();//Освобождение памяти от структуры данных
	void enqueue(int item);//Вставка элемента
	bool dequeue(int & return_value);//Извлечение элемента
	
	Queue* copy();//Клонирование
	void print();
private:
	int* array;
	int first, last, current_size;
	
	bool is_empty;//если true массив пуст

	Queue(const Queue * copy);
	void resize();
};

const char* default_file_name = {"task_b_test.txt"};

int main(int argc, char** argv)
{
	std::ifstream input_f;
	if (argc > 1) {
		input_f.open(argv[1]);
	} else {
		input_f.open(default_file_name);
	}
	int buf;
	Queue* q_1 = new Queue();
	while (input_f >> buf) {
		q_1->enqueue(buf);
	}
	Queue* q_2 = q_1->copy();
	while (q_1->dequeue(buf)) {
		std::cout << buf << " ! ";
	}
	std::cout << std::endl;
	q_2->print();
	input_f.close();
	delete q_1;
	delete q_2;
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
	int new_ind = 0;
	int first_end = last < first ? current_size : last + 1;
	for (int x = first; x < first_end; ++x) {
		array[new_ind++] = source->array[x];
	}
	if (last < first) {
		for (int x = 0; x <= last; ++x) {
			array[new_ind++] = source->array[x];
		}
	}
	first = 0;
	last = new_ind - 1;
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
	for (int x = first; x < current_size; ++x) {
		new_array[new_index++] = array[x];
	}
	if (first != 0) {
		//т.к last == first сравнение через "<"
		for (int x = 0; x < last; ++x) {
			new_array[new_index++] = array[x];
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
	for (int x = first; x < first_end; ++x) {
		std::cout << array[x] << " ";
	}
	if (last < first) {
		for (int x = 0; x <= last; ++x) {
			std::cout << array[x] << " ";
		}
	}
	std::cout << std::endl;
}