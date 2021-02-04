#include <iostream>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

int recurent_sum(int* arr, int current_index, int arr_size)
{
	if (current_index == arr_size) {
		return arr[current_index];
	} else {
		return arr[current_index] + recurent_sum(arr, 
											current_index + 1,
											arr_size);
	}
}

int main()
{
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	std::cout << recurent_sum(arr, 0, arr_size - 1);
}