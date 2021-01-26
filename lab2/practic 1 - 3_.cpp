#include <iostream>

int RecurSumma(int* arr, int i = 0) {
    if (i == 10) { return 0; }
    else { return arr[i] + RecurSumma(arr, i + 1); }
}

int main() {
    int arr[10] = { 1, 3, 6, 12, 17, 18, 20, 28, 32, 53 };
    std::cout << RecurSumma(arr);
}