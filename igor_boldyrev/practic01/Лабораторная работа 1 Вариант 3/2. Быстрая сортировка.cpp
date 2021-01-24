#include <iostream>
//функция Быстрой сортировки
void speedsort(int* mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(first + last) / 2];
	
	while (f < l){
		while (mas[f] < mid) { f++; }
		while (mas[l] > mid) { l--; }
		if (f <= l) {
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++; l--;
		}
	}
	if (first < l) speedsort(mas, first, l);
	if (f < last) speedsort(mas, f, last);
}

void main()
{
	int mass[6] = { 5, 2, 4, 6, 1, 3 };
	int first = 0, last = 6 - 1;
	speedsort(mass, first, last);
	
	std::cout << "array: " << mass[0];
	for (int i = 1; i != 6; i++) { std::cout << ", " << mass[i]; }
}