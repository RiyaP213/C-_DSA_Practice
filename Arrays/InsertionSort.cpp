#include<iostream>
using namespace std;

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 1; i < n; i++) {

        int curr = arr[i];      // current element to insert
        int prev = i - 1;       // last element in sorted part

        // shift bigger elements right
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // insert current element
        arr[prev + 1] = curr;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}