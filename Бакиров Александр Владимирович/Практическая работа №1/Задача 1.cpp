
#include <iostream>
using namespace std;
void main()
{
	float b[10] = { 1.1 , 2.9 , 3 , 4.6 , 5 , 6.8 , 7.5 , 8 , 9.2 , 10.1 }, summ = 0, avrg;
	
	for (int i = 0; i < 10; i++) 
	{
		summ += b[i];
	}
	avrg = summ / 10;
	for (int i = 0; i < 10; i++)
	{
		if (b[i] < avrg)
			b[i] = 0;

		cout << b[i] << " ";
	}
	
}

