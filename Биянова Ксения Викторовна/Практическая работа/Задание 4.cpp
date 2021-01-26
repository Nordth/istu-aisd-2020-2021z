#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void InsertSort (int* arr, const int lengthArr);

int main()
{
    setlocale(LC_ALL, "rus");
    //Заполнение массива случаными числами от 0 до 9
    const int sizeMass = 20;
    int massDigits[sizeMass] = {};

    srand(time(NULL));
    for (int i = 0; i < sizeMass; i++)
    {
        massDigits[i] = rand() % 10;
    }
    //Нахождение количества повторений каждой цифры
    int massiveSumRepet[10] = {0};

    for (int digit = 0; digit < 10; digit++)
    {
        for (int j = 0; j < sizeMass; j++)
        {
            if (massDigits[j] == digit) massiveSumRepet[digit] += 1;
        }
    }
    //Сортировка получившегося массива
    InsertSort(massiveSumRepet, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << massiveSumRepet[i] << " ";
    }

    return 0;
}

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
