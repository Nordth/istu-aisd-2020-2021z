#include <iostream>
int main()
{
	int a, b, r;
	std::string op;
	std::cout << "number one: "; // user put any number
	std::cin >> a;
	std::cout << "number two: "; 
	std::cin >> b;
	std::cout << "math sign: "; 
	std::cin >> op;

	if (op == "+") { r = a + b; }
	else if (op == "-") { r = a - b; }
	else if (op == "*") { r = a * b; }
	else if (op == "/") { r = a / b; }

	std::cout << "Answer: " << r;
	std::cin >> b;


}