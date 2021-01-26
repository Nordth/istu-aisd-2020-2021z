#include <iostream>
int main()
{

	int num[8] = { 1, 5, 8, 12, 14, 18, 19, 31 };
	int sum = 0;

	for (int i = 0; i != 8; i++) { sum += num[i]; }
	int average = sum / 8;

	for (int i = 0; i != 8; i++) {
		if (num[i] < average) { num[i] = 0; }
	}

	for (int i = 0; i != 8; i++) {
		std::cout << num[i] << std::endl;
	}

	std::cin >> sum;
}