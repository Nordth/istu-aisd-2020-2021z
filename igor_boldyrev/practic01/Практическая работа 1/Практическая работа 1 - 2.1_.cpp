#include <iostream>
int main()
{
	int a, b, r;
	std::string op;
	std::cout << "number one: "; // просим пользователя ввести любое число
	std::cin >> a;
	std::cout << "number two: "; // просим пользователя ввести любое число
	std::cin >> b;
	std::cout << "math sign: "; // просим пользователя ввести любое число
	std::cin >> op;

	if (op == "+") { r = a + b; }
	else if (op == "-") { r = a - b; }
	else if (op == "*") { r = a * b; }
	else if (op == "/") { r = a / b; }

	std::cout << "Answer: " << r; // просим пользователя ввести любое число
	std::cin >> b;


}