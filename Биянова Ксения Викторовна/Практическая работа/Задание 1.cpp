#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    const int sizeMass = 15;
    int massDigits[sizeMass] = {};

    srand(time(NULL));
    for (int i = 0; i < sizeMass; i++)
    {
        massDigits[i] = rand() % 1001;
        cout << massDigits[i] << " ";
    }
    cout << endl;

    double middleMeaning = 0;
    for (int i = 0; i < sizeMass; i++)
            middleMeaning += massDigits[i];

    middleMeaning /= sizeMass;
    cout << "Среднее значение элементов массива = " << middleMeaning << endl;

    for (int i = 0; i < sizeMass; i++)
    {
        if (massDigits[i] < middleMeaning)
                massDigits[i] = 0;
        cout << massDigits[i] << " ";
    }

    return 0;
}
