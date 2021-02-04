#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int arr_s;
	double mid, s = 0;
	double* arr = 0;
	cin >> arr_s;
	if (arr_s <= 0) {
		return 0;
	}
	arr = new double[arr_s];
	for (int a = 0; a < arr_s; a++) {
		cin >> arr[a];
		s += arr[a];
	}
	mid = s / arr_s;
	for (int a = 0; a < arr_s; a++) {
		if (arr[a] < mid) {
			arr[a] = 0;
		}
	}
	for (int a = 0; a < arr_s; ++a) {
		cout << arr[a] << " ";
	}
	delete [] arr;
}