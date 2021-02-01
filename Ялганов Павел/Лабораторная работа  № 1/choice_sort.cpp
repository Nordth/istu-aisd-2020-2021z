//5 variant
#include <iostream>

int array[] = { 2, 3, 4, 0, 1};

void choice_sort(int* array, int size);

int main() 
{
	int size = sizeof(array) / sizeof(array[0]);
	choice_sort(array, size);

	std::cout << "Sorted array\n";
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void choice_sort(int * array, int size) 
{
	for (int i = 1; i < size; ++i) {
		int base_index = i - 1;
		for (int j = i; j < size; ++j) {
			if (array[base_index] > array[j]) {
				base_index = j;
			}
		}
		int buf = array[i - 1];
		array[i - 1] = array[base_index];
		array[base_index] = buf;
	}
}