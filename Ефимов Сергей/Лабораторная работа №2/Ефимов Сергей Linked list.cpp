//������ ������. ���������������� ������. ������� 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


struct node
{
	int data;
	struct node* next;
}*head;

class list
{
public:
	node* node(int);
	void insert_start(); // ������� �������� � ������
	void insert_position(); // ������� �������� ����� �������� ��������
	void insert_end(); // ������� �������� � �����
	void display(); // ������ ���� ���������
	void delete_position(); // �������� �������� �� ��������
	void memoryDelete();//������������ ������
	void search(int); // ��������� �������� �������� �� �������
	list()
	{
		head = NULL;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int command;
	bool process = true;
	list list;
	head = NULL;

	cout << "0. ������� �������� � �����" << endl;
	cout << "1. ������� �������� � ������" << endl;
	cout << "2. ������� �������� ����� �������� ��������" << endl;
	cout << "3. ������ ���� ���������" << endl;
	cout << "4. �������� �������� �� ��������" << endl;
	cout << "5. ��������� �������� �������� �� �������" << endl;
	cout << "6. ������������ ������ �� ��������� ������" << endl;
	cout << "7. �����" << endl;
	while (process == true)
	{
		cout << "��� �� ������ �������? ";

		cin >> command;

		switch (command)
		{
		case 0:
			//" ������� �������� � �����";
			list.insert_end();
			cout << endl;
			break;
		case 1:
			// "������� �������� � ������. ";
			list.insert_start();
			cout << endl;
			break;
		case 2:
			// "������� �������� ����� �������� ��������. ";
			list.insert_position();
			cout << endl;
			break;
		case 3:
			// "������ ���� ���������. ";
			list.display();
			cout << endl;
			break;
		case 4:
			//"�������� �������� �� ��������. ";
			list.delete_position();
			cout << endl;
			break;
		case 5:
			// "��������� �������� �������� �� �������. ";
			int index; cout << endl << "������� ������: ";  cin >> index;
			list.search(index);
			cout << endl;
			break;
		case 6:
			// "������������ ������ �� ��������� ������. ";
			list.memoryDelete();
			break;
		case 7:
			cout << endl << endl << "���������� ���������";
			return 0;
			break;

		default:
			cout << "������������ �����";
		}
		cout << endl << endl;
	}
};

node* list::node(int a)
{
	struct node* temp;
	temp = new(struct node);
	temp->data = a;
	temp->next = NULL;
	return temp;
}


void list::memoryDelete() 
{
	struct node* temp;
	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}


void list::insert_start()
{
	int number;
	cout << "������� ��������, ������� ������ ��������: ";
	cin >> number;
	struct node* temp, * p;
	temp = node(number);
	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		p = head;
		head = temp;
		head->next = p;
	}
}

void list::insert_position()
{
	int number, index, size = 0;
	cout << "������� ��������, ������� ������ ��������: ";
	cin >> number;
	struct node* temp, * p = 0, * p2 = 0;
	temp = node(number);
	cout << "������� ������, ����� ������� ������ ��������";
	cin >> index;
	int i;
	p = head;
	while (p != NULL)
	{
		p = p->next;
		size++;
	}
	if (index == 0)
	{
		cout << "�����������, �� ���������� ������ �������";
	}


	if (index == 1)
	{
		if (head == NULL)
		{
			head = temp;
			head->next = NULL;
		}
		else
		{
			p2 = head;
			head = temp;
			head->next = p2;
		}
	}
	else if (index > 1 && index <= size)
	{
		p = head;
		for (i = 1; i < index; i++)
		{
			p2 = p;
			p = p->next;
		}
		p2->next = temp;
		temp->next = p;
	}
	else
	{
		cout << "������� ��� ����" << endl;
	}
}

void list::delete_position()//������� ������� ���������. ���� �� ����� ����� ����.
{
	struct node* current = head;
	struct node* next = current;
	struct node* prev = head;
	int number;
	cout << "������� �����, ������� ����� �������: ";
	cin >> number;
	while (current != NULL)
	{
		if (current->data == number)
		{
			break;
		}
		else
		{
			cout << "����� " << current->data << " �� �������������" << number << endl;
			prev = current;
			current = current->next;
		}
	}
	if (current == NULL)
	{
		cout << "����� �� �������.";
	}
	else
	{
		cout << "�������� ����� " << current->data << endl;
		prev->next = current->next;
		free(current);
	}
}


void list::search(int index)//��������
{
	int size = 0;
	struct node* element, * p;
	element = head;
	if (head == NULL)
	{
		cout << "���� ����" << endl;
		return;
	}
	p = head;
	while (p != NULL)
	{
		p = p->next;
		size++;//������ ������ ������, ����� ����� ��������� �������� �� �����
	}

	if (index < size)
	{
		if (index == 0)
		{
			cout << "�������� - " << element->data;
		}
		else {
			for (int i = 0; i != index; i++)
			{
				element = element->next;

				if (i == index - 1)
				{
					cout << "�������� - " << element->data;
				}
			}
		}
	}
	else
	{
		cout << "������ �� ��������� ������";
	}
}

void list::display()
{
	struct node* element;
	if (head == NULL) //���� � ������ ��� ������
	{
		cout << "���� ������ ����" << endl;
		return;
	}
	element = head;
	cout << endl << endl << endl << "��������: ";
	while (element != NULL)
	{
		if (element->next != NULL)
		{
			cout << element->data << ", ";
			element = element->next;
		}
		else
		{
			cout << element->data;
			element = element->next;
		}
	}
	cout << endl;
}

void list::insert_end()
{
	struct node* temp, * h;
	int number;
	cout << "������� �����, ������� ������ ��������� � ����� ������: ";
	cin >> number;
	temp = node(number);
	h = head;
	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else 
	{
		while (h->next != NULL)
		{
			h = h->next;
		}
		temp->next = NULL;
		h->next = temp;
	}
}