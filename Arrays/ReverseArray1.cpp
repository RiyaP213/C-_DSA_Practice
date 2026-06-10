#include <iostream>
using namespace std;

// Time complexity: O(n)

int main() {
    int size;
    int array[] = {5, 4, 3, 2, 1};

    size = sizeof(array) / sizeof(array[0]);

    int reverse[size];

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        int j = size - i - 1;
        reverse[i] = array[j];

        cout << reverse[i] << " ";
    }

    cout << endl;

    return 0;
}