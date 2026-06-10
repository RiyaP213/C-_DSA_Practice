#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
        We reverse the array in-place.

        In-place means:
        - We do not create another array.
        - We swap elements inside the same array.

        Idea:
        - Swap first element with last element.
        - Swap second element with second-last element.
        - Continue only till the middle.

        Example:
        {5, 4, 3, 2, 1}

        i = 0:
        swap arr[0] and arr[4]
        {1, 4, 3, 2, 5}

        i = 1:
        swap arr[1] and arr[3]
        {1, 2, 3, 4, 5}

        The middle element does not need to move.

        Time Complexity: O(n)
        - The loop runs n/2 times.
        - In Big O, we ignore constants, so O(n/2) becomes O(n).

        Space Complexity: O(1)
        - We only use one extra variable: temp.
        - We do not create another array.
    */
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];                    // Store left element safely
        arr[i] = arr[size - i - 1];           // Put right element into left position
        arr[size - i - 1] = temp;             // Put old left element into right position
    }

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}