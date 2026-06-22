#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(height[0]);

    int leftMax[n];
    int rightMax[n];

    // leftMax[i] stores the tallest wall from index 0 to i
    leftMax[0] = height[0];

    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // rightMax[i] stores the tallest wall from index i to n-1
    rightMax[n - 1] = height[n - 1];

    for(int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int water = 0;

    // Water at each index depends on the shorter wall
    for(int i = 0; i < n; i++) {
        int waterLevel = min(leftMax[i], rightMax[i]);

        int currentWater = waterLevel - height[i];

        water += currentWater;
    }

    cout << "Trapped Water: " << water << endl;

    return 0;
}