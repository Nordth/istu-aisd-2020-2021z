//стэк
//2 вариант
#include <iostream>

class Stack
{
static const int start_size = 5;

private:
	int *arr;
	int top;
	int len;

	void ChangeSize();
public:
	//Инициализация
	Stack();
	Stack(const Stack *stack);
	//Освобождение памяти
	~Stack();
	//Вставка элемента
	void Push(int item);
	//Извлечение элемента
	bool Pop(int &item);
	//Клонирование
	Stack* CreateCopy();
};

int main()
{
	Stack *st1 = new Stack();

	for (int i = 0; i < 10; i++) {
		st1->Push(i);
	}

	int buf;
	std::cout << "Print five elements from original stack\n";
	for (int i = 0; i < 5; i++) {;
		st1->Pop(buf);
		std::cout << buf << " ";
	}
	std::cout << std::endl;
	std::cout << "Print elements from copy stack\n";
	Stack *st2 = st1->CreateCopy();
	while (st2->Pop(buf)) {
		std::cout << buf << " ";
	}
	std::cout << std::endl;

	delete st1;
	delete st2;
}

Stack::Stack()
{
	arr = new int[start_size];
	top = -1;
	len = start_size;
}

Stack::Stack(const Stack *stack)
{
	len = stack->len;
	arr = new int[len];
	top = stack->top;
	for (int i = 0; i <= top; i++) {
		arr[i] = stack->arr[i];
	}
}

Stack::~Stack()
{
	delete[] arr;
}

void Stack::Push(int item) 
{
	if (++top >= len) {
		ChangeSize();
	}
	arr[top] = item;
}

bool Stack::Pop(int &item)
{
	if (top >= 0) {
		item = arr[top--];
		return true;
	}
	return false;
}

Stack* Stack::CreateCopy()
{
	return new Stack(this);
}

void Stack::ChangeSize()
{
	int *new_arr = new int[len * 2];
	for (int i = 0; i < len; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	top = len;
	len *= 2;
	arr = new_arr;
}