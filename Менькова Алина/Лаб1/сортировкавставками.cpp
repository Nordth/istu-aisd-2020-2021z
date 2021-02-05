//Вариант 3, сортировка вставками
#include <iostream>
#include <string>
int main()
{
	int j, n = 0, i;
	int m[8] = { 8, 5, 2,7, 4, 6, 1, 3 };
	for (j = 1; j != 6; j++) {
		n = m[j];
		i = j - 1;
		while (i != -1 && n < m[i]) {
			m[i + 1] = m[i];
			i--;
		}
		m[i + 1] = n;
	}
	std::cout << "array: " << m[0];
	for (int i = 1; i != 8; i++) { std::cout << ", " << m[i]; }
}