//сортировка слиянием
#include <iostream>

int* arr = nullptr;
int* global_buffer = nullptr;

//array's index == [left, right], not [left, right)
void merge_sort(int* arr, int left, int right);
void merge_array(int* arr, int left, int middle, int right);

int main() 
{
	int size;
	std::cout << "Write size of array\n";
	std::cin >> size;
	
	arr = new int[size];
	global_buffer = new int[size];

	std::cout << "Write array's items\n";
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	
	merge_sort(arr, 0, size - 1);

	std::cout << "Sorted array\n";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	delete [] arr;
	delete [] global_buffer;
}

void merge_sort(int* arr, int left, int right)
{
	if (right - left <= 1) {
		if (arr[left] > arr[right]) {
			int buf = arr[left];
			arr[left] = arr[right];
			arr[right] = buf;
		}
		return;
	}
	int middle = (left + right) / 2;
	merge_sort(arr, left, middle);
	merge_sort(arr, middle + 1, right);
	merge_array(arr, left, middle, right);
}

void merge_array(int* arr, int left, int middle, int right)
{
	int first = left;
	int second = middle + 1;
	int buffer_index = 0;
	while (first <= middle && second <= right) {
		if (arr[first] <= arr[second]) {
			global_buffer[buffer_index++] = arr[first++];
		}
		else { //arr[first] > arr[second]
			global_buffer[buffer_index++] = arr[second++];
		}
	}
	while (first <= middle) {
		global_buffer[buffer_index++] = arr[first++];
	}
	while (second <= right) {
		global_buffer[buffer_index++] = arr[second++];
	}
	for (int i = 0; i < buffer_index; ++i) {
		arr[left + i] = global_buffer[i];
	}
}