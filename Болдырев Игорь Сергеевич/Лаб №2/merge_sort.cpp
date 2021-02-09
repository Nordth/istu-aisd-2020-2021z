//6 вариант
//сортировка слиянием
#include <iostream>

const int arraySize = 10;
int array[arraySize];
int globalBuffer[arraySize];

void sort(int* array, int lt, int rt);
void mergeArray(int* array, int lt, int m, int rt);

int main() 
{
	std::cout << "Write "<< arraySize << " numbers\n";
	for (int i = 0; i < arraySize; i++) {
		std::cin >> array[i];
	}
	
	sort(array, 0, arraySize - 1);

	std::cout << "Sorted array\n";
	for (int i = 0; i < arraySize; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void sort(int* array, int lt, int rt)
{
	if (rt - lt < 2) {
		if (array[lt] > array[rt]) {
			int tmp = array[lt];
			array[lt] = array[rt];
			array[rt] = tmp;
		}
		return;
	}
	int m = (lt + rt) / 2;
	sort(array, lt, m);
	sort(array, m + 1, rt);
	mergeArray(array, lt, m, rt);
}

void mergeArray(int* array, int lt, int m, int rt)
{
	int index_left = lt;
	int index_right = m + 1;
	int index_buffer = 0;
	while (index_left <= m && index_right <= rt) {
		if (array[index_left] <= array[index_right]) {
			globalBuffer[index_buffer++] = array[index_left++];
		}
		else { 
			globalBuffer[index_buffer++] = array[index_right++];
		}
	}
	for ( ; index_left <= m; index_buffer++, index_left++) {
		globalBuffer[index_buffer] = array[index_left];
	}
	for ( ; index_right <= rt; index_buffer++, index_right++) {
		globalBuffer[index_buffer] = array[index_right];
	}
	for (int i = 0; i < index_buffer; i++) {
		array[lt + i] = globalBuffer[i];
	}
}