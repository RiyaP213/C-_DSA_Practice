#include <iostream>
#include <algorithm> // needed for reverse()
using namespace std;

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
        Reverse array using built-in reverse() function.

        Syntax:
        reverse(start, end);

        For arrays:
        reverse(arr, arr + size);

        Meaning:
        - arr points to the first element.
        - arr + size points just after the last element.
        - reverse() reverses everything from arr to arr + size.

        Important:
        - reverse() modifies the original array.
        - It does not create a new reversed array.

        Time Complexity: O(n)
        - It still needs to visit/swap the elements.

        Space Complexity: O(1)
        - It reverses in-place.
        - No extra array is created.
    */

    reverse(arr, arr + size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}