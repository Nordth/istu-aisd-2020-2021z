#include <iostream>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

void reverse(int* arr, int arr_size)
{
	int iter_stop = arr_size / 2;
	for (int i = 0; i < iter_stop; ++i) {
		int buf = arr[i];
		arr[i] = arr[arr_size - i - 1];
		arr[arr_size - i - 1] = buf;
	}
}

int main()
{
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, arr_size);
	for (int i = 0; i < arr_size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}