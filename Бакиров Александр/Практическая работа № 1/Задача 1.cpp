
#include <iostream>
using namespace std;
void main()
{	
	const int N = 10;
	float b[N] = { 1.1 , 2.9 , 3 , 4.6 , 5 , 6.8 , 7.5 , 8 , 9.2 , 10.1 }, summ = 0, avrg;
	
	for (int i = 0; i < 10; i++) 
	{
		summ += b[i];
	}
	avrg = summ / N;
	for (int i = 0; i < N; i++)
	{
		if (b[i] < avrg)
			b[i] = 0;

		cout << b[i] << " ";
	}
	
}

