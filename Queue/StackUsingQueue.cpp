#include <iostream>
#include <queue>
using namespace std;

// Stack implementation using two queues.
//
// Stack follows LIFO:
// Last In, First Out.
//
// We keep the newest element at the front of q1.
// Therefore:
//
// top() = q1.front()
// pop() = q1.pop()

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Push a new element onto the stack.
    //
    // Steps:
    // 1. Move all existing elements from q1 to q2.
    // 2. Push the new element into q1.
    // 3. Move everything from q2 back to q1.
    //
    // This makes the newest element stay at the front of q1.
    void push(int data) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Remove the top element.
    void pop() {
        if (empty()) {
            cout << "Stack is empty\n";
            return;
        }

        q1.pop();
    }

    // Return the top element.
    int top() {
        if (empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        return q1.front();
    }

    // Check whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    // Stack:
    //
    // Top
    //  3
    //  2
    //  1

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";

    return 0;
}

/*
Expected output:

3 2 1


Time complexity:

push()  -> O(n)
pop()   -> O(1)
top()   -> O(1)
empty() -> O(1)
*/