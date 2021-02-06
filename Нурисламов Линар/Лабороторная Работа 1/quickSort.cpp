//1 вариант
//быстрая сортировка

#include <iostream>

void quickSort(int *array, int left, int right)
{
	int l = left;
	int r = right;
	int x = array[(l + r) / 2];
	do {
		for ( ; array[l] < x; l++) {}
		for ( ; array[r] > x; r--) {}
		if (l <= r) {
			int buf = array[l];
			array[l] = array[r];
			array[r] = buf;
			l++,r--;
		} 
	} while (l < r);
	if (r > left) {
		quickSort(array, left, r);
	}
	if (l < right) {
		quickSort(array, l, right);
	}
}

int array[] = {7, 3, -22, -9, 0, 56, 78, 3, 2,};

int main()
{
	int size = sizeof(array) / sizeof(array[0]);

	std::cout << "After sort\n";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	quickSort(array, 0, size - 1);

	std::cout << "Before sort\n";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}