//6 вариант
//сортировка выбором
#include <iostream>

const int arraySize = 10;
int array[arraySize];

void sort(int* array, int array_size);

int main() 
{
	std::cout << "Write "<< arraySize << " numbers\n";
	for (int i = 0; i < arraySize; i++) {
		std::cin >> array[i];
	}
	
	sort(array, arraySize);

	std::cout << "Sorted array\n";
	for (int i = 0; i < arraySize; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void sort(int * array, int array_size) 
{
	for (int i = 1; i < array_size; i++) {
		int index_min = i - 1;
		for (int j = i; j < array_size; j++) {
			if (array[index_min] > array[j]) {
				index_min = j;
			}
		}
		int tmp = array[i - 1];
		array[i - 1] = array[index_min];
		array[index_min] = tmp;
	}
}