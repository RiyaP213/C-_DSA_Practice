#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreater(vector<int> arr, vector<int>& ans) {
    stack<int> s;

    // Start from the last element
    int idx = arr.size() - 1;

    // Last element has nothing on its right
    ans[idx] = -1;

    // Push last element into stack
    s.push(arr[idx]);

    // Move from right to left
    for (idx = idx - 1; idx >= 0; idx--) {
        int curr = arr[idx];

        // Remove all elements smaller than or equal to curr
        while (!s.empty() && curr >= s.top()) {
            s.pop();
        }

        // No greater element exists on the right
        if (s.empty()) {
            ans[idx] = -1;
        }
        else {
            // Stack top is the next greater element
            ans[idx] = s.top();
        }

        // Current element may help elements on its left
        s.push(curr);
    }
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans(arr.size());

    nextGreater(arr, ans);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}