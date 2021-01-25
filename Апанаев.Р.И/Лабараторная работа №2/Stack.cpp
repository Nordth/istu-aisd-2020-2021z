#include<iostream>
#include<ctime>
#include<time.h>
#include <stdlib.h>
using namespace std;

class STACK
{
public:
	STACK();
	STACK(const STACK& st)
	{
	stack = new int[st.N];
	N = st.N;
	for (int i = 0; i < N; i++)
	{
	stack[i] = st.stack[i];
	}
	}	
	~STACK();
	void addit(int xy);
	int top();
	int Nsize();
	void output();
private:
	int* stack;
	int N;
};

STACK::STACK()
{
	N = 0;
}

STACK::~STACK()
{
	delete[] stack;
}
void STACK::addit(int xy)
{
	int* temp;
	temp = stack;
	stack = new int[N + 1];
	N++;
	for (int i = 0; i < N - 1; i++)
	{
		stack[i] = temp[i];
	}
	stack[N - 1] = xy;
	if (N > 1)
	{
		delete[] temp;
	}
}
int STACK::top()
{
	if (N == 0)
	{
		return 0;
	}
	N--;
	return stack[N];
}
int STACK::Nsize()
{
	return N;
}
void STACK::output()
{
	int* p;
	p = stack;
	for (int i = 0; i < N; i++)
	{
		cout <<"Номер["<< i <<"] = "<< *p << endl;
		p++;
	}
	cout << endl;
}

int main()
{	
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	STACK stack1;
	int aN, up;
	cout << "Какой размер стека ?: ";
	cin >> aN;
	for (int i = 0; i < aN; i++)
	{
		stack1.addit(rand() % 50);
	}
	cout << "Заполненный стек №1:" << endl;
	stack1.output();
	cout << "Добавляем значение 51 на вершину стека" << endl;
	up=51;
	stack1.addit(up);
	stack1.output();
	STACK stack2(stack1);
	cout << "Вершина стека: " << stack1.top() << endl;
	stack1.output();
	cout << "Заполненный стек №2:" << endl;
	stack2.output();
}

