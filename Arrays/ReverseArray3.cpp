#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
// Time complexity: O(n)- in place reversal of the array
    /*
        Reverse array using two-pointer method.

        Idea:
        - start points to the first element.
        - end points to the last element.
        - Swap arr[start] and arr[end].
        - Move start forward.
        - Move end backward.
        - Stop when start and end meet or cross.

        Why this is good:
        - It reverses the array in-place.
        - In-place means we do not create another array.
        - This saves memory.

        Time Complexity: O(n)
        - The loop runs about n/2 times.
        - In Big O, we ignore constants, so O(n/2) becomes O(n).

        Space Complexity: O(1)
        - We only use three extra variables: start, end, and temp.
    */

    int start = 0;      // First index of the array
    int end = n - 1;    // Last index of the array

    while (start < end) {
        int temp = arr[start];      // Save the left/start value
        arr[start] = arr[end];      // Put the right/end value at the start
        arr[end] = temp;            // Put the saved start value at the end

        start++;    // Move start one step forward
        end--;      // Move end one step backward
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}