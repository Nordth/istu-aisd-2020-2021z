//сортировка слиянием
//2 вариант
#include <iostream>

int *array = nullptr;
int *buffer = nullptr;

void merge_array(int* array, int left, int centre_pos, int right)
{
	int buf_index = 0;
	int left_arr_index = left;
	int right_arr_index = centre_pos + 1;
	while (left_arr_index < centre_pos + 1 && right_arr_index <= right) {
		if (array[left_arr_index] < array[right_arr_index]) {
			buffer[buf_index] = array[left_arr_index];
			left_arr_index++;
		}
		else { 
			buffer[buf_index] = array[right_arr_index];
			right_arr_index++;
		}
		buf_index++;
	}
	while (left_arr_index < centre_pos + 1) {
		buffer[buf_index] = array[left_arr_index];
		buf_index++;
		left_arr_index++;
	}
	while (right_arr_index <= right) {
		buffer[buf_index] = array[right_arr_index];
		buf_index++;
		right_arr_index++;
	}
	for (int i = 0, j = left; i < buf_index; i++, j++) {
		array[j] = buffer[i];
	}
}

void merge_sort(int* array, int left, int right)
{
	if (right - left <= 1) {
		if (array[left] > array[right]) {
			int buf = array[left];
			array[left] = array[right];
			array[right] = buf;
		}
		return;
	}
	int centre_pos = (left + right) / 2;
	merge_sort(array, left, centre_pos);
	merge_sort(array, centre_pos + 1, right);
	merge_array(array, left, centre_pos, right);
}

int main() 
{
	
	int length;
	std::cout << "Write array length: ";
	std::cin >> length;
	array = new int[length];
	buffer = new int[length];
	std::cout << "Write array items\n";
	for (int i = 0; i < length; i++) {
		std::cin >> array[i];
	}
	
	merge_sort(array, 0, length - 1);

	std::cout << "Sorted array: \n";
	for (int i = 0; i < length; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	delete[] array;
	delete[] buffer;
}
