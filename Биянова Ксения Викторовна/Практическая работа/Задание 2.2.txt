#include <iostream>

using namespace std;

int main()
{
    const int n = 10;
    int arr[n] = {1, 85, 34, 5, 19, 45, 62, 7, 44, 10};

    int i = 0, t = 0;
    while (i < (n / 2))
    {
        t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
