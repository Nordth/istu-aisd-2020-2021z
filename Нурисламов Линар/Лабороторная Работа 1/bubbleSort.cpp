//1 вариант
//пузырьковая сортировка

#include <iostream>

void bubbleSort(int *array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				int buf = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buf;
			}
		}
	}
}

int array[] = {9, 4, 3, 1, 5, 6, 8, 7, 0, -1, -2};

int main()
{
	int size = sizeof(array) / sizeof(array[0]);

	std::cout << "After sort\n";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	bubbleSort(array, size);

	std::cout << "Before sort\n";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}