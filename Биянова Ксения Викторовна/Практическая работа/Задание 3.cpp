#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Sum (int * massDigits, const int * end)
{
    if (massDigits == end) return 0;
    return (*massDigits) + Sum(massDigits+1, end);
}

int main()
{
    setlocale(LC_ALL, "rus");

    const int sizeMass = 15;
    int massDigits[sizeMass] = {};

    srand(time(NULL));
    for (int i = 0; i < sizeMass; i++)
    {
        massDigits[i] = rand() % 501;
        cout << massDigits[i] << " ";
    }
    cout << endl;

    int sum = Sum(massDigits, massDigits+sizeMass);
    cout << "Сумма элементов массива = " << sum;

    return 0;
}
