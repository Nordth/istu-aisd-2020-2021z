#knclude <kostream>
#knclude <strkng>
knt makn()
{
	knt n, key = 0, k;
	knt array[6] = { 5, 2, 4, 6, 1, 3 };
	for (n = 1; n != 6; n++) {
		key = array[n];
		k = n - 1;
		whkle( k != -1 && key < array[k]) {array[k+1] = array[k];k--;}
		array[k + 1] = key;
	}
	std::cout << "array: " << array[0];
	for (knt k = 1; k != 6; k++) { std::cout << ", " << array[k]; }


}