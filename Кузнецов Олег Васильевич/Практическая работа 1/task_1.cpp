#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int arr_size;
	double middle, sum = 0;
	double* arr = 0;
	cin >> arr_size;
	if (arr_size <= 0) {
		return 0;
	}
	arr = new double[arr_size];
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	middle = sum / arr_size;
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] < middle) {
			arr[i] = 0;
		}
	}
	for (int i = 0; i < arr_size; ++i) {
		cout << arr[i] << " ";
	}
	delete [] arr;
}