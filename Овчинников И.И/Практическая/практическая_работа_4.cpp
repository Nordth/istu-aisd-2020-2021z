#include <iostream>

const int number_repeat_size = 10;
int arr[] = {9, 7, 9, 8, 6, 6, 3, 1, 2, 0, 2};
int number_repeat[number_repeat_size];

int main()
{
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < number_repeat_size; ++i) {
		number_repeat[i] = 0;
	}
	for (int i = 0; i < arr_size; ++i) {
		number_repeat[arr[i]]++;
	}
	for (int i = 0; i < number_repeat_size; ++i) {
		for (int j = 0; j < number_repeat[i]; ++j) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}