#include <iostream>
void speedsort(int* array, int first, int last)
{
	int sid, count;
	int myf = first, myl = last;
	sid = array[(first + last) / 2];
	
	while (myf < myl){
		while (array[myf] < sid) { myf++; }
		while (array[myl] > sid) { myl--; }
		if (myf <= myl) {
			count = array[myf];
			array[myf] = array[myl];
			array[myl] = count;
			myf++; myl--;
		}
	}
	if (first < myl) speedsort(array, first, myl);
	if (myf < last) speedsort(array, myf, last);
}

void main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int first = 0, last = 6 - 1;
	speedsort(arr, first, last);
	std::cout << "array: " << arr[0];
	for (int i = 1; i != 6; i++) { std::cout << ", " << arr[i]; }
}