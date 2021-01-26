
#include <iostream>
using namespace std;
int main()
{
	float a, b, result=0;
	char c;
	cin >> a >> c >> b;
	switch (c)
	{
		case '+': 
			cout<<a+b;
			break;
		case '-':
			cout<<a-b;
			break;
		case '*':
			cout<<a*b;
			break;
		case '/':
			cout<<a/b;
			break;
	}	
}