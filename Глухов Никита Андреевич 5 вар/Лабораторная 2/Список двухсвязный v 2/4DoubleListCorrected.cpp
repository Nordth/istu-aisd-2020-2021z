// 4DoubleList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

// Структура двусвязного списка.
struct DoubleList {
    int data;
    DoubleList* next;
    DoubleList* prev;
};
// Шапка для вывода меню 
void Hat();
// Вывод элементов списка.
void Output(DoubleList* begin);
// Добавление элемента в список.(элементы добавляются в конец)
void Input(DoubleList** begin);
//Вывод элемента по индексу
void IndexElementOutput(DoubleList** begin);
// Добавление элемента перед заданным индексом.
void CopyElementFrontIndex(DoubleList** begin);
// Удаление элемента по значению 
void DeletingElementbyValue(DoubleList** begin);
// Очистака списка.
void DeleteList(DoubleList** begin);

using namespace std;

int main()
{
    byte InputStat;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoubleList* Begin = NULL; // Начало списка
    DoubleList* End = NULL; // Конец списка
    // Заполнение значениями
    for (;;) {
        Hat();
        cin >> InputStat;
        switch (InputStat) {
        case '0':
            // Выход, удаление списка.
            DeleteList(&Begin);
            break;
        case '1':
            // Добавление элемента в список.(элементы добавляются в конец)
            Input(&Begin);
            break;
        case '2':
            //Вывод элемента по индексу
            IndexElementOutput(&Begin);
            break;
        case '3':
            // Добавление элемента перед заданным индексом.
            CopyElementFrontIndex(&Begin);
            break;
        case '4':
            // Удаление элемента по значению.
            DeletingElementbyValue(&Begin);
            break;
        case '5':
            // Вывод списка. 
            Output(Begin);
            break;
        default:
            break;
        }
        if (InputStat == '0') break;
    }
}
// Очистака списка.
void DeleteList(DoubleList** begin) {
    cout << "Очистка списка \nВыход...";
    DoubleList* Step = *begin;
    while (Step != NULL) {
        DoubleList* Delete;
        Delete = Step;
        Step = Step->next;
        delete Delete;
    }
}
// Удаление элемента по значению 
void DeletingElementbyValue(DoubleList** begin) {
    int inputelem; DoubleList* Step = *begin;
    cout << "Для выхода в предыдущее меню введите 0\n";
    for (;;) {
        // Проверяем существует ли вообще список. 
        if (*begin == NULL) {
            cout << "Внимание: Список пуст.\n";
            break;
        }
        cout << "Введите значение:\n";
        cin >> inputelem;
        if (inputelem == 0) break;
        // Удаление элемента происходит после поиска первого вхождения элемента. 
        while (Step->data != inputelem) {
            Step = Step->next;
            if (Step == NULL) {
                cout << "Внимание: Требуемого элемента в списке нет. \n";
                break;
            }
        }
        // 
        if (Step == NULL) {
            Step = *begin;
            continue;
        }
        // Тут надо выполнить очистку структуры DoubleList, требуемого элемента и связать адреса.
        DoubleList* Delete;
        DoubleList* Delete2;
        Delete = Step->next;
        Step = Step->prev;
        Delete->prev = Step;
        Delete2 = Step->next;
        Step->next = Delete;
        // Delete2 это теперь тот элемент который надо удалить. Удаление. далее.
        delete Delete2;
        Step = *begin;
    }
}
// Добавление элемента перед заданным индексом.
void CopyElementFrontIndex(DoubleList** begin) {
    int inputindex, inputelem, i = 0; DoubleList* Step = *begin;
    cout << "Для выхода в предыдущее меню введите 0\n";
    for (;;) {
        // Проверяем существует ли вообще список. 
        if (*begin == NULL) {
            cout << "Внимание: Список пуст.\n";

            break;
        }
        cout << "Введите значение:\n";
        cin >> inputelem;
        cout << "Введите индекс:\n";
        cin >> inputindex;
        if (inputindex == 0) break;
        //Блок вставки элемента перед заданным индексом.
        while (i < inputindex) {
            Step = Step->next;
            if (Step == NULL) {
                cout << "Внимание: Выход за пределы списка.\n";
                break;

            }
            i++;
        } i = 0;
        if (Step == NULL) {
            Step = *begin;
            continue;
        }
        // Инициализируем и добавляем новый элемент, затем связываем его в списке. 
        DoubleList* Add = new DoubleList;
        Add->data = inputelem;
        Add->prev = Step->prev;
        Add->next = Step;

        Step = Step->prev;
        Step->next = Add;
        Step = Add->next;
        Step->prev = Add;
        // Возвращаем на первый элемент.
        Step = *begin;
        //delete Add;
    }
}

//Вывод элемента по индексу
void IndexElementOutput(DoubleList** begin) {
    int input, i = 0; DoubleList* Step = *begin;
    cout << "Для выхода в предыдущее меню введите 0\n";
    for (;;) {
        // Проверяем существует ли вообще список. 
        if (*begin == NULL) {
            cout << "Внимание: Список пуст.\n";
            break;
        }
        cout << "Введите значение:\n";
        cin >> input;
        if (input == 0) break;
        //Блок поиска элемента по индексу.
        while (i < input) {
            Step = Step->next;
            if (Step == NULL) {
                cout << "Внимание: Выход за пределы списка.\n";
                break;

            }
            i++;
        } i = 0;
        if (Step == NULL) {
            Step = *begin;
            continue;
        }
        cout << Step->data;
        Step = *begin;

    }
}



void Input(DoubleList** begin) {
    static DoubleList* Last; int input;
    cout << "Для выхода в предыдущее меню введите 0\n";
    for (;;) {
        cout << "Введите значение:\n";
        cin >> input;
        if (input == 0) break;
        // Если лист еще пустой, то begin будет пуст.
        if (*begin == NULL) {
            DoubleList* Step = new DoubleList;
            Step->data = input;
            Step->prev = NULL;
            Step->next = NULL;
            *begin = Step;
            Last = Step;
        }
        else {
            DoubleList* Step = new DoubleList;
            Step->data = input;
            Last->next = Step;
            Step->prev = Last;
            Step->next = NULL;
            Last = Step;
            
        }
    }
}

void Output(DoubleList* begin) {
    DoubleList* output = begin;
    cout << "Вывод элементов\n";
    while (output != NULL) {
        cout << output->data << ' ';
        output = output->next;
    }
}

void Hat() {
    cout << "\nДанная программа создает список. Прежде чем\n";
    cout << "выполнять операций с данными, заполните список данными\n";
    cout << "Выберите пункт в меню\n";
    cout << "0. Выход/удалить список.\n";
    cout << "1. Добавить элемент в конец списка.\n";
    cout << "2. Получение значения элемента по индексу.\n";
    cout << "3. Вставка элемента перед заданным индексом.\n";
    cout << "4. Удаление элемента по значению.\n";
    cout << "5. Вывод списка.\n";
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
