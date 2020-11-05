
#include <iostream>
using namespace std;
int main()
{
	float a, b, result=0;
	char c;
	cin >> a >> c >> b;
	if (c == '+')
		result = a + b;
	else
		if (c == '-')
			result = a - b;
		else
			if (c == '*')
				result = a * b;
			else
				if (c == '/')
					result = a / b;
			
	cout << result;
}