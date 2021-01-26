#include <iostream>
#include <vector>

int main(){
	int imenu=0 ,number1, number2;
	std::vector<int> mass;
	setlocale(LC_ALL, "Russian");
	while (imenu != 5) {
		system("cls");
		//array output
		if ( mass.empty() ) {std::cout << "Массив пустой!!!";
		}else{
			std::cout << "Массив: { ";
			for (int i = 0; i != mass.size(); i++) { std::cout << mass[i] << ", "; }
			std::cout << "}";
		}std::cout << std::endl;

		//menu output
		std::cout << std::endl << "1. Добавить значение в конец." << std::endl << "2. Вставить после." << std::endl << "3. Получить значение по индексу." << std::endl << "4. Удаление элемента по значению." << std::endl << "5. Выход." << std::endl << ">> ";
        std::cin >> imenu;

		//menu function
        switch (imenu) {
		case 1:
			system("cls");
			std::cout << "число: ";
			std::cin >> number1;
			mass.push_back(number1);
			break;
		case 2:
			system("cls");
			std::cout << "число: ";
			std::cin >> number1;
			std::cout << "вставить в: ";
			std::cin >> number2;
			mass.emplace(mass.begin()+number2+1, number1);
			break;
		case 3: 
			system("cls");
			std::cout << "индекс: ";
			std::cin >> number1;
			std::cout << mass[number1-1] << std::endl;
			system("pause");
			break;
		case 4: 
			std::cout << "число: ";
			std::cin >> number1;
			for (int i = 0; i != mass.size(); i++) {
				//delete if finded
				if (mass[i] == number1) {mass.erase(mass.begin() + i);break;}
			}
			break;
        }
	}
}


