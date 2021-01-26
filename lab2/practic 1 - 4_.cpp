#include <iostream>
#include <string>
int main()
{

	int num[14] = { 1, 5, 7, 9, 4, 5, 5, 1, 2, 5, 4, 5, 8, 5};
	int j = 0, counter[10] = { 0 };
	for (int i = 0; i != 14; i++) {counter[num[i]]++;}
	for (int i = 0; i != 10; i++) {
		if (counter[i] > 0) {std::cout << "number " << i << " - " << counter[i] << " repetitions" << std::endl;}
	}
	std::cout << "---------------------------------------" << std::endl;
	for (int i = 0; i != 10; i++) {
		while (counter[i] != 0) { num[j] = i; j++; counter[i]--; }
	}
	std::cout << "array: " << num[0];
	for (int i = 1; i != 14; i++) {std::cout << ", " << num[i];}
}