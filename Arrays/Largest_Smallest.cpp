#include <iostream>
#include <climits>
using namespace std;

pair<int, int> LargestSmallest(int arr[], int size) {
    int largest = INT_MIN;
    int smallest = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }

        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    return {largest, smallest};
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    pair<int, int> ans = LargestSmallest(arr, size);

    cout << "Largest: " << ans.first << endl;
    cout << "Smallest: " << ans.second << endl;

    return 0;
}