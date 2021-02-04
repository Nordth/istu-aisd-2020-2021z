//������������ ������ �1, ������ 3, ���������� ���������

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void InsertSort (int* arr, const int lengthArr)
{
    int buffer = 0;
    int i = 0;
    for (int j = 1; j < lengthArr; j++)
    {
        buffer = arr[j];
        i = j;
        while (arr[i] < arr[i-1] && i-1 >= 0)
        {
            arr[i] = arr[i-1];
            arr[i-1] = buffer;
            i--;
        }
    }
}

int main()
{
    const int sizeMass = 20;
    int massDigits[sizeMass] = {};

    srand(time(NULL));
    for (int i = 0; i < sizeMass; i++)
    {
        massDigits[i] = rand() % 51;
        cout << massDigits[i] << " ";
    }
    cout << endl;

    InsertSort(massDigits, sizeMass);

    for (int i = 0; i < sizeMass; i++)
    {
        cout << massDigits[i] << " ";
    }
    return 0;
}
