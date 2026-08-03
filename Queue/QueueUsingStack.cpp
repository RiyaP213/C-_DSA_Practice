#include <iostream>
#include <stack>
using namespace std;

// Queue using two stacks
class Queue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    // Add element to the rear of the queue
    void push(int data) {

        // Step 1:
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2:
        // Push new element into s1
        s1.push(data);

        // Step 3:
        // Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Remove element from the front
    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        s1.pop();
    }

    // Return front element
    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return s1.top();
    }

    // Check whether queue is empty
    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";

    return 0;
}
/* push(data)

1. Move s1 → s2
2. Push new data into s1
3. Move s2 → s1
 
complexity:
push()  → O(n)
pop()   → O(1)
front() → O(1)
empty() → O(1)
*/