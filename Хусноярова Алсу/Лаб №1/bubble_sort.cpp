//пузырьковая сортировка
//2 вариант
#include <iostream>

void bubble_sort(int *array, int length)
{
	for (int i = 0; i < length - 1; i++) {
		for (int j = length - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				int buf = array[j];
				array[j] = array[j - 1];
				array[j - 1] = buf;
			}
		}
	}
}

int *array = nullptr;

int main()
{
	int length;
	std::cout << "Write array length: ";
	std::cin >> length;
	array = new int[length];
	std::cout << "Write array items\n";
	for (int i = 0; i < length; i++) {
		std::cin >> array[i];
	}

	bubble_sort(array, length);

	std::cout << "Sorted array: \n";
	for (int i = 0; i < length; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	delete[] array;
}