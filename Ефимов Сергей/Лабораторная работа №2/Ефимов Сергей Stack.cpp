#include<iostream>

using namespace std;

int up; //������ ������� ����� 
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

//���������� ������ � 2 ���� ���������� � main
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

	cout << "\n��������: ";

	if (up == -1 || up < -1)
	{
		cout << "����";
	}

	else
	{
		for (i = up; i >= 0; --i)
			cout << stack[i] << " ";
	}
	cout << "\n";
}

int Clone(int oldStack[], int size, int i)//������� ������������
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
	cout << "������� ������ �������: ";
	bool process = true;
	int max;
	cin >> max;
	int* stack = new int[max], element;
	int* copyStack = new int[max];
	int command;
	up = -1;

	cout << "\n�������� ��� ����� �������: \n";
	cout << "\n1. ������� ��������";
	cout << "\n2. ���������� ��������";
	cout << "\n3. �������� ������� ������������";
	cout << "\n4. ������������ ������ �� ��������� ������";
	cout << "\n5. �����";

	while (process == true)
	{

		cout << "\n\n������� �������: ";
		cin >> command;

		switch (command)
		{
		case 1://����������
			cout << "����� ����� ��������? ";
			cin >> element;
			cout << element;
			push(stack, element, max);

			if (ifNotEmpty == true)
			{
				cout << "\n ���� ����� ��������";
				showstack(stack);

				if (up == (max - 1))
				{
					max = max * 2;//���������� ������ � ��� ����
				}
			}
			//��� ������� ������� �� ������ �������������, ��� ��� ������ ������������� � ��� ���� ����� �� �������
			else
				cout << "���� ����������";
			break;
		case 2://����������
			element = pop(stack);
			if (ifNotEmpty == true)
			{
				cout << "\n ���� ����� �������� ";
				showstack(stack);
			}

			else
			{
				cout << "���� ����";
			}
			break;
		case 3://������������
			for (int i = up; i >= 0; --i)
			{
				copyStack[i] = Clone(stack, max, i);
			}
			cout << "\n�����: ";
			showstack(copyStack);
			cout << "\n�� �����: ";
			showstack(stack);
			break;
		case 4://������������
			memoryDelete(stack);
			break;
		case 5://�����
			return 0;
			break;
		default:
			cout << "������� �� �����." << endl;
		}
	}
	return 0;
}