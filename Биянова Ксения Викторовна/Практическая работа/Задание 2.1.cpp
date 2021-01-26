#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    double numberA = 0;
    cout << "¬ведите первое число: ";
    cin >> numberA;

    char operation = '\0';
    cout << "”кажите операцию: ";
    cin >> operation;

    double numberB = 0;
    cout << "¬ведите второе число: ";
    cin >> numberB;

    double result = 0;
    if (operation == '+')
        result = numberA + numberB;
    else if (operation == '-')
        result = numberA - numberB;
    else if (operation == '*')
        result = numberA * numberB;
    else if (operation == '/')
        result = numberA / numberB;

    cout << result;

    return 0;
}
