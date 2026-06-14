//Kadane's Algorithm- Time complexity is O(n) and space complexity is O(1). This is the most optimized approach to find the maximum subarray sum. 
//It is based on the idea that if the current sum becomes negative, we can reset it to zero because a negative sum will not contribute to a maximum sum in the future.
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[] = {1, 2, -3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = INT_MIN;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        currentSum += arr[i];

        maxSum = max(maxSum, currentSum);

        if(currentSum < 0) {
            currentSum = 0;
        }
    }

    cout << "Maximum Subarray Sum is: " << maxSum << endl;
}