//5 variant
#include <iostream>

void quick_sort(int* array, unsigned left, unsigned right);

int array[] = { 2, 3, 4, 0, 1 };

int main()
{
	int arr_size = sizeof(array) / sizeof(array[0]);
	quick_sort(array, 0, arr_size - 1);
	for (int k = 0; k < arr_size; k++) {
		std::cout << array[k] << " ";
	}
	std::cout << std::endl;
}

void quick_sort(int* array, unsigned left, unsigned right)
{
	unsigned i = left;
	unsigned j = right;
	int middle = array[(left + right) / 2];
	do {
		while (array[i] < middle) i++;
		while (array[j] > middle) j--;
		if (i <= j) {
			int buf = array[i];
			array[i] = array[j];
			array[j] = buf;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > left) {
		quick_sort(array, left, j);
	}
	if (i < right) {
		quick_sort(array, i, right);
	}
}