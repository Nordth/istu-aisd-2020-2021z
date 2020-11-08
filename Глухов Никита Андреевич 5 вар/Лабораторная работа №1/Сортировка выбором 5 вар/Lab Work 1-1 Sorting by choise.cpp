// Lab Work 1-1 Sorting by choise.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

//#define SizeArray sizeof(OriginalArray)/sizeof(int)

using namespace std;
void SortingByChoise(int* Array, int* SizeArgument);
void OutputArray(int* Array, int* SizeArgument);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int OriginalArray[10] = { 5, 4, 4, 10, 3, 3, 10, 4, 2, 5 };
    int SizeArray = sizeof(OriginalArray) / sizeof(int);
    SortingByChoise(OriginalArray, &SizeArray);
    OutputArray(OriginalArray, &SizeArray);

    cout << "Hello World!\n";
}

void SortingByChoise(int* Array, int* SizeArgument) {
    int i = 0, k = 0, SortAr = 0, Min = 0, SwapIndex = 0;
    Min = Array[k];
    for (;i < *SizeArgument;i++) {
        //Array[i];
        k = i;
        for (;k < *SizeArgument;k++) {
            //Min = Array[k];
            if (Min > Array[k]) Min = Array[k], SwapIndex = k;
            //else 
        }
        Array[SwapIndex] = Array[i];
        Array[i] = Min;

        //k = 0;
        Min = Array[i + 1];
    }
}

void OutputArray(int* Array, int* SizeArgument) {
    int i = 0;
    for (;i < *SizeArgument;i++) {
        cout << Array[i] << "\n";
    }
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
