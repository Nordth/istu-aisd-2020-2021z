﻿// Practice work №1 nomber 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

//#define ArrSquare ((sizeof(OriginalArray) / sizeof(float))
//Я делал в спешке, чтобы сделать скорее. Дайте мне знать как переделать, я бы мог все по функциям распределить и
//задействовать указатели. Спасибо.
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;

    int SizeArray = 12;
    float OriginalArray[12] = {
        43.08, 5.57, 30.63,
        51.67, 96.28, 18.71,
        86.42, 51.26, 3.15,
        67.82, 8.85, 51.07
    };
    float ArithmeticMean;
    int i = 0;// (sizeof(OriginalArray) / sizeof(float));
    float Amount = 0;
    for (i = 0; i < SizeArray; i++) {
        Amount += OriginalArray[i];
    }
    ArithmeticMean = Amount / SizeArray;
    cout << ArithmeticMean << "\n";
    cout << "Исходный массив\n";
    for (i = 0; i < SizeArray; i++) {
        cout << OriginalArray[i] << "  ";
    }
    for (i = 0; i < SizeArray; i++) {
        if(ArithmeticMean > OriginalArray[i]){
            OriginalArray[i] = 0;
        }
    }
    cout << "Конечный массив\n";
    for (i = 0; i < SizeArray; i++) {
        cout << OriginalArray[i] << "  ";
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
