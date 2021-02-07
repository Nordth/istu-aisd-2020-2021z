#include <iostream>
#include <string>
int main()
{
	int n, key = 0, k;
	int array[6] = { 5, 2, 4, 6, 1, 3 };
	for (n = 1; n != 6; n++) {
		key = array[n];
		k = n - 1;
		while( k != -1 && key < array[k]) {array[k+1] = array[k];k--;}
		array[k + 1] = key;
	}
	std::cout << "array: " << array[0];
	for (int v = 1; v != 6; v++) { std::cout << ", " << array[k]; }


}
