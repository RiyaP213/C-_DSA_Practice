#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void CountSort(int arr[], int n) {
    int freq[1000] = {0};

    int minval = INT_MAX, maxVal = INT_MIN;

    for(int i = 0; i < n; i++) {
        minval = min(minval, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    // Count frequency
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Rebuild sorted array
    int j = 0;

    for(int i = minval; i <= maxVal; i++) {
        while(freq[i] > 0) {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}

int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    int n = 8;

    CountSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}