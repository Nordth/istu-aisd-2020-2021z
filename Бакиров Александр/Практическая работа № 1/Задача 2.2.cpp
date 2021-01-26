
#include <iostream>
#define N 10
using namespace std;

int main()
{
	int arr[N] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < N / 2; i++)
	{
		int t = arr[i];
		arr[i] = arr[N - i - 1];
		arr[N - i - 1] = t;
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
}