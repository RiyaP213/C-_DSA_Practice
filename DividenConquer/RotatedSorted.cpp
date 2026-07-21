#include <iostream>
using namespace std;

int search(int arr[], int si, int ei, int tar) {
    if (si > ei) {
        return -1;
    }

    int mid = si + (ei - si) / 2;

    if (arr[mid] == tar) {
        return mid;
    }

    // Left half is sorted (L1)
    if (arr[si] <= arr[mid]) {

        if (arr[si] <= tar && tar <= arr[mid]) {
            // Search left half
            return search(arr, si, mid - 1, tar);
        } else {
            // Search right half
            return search(arr, mid + 1, ei, tar);
        }
    }

    // Right half is sorted (L2)
    else {

        if (arr[mid] <= tar && tar <= arr[ei]) {
            // Search right half
            return search(arr, mid + 1, ei, tar);
        } else {
            // Search left half
            return search(arr, si, mid - 1, tar);
        }
    }
}

int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;
    int target = 0;

    int idx = search(arr, 0, n - 1, target);

    cout << idx << endl;

    return 0;
}