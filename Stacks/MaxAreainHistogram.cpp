#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int maxAreaHistogram(vector<int> heights) {
    int n = heights.size();

    // nsl[i] = index of nearest smaller bar on the left
    // nsr[i] = index of nearest smaller bar on the right
    vector<int> nsl(n);
    vector<int> nsr(n);

    stack<int> s; // stores indices

    // ========================================================
    // FIND NEAREST SMALLER ON LEFT
    // ========================================================

    nsl[0] = -1;
    s.push(0);

    for (int i = 1; i < n; i++) {
        int curr = heights[i];

        // Remove bars greater than or equal to current bar
        while (!s.empty() && curr <= heights[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            nsl[i] = -1;
        }
        else {
            nsl[i] = s.top();
        }

        // Push index, not height
        s.push(i);
    }

    // Clear stack before using it again
    while (!s.empty()) {
        s.pop();
    }

    // ========================================================
    // FIND NEAREST SMALLER ON RIGHT
    // ========================================================

    nsr[n - 1] = n;
    s.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        int curr = heights[i];

        // Remove bars greater than or equal to current bar
        while (!s.empty() && curr <= heights[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            nsr[i] = n;
        }
        else {
            nsr[i] = s.top();
        }

        // Push index, not height
        s.push(i);
    }

    // ========================================================
    // CALCULATE AREA FOR EVERY BAR
    // ========================================================

    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int height = heights[i];

        int width = nsr[i] - nsl[i] - 1;

        int area = height * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Maximum area: "
         << maxAreaHistogram(heights)
         << "\n";

    return 0;
}