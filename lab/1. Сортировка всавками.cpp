#include <iostream>
#include <string>
int main()
{
	//Сортировка вставками
	int j, key = 0, i;
	int mass[6] = { 5, 2, 4, 6, 1, 3 };
	for (j = 1; j != 6; j++) {
		key = mass[j];
		i = j - 1;
		while( i != -1 && key < mass[i]) {
			mass[i+1] = mass[i];
			i--;
		}
		mass[i + 1] = key;
	}

	std::cout << "array: " << mass[0];
	for (int i = 1; i != 6; i++) { std::cout << ", " << mass[i]; }


}