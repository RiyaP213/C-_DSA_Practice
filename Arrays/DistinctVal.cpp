#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    bool isDistinct = true;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] == arr[i + 1]) {
            isDistinct = false;
            break;
        }
    }

    if(isDistinct) {
        cout << "Values are distinct";
    } else {
        cout << "Values are not distinct";
    }

    return 0;
}