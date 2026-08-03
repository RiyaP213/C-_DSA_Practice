#include <iostream>
#include <stack>
using namespace std;

// Push one value at the bottom of the stack
void pushAtBottom(stack<int>& s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    pushAtBottom(s, val);

    s.push(temp);
}

// Reverse the stack using recursion
void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    // Remove the top element
    int temp = s.top();
    s.pop();

    // Reverse the remaining stack
    reverseStack(s);

    // Put the removed element at the bottom
    pushAtBottom(s, temp);
}

// Copy is passed so the original stack is not changed
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    cout << "Before reversing:\n";
    printStack(s);

    reverseStack(s);

    cout << "After reversing:\n";
    printStack(s);

    return 0;
}