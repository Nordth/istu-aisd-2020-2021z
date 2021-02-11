// Practice Work №1 nomber 2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

void Reverse(int* OriginalArray, int* SizeArray);
void OutputArray(int* OriginalArray, int* SizeArray);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;
    int SizeArray = 10;
    int OriginalArray[10] = {
        8, 5, 9, 2, 3, 6, 10, 7, 6, 2
    };
    Reverse(OriginalArray, &SizeArray);
    OutputArray(OriginalArray, &SizeArray);
    //std::cout << "Hello World!\n";
}


void Reverse(int* OriginalArray, int* SizeArray) {
    int t,i = 0;
    while (i < *SizeArray / 2) {
        t = OriginalArray[i];
        OriginalArray[i] = OriginalArray[*SizeArray - i - 1];
        OriginalArray[*SizeArray - i - 1] = t;
        i++;
    }
}

void OutputArray(int* OriginalArray, int* SizeArray) {
     
    for (int i = 0;i < *SizeArray;i++) {
        std::cout << OriginalArray[i] << ' ';
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
