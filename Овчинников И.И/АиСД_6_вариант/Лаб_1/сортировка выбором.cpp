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
	
	for (int x = 0; x < size; ++x) {
		std::cin >> arr[x];
	}
	choice_sort(arr, size);

	std::cout << "Sorted array\n";
	for (int x = 0; x < size; ++x) {
		std::cout << arr[x] << " ";
	}
	std::cout << std::endl;
	
	delete [] arr;
}

void choice_sort(int * arr, int size) 
{
	for (int x = 1; x < size; ++x) {
		int min_index = x - 1;
		for (int y = x; y < size; ++y) {
			if (arr[min_index] > arr[y]) {
				min_index = y;
			}
		}
		int buf = arr[x - 1];
		arr[x - 1] = arr[min_index];
		arr[min_index] = buf;
	}
}