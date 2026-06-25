#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Ascending Order
    sort(arr, arr + n);

    cout << "Ascending Order: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Descending Order
    sort(arr, arr + n, greater<int>());

    cout << "Descending Order: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}