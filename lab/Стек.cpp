#include <iostream>
#include <stack>

int main() {
	setlocale(LC_ALL, "Russian");
	int imenu = 0, number1, number2;
	std::stack <int> mass;
	std::stack <int> copymass;
	while (imenu != 6) {
		//����� ����
		system("cls");
		std::cout << "������ �����:		" << mass.size() << std::endl;
		std::cout << "������ ����� �����:	" << copymass.size() << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "1. ������� ���������." << std::endl << "2. ������� ��������." << std::endl << "3. ������������." << std::endl << "4. ������� �������� �� �����." << std::endl << "5. �������� ����." << std::endl << "6. �����." << std::endl << ">> ";
		std::cin >> imenu;
		switch (imenu) {
			case 1:
				system("cls");
				std::cout << "����� ��� �����: ";
				std::cin >> number1;
				mass.push(number1);
				break;
			case 2:
				system("cls");
				if ( !mass.empty() ) {
					std::cout << "����: " << mass.top() << " ��������." << std::endl;
					mass.pop();
				}else{ std::cout << "���� ������." << std::endl; }
				std::system("pause");
				break;
			case 3: 
				system("cls");
				copymass = mass;
				break;
			case 4:
				system("cls");
				if (!copymass.empty()) {
					std::cout << "����: " << copymass.top() << " ��������." << std::endl;
					copymass.pop();
				}
				else { std::cout << "���� ������." << std::endl; }
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