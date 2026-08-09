#include <iostream>
#include <stack>
using namespace std;

// Push a value at the bottom of the stack
void pushAtBottom(stack<int>& s, int val) {

    // Base case:
    // If stack is empty, push the value.
    // This becomes the bottom element.
    if (s.empty()) {
        s.push(val);
        return;
    }

    // Store the top element
    int temp = s.top();

    // Remove the top element
    s.pop();

    // Recursively push val at the bottom
    pushAtBottom(s, val);

    // Put the removed element back
    s.push(temp);
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    /*
    Stack before:

    Top
     ↓
     1
     2
     3
    */

    pushAtBottom(s, 4);

    /*
    Stack after:

    Top
     ↓
     1
     2
     3
     4   <- bottom
    */

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

//n pops + n pushes = 2n so 0(n) time complexity
// 0(n) space complexity for recursion stack