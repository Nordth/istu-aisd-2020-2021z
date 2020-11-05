#include <iostream>

void calculator()
{
	int a, b, r;
	char op;
	bool is_correct = true;
	
	std::cin >> a >> op >> b;
	
	switch(op) {
		case '+':
			r = a + b;
			break;
		case '-':
			r = a - b;
			break;
		case '*':
			r = a * b;
			break;
		case '/':	
			if(b == 0) {
				is_correct = false;
			} else {
				r = a / b;
			}
			break;
		default:
			is_correct = false;
	}
	if (is_correct) {
		std::cout << r << std::endl;
	} else {
		std::cout << "Incorrect operation\n";
	}
}

int main() 
{
	calculator();
}