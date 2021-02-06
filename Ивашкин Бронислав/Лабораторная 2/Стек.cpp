#include <iostream>

class Stack
{
static const int startLength = 5;
private:
	int *array;
	int currentIndex;
	int length;

	void Resize();
public:
	Stack();
	Stack(const Stack *otherStack);
	~Stack();
	void Add(int value);
	bool Get(int &value);
	Stack* Copy();
};

int main()
{
	Stack *stack = new Stack();

	for (int i = 0; i < 10; i++) {stack->Add(i);}
	Stack *stack2 = stack->Copy();
	int buf;
	std::cout << "Original stack:\n";
	while (stack->Get(buf)) {std::cout << buf << " ";}
	std::cout << std::endl;

	std::cout << "Copy stack:\n";
	while (stack2->Get(buf)) {std::cout << buf << " ";}
	std::cout << std::endl;
	delete stack;
	delete stack2;
}

Stack::Stack()
{
	currentIndex = -1;
	length = startLength;
	array = new int[startLength];
}

Stack::Stack(const Stack *otherStack)
{
	length = otherStack->length;
	array = new int[length];
	for (int i = 0; i <= otherStack->currentIndex; i++) {array[i] = otherStack->array[i];}
	currentIndex = otherStack->currentIndex;
}

Stack::~Stack(){delete[] array;}

void Stack::Add(int value)
{
	currentIndex++;
	if (currentIndex >= length) {Resize();}
	array[currentIndex] = value;
}

bool Stack::Get(int &value)
{
	if (currentIndex == -1) {return false;}
	value = array[currentIndex];
	currentIndex--;
	return true;
}

Stack* Stack::Copy(){return new Stack(this);}

void Stack::Resize()
{
	int *newArray = new int[length * 2];
	int newArrayIndex = 0;
	for (int i = 0; i < length; i++, newArrayIndex++) {newArray[newArrayIndex] = array[i];}
	length *= 2;
	currentIndex = newArrayIndex - 1;
	delete[] array;
	array = newArray;
}

