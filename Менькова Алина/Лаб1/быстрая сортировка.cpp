//Вариант 3, быстрая сортировка


#include <iostream>
void speedsort(int* m, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = m[(first + last) / 2];

	while (f < l) {
		while (m[f] < mid) { f++; }
		while (m[l] > mid) { l--; }
		if (f <= l) {
			count = m[f];
			m[f] = m[l];
			m[l] = count;
			f++; l--;
		}
	}
	if (first < l) speedsort(m, first, l);
	if (f < last) speedsort(m, f, last);
}
void main()
{
	int m[8] = {8, 5, 2, 7, 4, 6, 1, 3 };
	int first = 0, last = 8 - 1;
	speedsort(m, first, last);
	std::cout << "array: " << m[0];
	for (int i = 1; i != 8; i++) { std::cout << ", " << m[i]; }
}