#include <iostream>
#include <stack>

int main() {
	setlocale(LC_ALL, "Russian");
	int imenu = 0, number1, number2;
	std::stack <int> mass;
	std::stack <int> copymass;
	while (imenu != 6) {
		//вывод меню
		system("cls");
		std::cout << "Размер стека:		" << mass.size() << std::endl;
		std::cout << "Размер копии стека:	" << copymass.size() << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "1. Вставка эллемента." << std::endl << "2. Извлечь эллемент." << std::endl << "3. Клонирование." << std::endl << "4. Извлечь эллемент из копии." << std::endl << "5. Очистить стек." << std::endl << "6. Выход." << std::endl << ">> ";
		std::cin >> imenu;
		switch (imenu) {
			case 1:
				system("cls");
				std::cout << "Число для ввода: ";
				std::cin >> number1;
				mass.push(number1);
				break;
			case 2:
				system("cls");
				if ( !mass.empty() ) {
					std::cout << "Стек: " << mass.top() << " извлечен." << std::endl;
					mass.pop();
				}else{ std::cout << "Стек пустой." << std::endl; }
				std::system("pause");
				break;
			case 3: 
				system("cls");
				copymass = mass;
				break;
			case 4:
				system("cls");
				if (!copymass.empty()) {
					std::cout << "Стек: " << copymass.top() << " извлечен." << std::endl;
					copymass.pop();
				}
				else { std::cout << "Стек пустой." << std::endl; }
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