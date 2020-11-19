#include <iostream>

const int values_number = 10;
int arr[] = {9, 7, 9, 8, 6, 6, 3, 1, 2, 0, 2};
int number_repeat[values_number];

int main()
{
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < arr_size; ++i) {
		number_repeat[arr[i]]++;
	}
	for (int i = 0; i <= values_number; ++i) {
		for (int j = 0; j < number_repeat[i]; ++j) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}