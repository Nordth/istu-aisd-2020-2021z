#include <iostream>

using namespace std;

int top;// врехний элемент стека


int DoubleArr(int Stack[], int count)
{
	int count2 = count * 2;
	int *BiggerStack = new int[count2];
	for (int i = 0; i < count; i++)
		BiggerStack[i] = Stack[i];
	return BiggerStack[count2];
}

void Push(int Stack[], int count)
{
	int data;
	cout << "Введите число, которое будет добавлено в стек ";
	cin >> data;

	if (top == (count))
	{
		DoubleArr(Stack, count);
	}
	else
	{
		++top;
		Stack[top] = data;
	}
	cout << "Элемент " << data << " добавлен в стек\n";
}

void Print(int Stack[])
{

	if (top == -1 || top < -1)
	{
		cout << "Стек пуст!";
	}
	else
	{
		cout << "Стек: ";
		for (int i = top; i >= 0; --i)
		{
			cout << Stack[i] << " ";
		}
	}
	cout << "\n";
}
void Pop(int Stack[])
{
	int deleteValue;

	// Если стек пуст, то удалять нечего
	if (top == -1)
	{
		deleteValue = 0;
		cout << "Стек пуст!!!";
	}
	else
	{
		deleteValue = Stack[top];
		--top;
	}
	cout << "Элемент хранящийся на вершине стека: " << deleteValue<<"\n";
	cout << "Стек после удаления ";
	Print(Stack);
}

void Copy(int Stack[],int CopiedStack[])//Клонирую стек путем выделения новой памяти и занесения в нее всех значений из оригинального стека
{ 
	
	cout << "Копирую стек ... ";
	for (int i = top; i >= 0; --i)
	{
		CopiedStack[i] = Stack[i];
	}
	cout << "\nКопия стека:\n ";
	Print(CopiedStack);
	cout << "\nОригинал:\n ";
	Print(Stack);
}

// Очистка памяти от стека
void ClearMem(int Stack[])
{
	cout << "Удаляю стек... ";
	free(Stack);
	top = -1;
	Print(Stack);
	cout <<"\nПамять очищена!\n";
}


int main()
{
	int* CopiedStack = new int[100];
	top = -1; // изначальное значение положения первого элемента. Не 0, т.к. реализуем на базе массива
	int count = 10; // количество элементов стека.
	int data; //значение элемента стека.

	setlocale(LC_ALL, "Russian");

	int* Stack = new int[count]; // создание стека на базе массива размером count.

//	"------------------------------------------------------------------------------------------------"
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Push(Stack,count);
	Print(Stack);
	Pop(Stack);
	Copy(Stack, CopiedStack);
	return 0;
}