#include <iostream>

void calculator()
{
	int x, y, z;
	char g;
	bool is_cor = true;
	
	std::cin >> x >> g >> y;
	
	switch(g) {
		case '+':
			z = x + y;
			break;
		case '-':
			z = x - y;
			break;
		case '*':
			z = x * y;
			break;
		case '/':	
			if(y == 0) {
				is_cor = false;
			} else {
				z = x / y;
			}
			break;
		default:
			is_cor = false;
	}
	if (is_cor) {
		std::cout << z << std::endl;
	} else {
		std::cout << "Incorrect operation\n";
	}
}

int main() 
{
	calculator();
}