//сортировка выбором
#include <iostream>

int* arr = nullptr;

void choice_sort(int* arr, int size);

int main() 
{
	int size;
	std::cout << "Write size of array\n";
	std::cin >> size;
	arr = new int[size];
	std::cout << "Write array's items\n";
	
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	choice_sort(arr, size);

	std::cout << "Sorted array\n";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	delete [] arr;
}

void choice_sort(int * arr, int size) 
{
	for (int i = 1; i < size - 1; ++i) {
		int min_index = i - 1;
		for (int j = i; j < size; ++j) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		int buf = arr[i - 1];
		arr[i - 1] = arr[min_index];
		arr[min_index] = buf;
	}
}