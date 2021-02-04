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
	for (int x = 0; x < size; ++x) {
		std::cin >> arr[x];
	}
	
	merge_sort(arr, 0, size - 1);

	std::cout << "Sorted array\n";
	for (int x = 0; x < size; ++x) {
		std::cout << arr[x] << " ";
	}
	std::cout << std::endl;
	
	delete [] arr;
	delete [] global_buffer;
}

void merge_sort(int* arr, int left, int right)
{
	if (right - left <= 1) {
		if (arr[left] > arr[right]) {
			int b = arr[left];
			arr[left] = arr[right];
			arr[right] = b;
		}
		return;
	}
	int mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge_array(arr, left, mid, right);
}

void merge_array(int* arr, int left, int middle, int right)
{
	int fir = left;
	int sec = middle + 1;
	int buf_ind = 0;
	while (fir <= middle && sec <= right) {
		if (arr[fir] <= arr[sec]) {
			global_buffer[buf_ind++] = arr[fir++];
		}
		else { //arr[first] > arr[second]
			global_buffer[buf_ind++] = arr[sec++];
		}
	}
	while (fir <= middle) {
		global_buffer[buf_ind++] = arr[fir++];
	}
	while (sec <= right) {
		global_buffer[buf_ind++] = arr[sec++];
	}
	for (int x = 0; x < buf_ind; ++x) {
		arr[left + x] = global_buffer[x];
	}
}