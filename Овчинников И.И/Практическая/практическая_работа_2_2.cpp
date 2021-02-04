#include <iostream>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

void reverse(int* arr, int arr_size)
{
	int iter_s = arr_size / 2;
	for (int x = 0; x < iter_s; ++x) {
		int b = arr[x];
		arr[x] = arr[arr_size - x - 1];
		arr[arr_size - x - 1] = b;
	}
}

int main()
{
	int arr_s = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, arr_s);
	for (int x = 0; x < arr_s; ++x) {
		std::cout << arr[x] << " ";
	}
	std::cout << std::endl;
}