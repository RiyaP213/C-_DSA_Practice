#include <iostream>
#include <algorithm> // needed for swap()
using namespace std;

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    /*
        Reverse array using two-pointer method and swap().

        Idea:
        - start points to the first element.
        - end points to the last element.
        - Swap arr[start] and arr[end].
        - Move start forward.
        - Move end backward.
        - Stop when start and end meet or cross.

        Why this method is good:
        - It reverses the same array directly.
        - We do not create another array.
        - swap() makes the code shorter than using temp manually.

        Time Complexity: O(n)
        - The loop runs about n/2 times.
        - Big O ignores constants, so O(n/2) becomes O(n).

        Space Complexity: O(1)
        - We only use start and end.
        - swap() does not create a full extra array.
    */

    int start = 0;      // First index
    int end = n - 1;    // Last index

    while (start < end) {
        swap(arr[start], arr[end]); // Swap elements at start and end

        start++; // Move start forward
        end--;   // Move end backward
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}