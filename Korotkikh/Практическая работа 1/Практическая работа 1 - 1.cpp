#include <iostream>
int main()
{
	//Дан массив вещественных чисел.Вычислите среднее значение и занулите элементы, которые меньше среднего

	int num[8] = { 1, 5, 8, 12, 14, 18, 19, 31 };
	int sum = 0;

	//среднее число
	for (int i = 0; i != 8; i++) { sum += num[i]; }// складываем весь массив 
	int average = sum / 8; //делим на количество чисел

	//зануляем массив 
	for (int i = 0; i != 8; i++) {
		if (num[i] < average) { num[i] = 0; }
	}

	//вывод
	for (int i = 0; i != 8; i++) {
		std::cout << num[i] << std::endl;
	}

	std::cin >> sum;
}