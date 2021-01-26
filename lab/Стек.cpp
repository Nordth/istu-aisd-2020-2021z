#include <iostream>
#include <stack>

int main() {
	setlocale(LC_ALL, "Russian");
	int imenu = 0, number1, number2;
	std::stack <int> mass;
	std::stack <int> copymass;
	while (imenu != 6) {
		//menu output
		system("cls");
		std::cout << "Stack size:		" << mass.size() << std::endl;
		std::cout << "Stack copy size:	" << copymass.size() << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "1. Insert element." << std::endl << "2. Extract element." << std::endl << "3. Clone." << std::endl << "4. Extract item from copy." << std::endl << "5. Clear stack." << std::endl << "6. Exit." << std::endl << ">> ";
		std::cin >> imenu;
		switch (imenu) {
			case 1:
				system("cls");
				std::cout << "Number to enter: ";
				std::cin >> number1;
				mass.push(number1);
				break;
			case 2:
				system("cls");
				if ( !mass.empty() ) {
					std::cout << "Stack: " << mass.top() << " extracted." << std::endl;
					mass.pop();
				}else{ std::cout << "Empty stack." << std::endl; }
				std::system("pause");
				break;
			case 3: 
				system("cls");
				copymass = mass;
				break;
			case 4:
				system("cls");
				if (!copymass.empty()) {
					std::cout << "Stack: " << copymass.top() << " extracted." << std::endl;
					copymass.pop();
				}
				else { std::cout << "Empty stack." << std::endl; }
				std::system("pause");
				break;
			case 5:
				system("cls");
				mass = std::stack<int>();
				copymass = std::stack<int>();
				break;
			case 6:
				system("cls");
				mass = std::stack<int>();
				copymass = std::stack<int>();
				break;
		}





	}


}