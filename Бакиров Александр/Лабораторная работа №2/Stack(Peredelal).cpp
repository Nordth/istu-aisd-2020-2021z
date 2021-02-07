#include <iostream>

using namespace std;

class Stack
{
	static const int firstSize = 5;
private:
	// Указатель на создаваемы массив
	int* Arr;
	// Индекс вершины
	int top;
	// кол-во элементов стека
	int size;
public:
	// инициализация
	Stack();
	~Stack();
	// добавление элемента в стек
	void Push();
	// получение вершины стека
	void Pop();
	// копирование...
	Stack(const Stack* otherStack);
	Stack* Copy();
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack* stack = new Stack();
	
	stack->Push();
	stack->Push();
	stack->Push();
	stack->Push();
	stack->Push();
	stack->Push();
	stack->Push();
	stack->Push();
	stack->Pop();
	Stack* stack2 = stack->Copy();
	std::cout << std::endl;

	delete stack;
	delete stack2;
}

Stack::Stack()
{
	top = -1;
	size = firstSize;
	Arr = new int[firstSize];
}

Stack::~Stack()
{
	delete[] Arr;
}


void Stack::Push()
{
	int value;
	top++;
	cout << "Введите значение, которое будет добавлено в стек: ";
	cin >> value;
	if (top >= size)
	{
		int* doubledArr = new int[size * 2];
		int index2 = 0;
		for (int i = 0; i < size; i++, index2++)
		{
			doubledArr[index2] = Arr[i];
		}
		size = size * 2;
		top = index2 - 1;
		delete[] Arr;
		Arr = doubledArr;
	}
	Arr[top] = value;
	cout << "\nЭлемент " << value << " добавлен\n";

}

void Stack::Pop()
{
	if (top == -1)
	{
		cout << "Стек пуст!";
		
	}
	cout << "\nЭлемент находящийся на вершине стека: " << Arr[top];
	top--;	

}


Stack::Stack(const Stack* copyStack)
{
	size = copyStack->size;
	Arr = new int[size];
	for (int i = 0; i <= copyStack->top; i++) {
		Arr[i] = copyStack->Arr[i];
	}
	top = copyStack->top;
}

Stack* Stack::Copy()
{
	return new Stack(this);
}
