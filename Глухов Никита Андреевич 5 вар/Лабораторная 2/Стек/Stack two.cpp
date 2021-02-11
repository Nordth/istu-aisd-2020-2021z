// Stack two.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

//Добавить элемент в стек. 
void Push(int* Array,int* Size, int* Value, int* last);
// Больше стека
void MoreStack(int* Array, int* Size);
// Вывод стека.
void Print(int* Array, int* Size);
// Инициализация массива.
void Initialisation(int* Array, int* Size, int* last);
// Шапка
void Hat();
// Извлечение элемента 
void DeleteElement(int* Array, int* Size, int* last);
// Удалеине стека
void DeleteStack(int* Array);
// Клонирование стека.
int* CloneStack(int* Array, int* Size);


using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int Size = 4; int* OriginalArray = new int[Size]; int LastElement = 0; int Value = 0; byte InputStat;
    for (;;) {
        Hat();
        cin >> InputStat;
        switch (InputStat) {
        case '0':
            cout << "\nОсвобождение памяти\n";
            DeleteStack(OriginalArray);
            break;
        case '1':
            Initialisation(OriginalArray, &Size, &LastElement);
            break;
        case '2':
            cout << "Введите элемент\n";
            cin >> Value;
            Push(OriginalArray, &Size, &Value, &LastElement);
            break;
        case '3':
            Print(OriginalArray, &Size);
            break;
        case '4':
            DeleteElement(OriginalArray, &Size,&LastElement);
            break;
        case '5':
            Print(OriginalArray, &Size);
            break;
        default:
            break;
        }
        if (InputStat == '0') break;
    }
}
int* CloneStack(int* Array, int* Size) {
    int* CloneStack = new int[*Size]; int i = 0;
    for (; i < *Size; i++) {
        CloneStack[i] = Array[i];
    }
    cout << "\nCтэк клонирован";
    return CloneStack;
}

void DeleteStack(int* Array) { delete Array; }

void DeleteElement(int* Array, int* Size, int* last) {
    /*if (Array == nullptr) {
        cout << "\nСписок пуст...";
            return;
    }*/
    /*if (*last == -1 && Array[0] < 0) {
        cout << "\nСписок пуст...";
            return;
    }*/
    cout << "\nИзвлечь элемент:" << Array[*last-1];
    Array[*last] = NULL;
    *last -= 1;
}

void Initialisation(int* Array, int* Size, int* last) {
    //MoreStack(Array, Size);
    int i = 0;
    for (; i < *Size;i++) Array[i] = 0;
    *last = 0;
}

void Push(int* Array, int* Size, int* Value, int* last) {
    if ((*last+1) > *Size) {
        MoreStack(Array, Size);
    }
    cout << "Добавлили элемент: " << *Value;
    Array[*last] = *Value;
    *last += 1;
    

}
void MoreStack(int* Array, int* Size) {
    int* Step = new int[*Size * 2];
    int i = 0;
    for (; i < *Size;i++) {
        Step[i] = Array[i];
    }
    Array = Step;
    *Size = *Size * 2;
    delete Step;
}

void Print(int* Array, int* Size) {
    cout << '\n';
    int i = 0;
    for (; i < *Size;i++) cout << ' ' << Array[i];
}
void Hat() {
    cout << "\n Данная программа создает эмуляцию стека: Последний вошел, первый вышел.\n";
    cout << "Выберите пункт в меню:";
    cout << "\n0. Выход";
    cout << "\n1. Инициализация";
    cout << "\n2. Добавить элемент";
    cout << "\n3. Вывести элементы";
    cout << "\n4. Удалить элемент";
    cout << "\n";
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
