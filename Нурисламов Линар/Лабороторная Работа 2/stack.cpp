//1 вариант
//стэк

#include <iostream>

class MyStack
{

static const int startLenght = 5;

private:
	int *stack;
	int size;
	int top;

	void resize();

public:
	//Инициализация
	MyStack();
	MyStack(MyStack *sourse);
	//Освоождение памяти
	~MyStack();
	//Вставка элемента
	void addItem(int x);
	//Извлечение элемента
	bool getItem(int & x);
	//Клонирование
	MyStack* getCopy();
};

int main()
{
	MyStack *stack1 = new MyStack();

	for (int i = 10; i < 21; i++) {
		stack1->addItem(i);
	}

	MyStack *stack2 = stack1->getCopy();

	std::cout << "Original stack\n";
	int buf;
	while (stack1->getItem(buf)) {
		std::cout << buf << " ";
	}
	std::cout << std::endl;

	std::cout << "Copy stack\n";
	while (stack2->getItem(buf)) {
		std::cout << buf << " ";
	}
	std::cout << std::endl;
}

MyStack::MyStack()
{
	stack = new int[startLenght];
	size = startLenght;
	top = -1;
}
	
MyStack::MyStack(MyStack *sourse)
{
	size = sourse->size;
	stack = new int[size];
	top = sourse->top;
	for (int i = 0; i <= top; i++) {
		stack[i] = sourse->stack[i];
	}
}

MyStack::~MyStack()
{
	delete[] stack;
}

void MyStack::addItem(int x)
{
	top++;
	if (top >= size) {
		resize();
	}
	stack[top] = x;
}
	
bool MyStack::getItem(int & x)
{
	if (top < 0) {
		return false;
	}
	x = stack[top];
	top--;
	return true;
}

MyStack* MyStack::getCopy()
{
	return new MyStack(this);
}

void MyStack::resize()
{
	int *newStack = new int[size * 2];
	for (int i = 0; i < size; i++) {
		newStack[i] = stack[i];
	}
	top = size;
	delete stack;
	stack = newStack;
	size *= 2;
}