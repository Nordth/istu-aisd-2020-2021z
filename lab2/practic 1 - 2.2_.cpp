#include <iostream>

void reverse(int *arr, int n) {
    int i = 0;
    while (i < n/2) {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
        i++;
    }
}

int main() {
    int arr[10] = { 1, 3, 6, 13, 17, 18, 20, 28, 32, 53 };
    reverse(arr, 10);

    for (int i = 0; i != 10; i++ ) { std::cout << arr[i] << " "; }
    std::cin >> arr[0];
}