#include <iostream>
#include <vector>

int main(){
	int imenu=0 ,number1, number2;
	std::vector<int> mass;
	setlocale(LC_ALL, "Russian");
	while (imenu != 5) {
		system("cls");
		if ( mass.empty() ) {std::cout << "Array is empty!!!";
		}else{
			std::cout << "Array: { ";
			for (int i = 0; i != mass.size(); i++) { std::cout << mass[i] << ", "; }
			std::cout << "}";
		}std::cout << std::endl;

		std::cout << std::endl << "1. Add a value to the end." << std::endl << "2. Insert after." << std::endl << "3. Get the value by index." << std::endl << "4. Deleting an element by value." << std::endl << "5. Exit." << std::endl << ">> ";
        std::cin >> imenu;

        switch (imenu) {
		case 1:
			system("cls");
			std::cout << "number: ";
			std::cin >> number1;
			mass.push_back(number1);
			break;
		case 2:
			system("cls");
			std::cout << "number: ";
			std::cin >> number1;
			std::cout << "insert in: ";
			std::cin >> number2;
			mass.emplace(mass.begin()+number2+1, number1);
			break;
		case 3: 
			system("cls");
			std::cout << "index: ";
			std::cin >> number1;
			std::cout << mass[number1-1] << std::endl;
			system("pause");
			break;
		case 4: 
			std::cout << "number: ";
			std::cin >> number1;
			for (int i = 0; i != mass.size(); i++) {
				if (mass[i] == number1) {mass.erase(mass.begin() + i);break;}
			}
			break;
        }
	}
}


