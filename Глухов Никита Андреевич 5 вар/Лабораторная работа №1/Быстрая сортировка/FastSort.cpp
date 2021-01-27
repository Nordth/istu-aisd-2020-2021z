// FastSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

void FastSort(int* Array, int first, int last); // Функция для соритровки. 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int mid, last, first, SizeArr = 10, i = 0;
    int *OriginalArr = new int [SizeArr];
    OriginalArr[0] = 4;
    OriginalArr[1] = 7;
    OriginalArr[2] = 10;
    OriginalArr[3] = 6;
    OriginalArr[4] = 8;
    OriginalArr[5] = 1;
    OriginalArr[6] = 5;
    OriginalArr[7] = 2;
    OriginalArr[8] = 10;
    OriginalArr[9] = 8;
    cout << "Исходный массив:\n";
    for (; i < SizeArr; i++) {
        cout << OriginalArr[i] << ' ';
    }i = 0;
    FastSort(OriginalArr, 0, SizeArr - 1);
    cout << "\nОтсортированный массив:\n";
    for (; i < SizeArr; i++) {
        cout << OriginalArr[i] << ' ';
    }
}

void FastSort(int* Array, int first, int last) {
    int swap,size = last,pred = first,mid = Array[(first + last) / 2];

    do {
        while (Array[first] < mid) first++;
        while (Array[last] > mid) last--;

        if (first <= last) {
            swap = Array[first]; Array[first] = Array[last]; Array[last] = swap;
            first++; last--;
        }
    } while (first <= last);
    if(last > pred) FastSort(Array, pred, last);
    if(first < size) FastSort(Array, first, size);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
