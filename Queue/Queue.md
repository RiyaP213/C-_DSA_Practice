# Queue

## Definition

A **Queue** is a linear data structure that follows:

> **FIFO — First In, First Out**

The first element inserted is the first element removed.

Example:

```text
Front                     Rear
  ↓                         ↓
[10] [20] [30] [40]
```

- Elements are added from the **rear**.
- Elements are removed from the **front**.

---

# Core Queue Operations

```cpp
push()
```

Adds an element at the rear.

Also called:

```text
enqueue
```

```cpp
pop()
```

Removes an element from the front.

Also called:

```text
dequeue
```

```cpp
front()
```

Returns the first element.

```cpp
back()
```

Returns the last element.

```cpp
empty()
```

Checks whether the queue is empty.

```cpp
size()
```

Returns the number of elements.

---

# Time Complexity

| Operation | Time |
|---|---:|
| `push()` | `O(1)` |
| `pop()` | `O(1)` |
| `front()` | `O(1)` |
| `back()` | `O(1)` |
| `empty()` | `O(1)` |

---

# Queue Using Linked List

For a linked-list queue:

- `head` represents the front.
- `tail` represents the rear.
- Insert from `tail`.
- Remove from `head`.

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = nullptr;
    }

    // Add an element at the rear
    void push(int value) {
        Node* newNode = new Node(value);

        // Empty queue
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // Remove an element from the front
    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        // If the final node was removed,
        // tail must also become nullptr
        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
    }

    // Return the front element
    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return head->data;
    }

    // Return the rear element
    int back() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return tail->data;
    }

    bool empty() {
        return head == nullptr;
    }

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";

    cout << "Queue elements:\n";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";

    return 0;
}
```

## Output

```text
Front: 1
Back: 4
Queue elements:
1 2 3 4
```

## Linked-List Queue Mind Map

```text
push:

create new node

if queue is empty:
    head = tail = newNode

otherwise:
    tail->next = newNode
    tail = newNode
```

```text
pop:

save head in temp

head = head->next

if head becomes nullptr:
    tail = nullptr

delete temp
```

```text
front:

return head->data
```

```text
back:

return tail->data
```

---

# Circular Queue

A circular queue also follows FIFO.

The difference is in how an array-based queue uses memory.

## Problem with a Simple Array Queue

Suppose the array is:

```text
[1, 2, 3, 4]
```

After removing `1` and `2`:

```text
[_, _, 3, 4]
```

There are free spaces at the front, but the rear has already reached the end of the array.

A simple queue may not reuse those spaces.

## Circular Queue Solution

A circular queue treats the array like a circle.

After reaching the final index, the rear moves back to index `0`.

```text
0 → 1 → 2 → 3
↑           ↓
└───────────┘
```

The wrapping formula is:

```cpp
nextIndex = (currentIndex + 1) % capacity;
```

For capacity `4`:

```text
0 → 1 → 2 → 3 → 0 → 1 ...
```

## Common Uses

- CPU scheduling
- Circular buffers
- Producer-consumer systems
- Network buffers
- Keyboard buffers
- Streaming data

---

# Circular Queue Implementation

```cpp
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int capacity;
    int currentSize;
    int frontIndex;
    int rearIndex;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;

        arr = new int[capacity];

        currentSize = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    // Add element at rear
    void push(int value) {
        if (full()) {
            cout << "Queue is full\n";
            return;
        }

        // Move rear forward and wrap around if needed
        rearIndex = (rearIndex + 1) % capacity;

        arr[rearIndex] = value;
        currentSize++;
    }

    // Remove element from front
    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Move front forward and wrap around if needed
        frontIndex = (frontIndex + 1) % capacity;

        currentSize--;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[frontIndex];
    }

    int back() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[rearIndex];
    }

    bool empty() {
        return currentSize == 0;
    }

    bool full() {
        return currentSize == capacity;
    }

    int size() {
        return currentSize;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";

    q.pop();
    q.pop();

    // Empty positions now exist at the front.
    // Circular queue reuses them.
    q.push(5);
    q.push(6);

    cout << "Queue elements:\n";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";

    return 0;
}
```

## Output

```text
Front: 1
Back: 4
Queue elements:
3 4 5 6
```

## Circular Queue Mind Map

```text
Constructor:

capacity = given size
currentSize = 0
frontIndex = 0
rearIndex = -1
```

```text
push:

if currentSize == capacity:
    queue is full

rearIndex = (rearIndex + 1) % capacity

arr[rearIndex] = value

currentSize++
```

```text
pop:

if currentSize == 0:
    queue is empty

frontIndex = (frontIndex + 1) % capacity

currentSize--
```

```text
front:

return arr[frontIndex]
```

```text
back:

return arr[rearIndex]
```

---

# STL Queue

C++ provides a built-in queue in the `<queue>` library.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";
    cout << "Size: " << q.size() << "\n";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";

    return 0;
}
```

## Output

```text
Front: 1
Back: 4
Size: 4
1 2 3 4
```

## STL Queue Functions

```cpp
q.push(value);
```

Add an element at the rear.

```cpp
q.pop();
```

Remove the front element.

```cpp
q.front();
```

Return the first element.

```cpp
q.back();
```

Return the last element.

```cpp
q.empty();
```

Returns `true` if the queue is empty.

```cpp
q.size();
```

Returns the number of elements.

> `q.pop()` does not return the removed value.  
> Read `q.front()` before calling `q.pop()`.

---

# Deque

A **Deque** means:

> **Double-Ended Queue**

It allows insertion and deletion from both ends.

This is different from a normal queue.

## Core Deque Operations

```cpp
push_front()
```

Insert at the front.

```cpp
push_back()
```

Insert at the back.

```cpp
pop_front()
```

Remove from the front.

```cpp
pop_back()
```

Remove from the back.

```cpp
front()
```

Return the front element.

```cpp
back()
```

Return the back element.

```cpp
empty()
```

Check whether the deque is empty.

```cpp
size()
```

Return the number of elements.

Yes, a deque has an `empty()` function.

---

# STL Deque

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert at front
    dq.push_front(2);
    dq.push_front(1);

    // Insert at back
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(10);

    /*
    Deque:

    1 2 3 4 10
    */

    cout << "Front: " << dq.front() << "\n";
    cout << "Back: " << dq.back() << "\n";
    cout << "Size: " << dq.size() << "\n";

    cout << "Deque elements:\n";

    for (int value : dq) {
        cout << value << " ";
    }

    cout << "\n";

    dq.pop_front();
    dq.pop_back();

    /*
    After removing front and back:

    2 3 4
    */

    cout << "After pop_front and pop_back:\n";

    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << "\n";

    return 0;
}
```

## Output

```text
Front: 1
Back: 10
Size: 5
Deque elements:
1 2 3 4 10
After pop_front and pop_back:
2 3 4
```

---

# STL Deque Functions

```cpp
dq.push_front(value);
```

Insert at front.

```cpp
dq.push_back(value);
```

Insert at back.

```cpp
dq.pop_front();
```

Remove from front.

```cpp
dq.pop_back();
```

Remove from back.

```cpp
dq.front();
```

Return front element.

```cpp
dq.back();
```

Return back element.

```cpp
dq.empty();
```

Returns `true` when empty.

```cpp
dq.size();
```

Returns number of elements.

```cpp
dq[index];
```

Access an element using an index.

Example:

```cpp
cout << dq[0];
```

Unlike `queue`, a `deque` supports indexed access.

---

# Queue vs Deque

| Feature | Queue | Deque |
|---|---|---|
| Insert at front | No | Yes |
| Insert at back | Yes | Yes |
| Remove from front | Yes | Yes |
| Remove from back | No | Yes |
| Access front | Yes | Yes |
| Access back | Yes | Yes |
| Indexed access | No | Yes |

---

# Final Mind Map

```text
QUEUE

FIFO

Insert:
rear

Remove:
front
```

```text
Queue operations:

push
pop
front
back
empty
size
```

```text
Linked-list queue:

head = front
tail = rear
```

```text
Circular queue:

reuse empty array spaces

wrap around using:

(index + 1) % capacity
```

```text
Deque:

Double-Ended Queue

insert and delete
from both front and back
```

---

# Final Complexity Summary

| Data Structure | Operation | Time |
|---|---|---:|
| Linked-list queue | Push | `O(1)` |
| Linked-list queue | Pop | `O(1)` |
| Linked-list queue | Front | `O(1)` |
| Circular queue | Push | `O(1)` |
| Circular queue | Pop | `O(1)` |
| Circular queue | Front | `O(1)` |
| STL queue | Push/Pop | `O(1)` |
| STL deque | Push front/back | `O(1)` |
| STL deque | Pop front/back | `O(1)` |
| STL deque | Indexed access | `O(1)` |