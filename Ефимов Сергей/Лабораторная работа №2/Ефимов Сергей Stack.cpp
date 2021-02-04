#include<iostream>

using namespace std;

int up; //индекс вершины стака 
bool ifNotEmpty;

int pop(int stack[])
{
	int element;
	if (up == -1)
	{
		element = 0;
		ifNotEmpty = false;
	}
	else
	{
		ifNotEmpty = true;
		element = stack[up];
		--up;
	}
	return element;
}

//увеличение буфера в 2 раза происходит в main
void push(int stack[], int element, int size)
{
	if (up == (size - 1))
	{
		ifNotEmpty = false;
	}
	else
	{
		ifNotEmpty = true;
		++up;
		stack[up] = element;
	}
}

void showstack(int stack[])
{
	int i;

	cout << "\nЭлементы: ";

	if (up == -1 || up < -1)
	{
		cout << "пуст";
	}

	else
	{
		for (i = up; i >= 0; --i)
			cout << stack[i] << " ";
	}
	cout << "\n";
}

int Clone(int oldStack[], int size, int i)//изменил клонирование
{
	return oldStack[i];
}

void memoryDelete(int stack[])
{
	free(stack);
	up = -1;
	showstack(stack);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер массива: ";
	bool process = true;
	int max;
	cin >> max;
	int* stack = new int[max], element;
	int* copyStack = new int[max];
	int command;
	up = -1;

	cout << "\nВыберете что нужно сделать: \n";
	cout << "\n1. Вставка элемента";
	cout << "\n2. Извлечение элемента";
	cout << "\n3. Показать функцию клонирования";
	cout << "\n4. Освобождение памяти от структуры данных";
	cout << "\n5. Выход";

	while (process == true)
	{

		cout << "\n\nВведите команду: ";
		cin >> command;

		switch (command)
		{
		case 1://добавление
			cout << "Какое число добавить? ";
			cin >> element;
			cout << element;
			push(stack, element, max);

			if (ifNotEmpty == true)
			{
				cout << "\n Стек после операции";
				showstack(stack);

				if (up == (max - 1))
				{
					max = max * 2;//увеличение буфера в два раза
				}
			}
			//это условие никогда не сможет осуществиться, так как память увеличивается в два раза дойдя до предела
			else
				cout << "стек переполнен";
			break;
		case 2://извлечение
			element = pop(stack);
			if (ifNotEmpty == true)
			{
				cout << "\n Стек после операции ";
				showstack(stack);
			}

			else
			{
				cout << "стек пуст";
			}
			break;
		case 3://клонирование
			for (int i = up; i >= 0; --i)
			{
				copyStack[i] = Clone(stack, max, i);
			}
			cout << "\nКОПИЯ: ";
			showstack(copyStack);
			cout << "\nНЕ КОПИЯ: ";
			showstack(stack);
			break;
		case 4://освобождение
			memoryDelete(stack);
			break;
		case 5://выход
			return 0;
			break;
		default:
			cout << "Команда не верна." << endl;
		}
	}
	return 0;
}