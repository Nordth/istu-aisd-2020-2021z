#include <iostream>

using namespace std;

int main(){
	const int N = 10;
	int A[N];

	int num=0;
	int averages=0;
	for (int i=0; i<N; i++){
		cin >> A[i];
		averages += A[i];
		num++;
	}
	averages /= num;

	for (int i=0; i<N; i++){
		if (A[i] < averages) A[i] = 0;
    cout << A[i] << " ";
	}

	system("PAUSE");
	return 0;
}