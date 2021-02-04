//������������ ������ �1, ������� 3, ������� ����������
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void QuickSort(int* arr, int left, int right)
{
    int pivot = arr[(left+right) / 2];
    int l = left;
    int r = right;
    int buffer = 0;

    while (r >= l)
    {
        while (arr[l] < pivot) l++;
        while (arr[r] > pivot) r--;

        if (l <= r)
        {
            if (arr[l] > arr[r])
            {
                buffer = arr[l];
                arr[l] = arr[r];
                arr[r] = buffer;
            }
            l++; r--;
        }
    }
    if (left < r) QuickSort(arr, left, r);
    if (l < right) QuickSort(arr, l, right);
}

int main()
{
    //���������� ������� ���������� ������� � ����� ������� �� �����
    const int sizeMass = 20;
    int massDigits[sizeMass] = {};

    srand(time(NULL));
    for (int i = 0; i < sizeMass; i++)
    {
        massDigits[i] = rand() % 51;
        cout << massDigits[i] << " ";
    }
    cout << endl;

    //����� ������� ����������
    QuickSort(massDigits, 0, sizeMass - 1);

    //����� ������� ����� ����������
    for (int i = 0; i < sizeMass; i++) cout << massDigits[i] << " ";
    return 0;
}
