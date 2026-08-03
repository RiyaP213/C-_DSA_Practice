````md
# Stack (LIFO)

## Definition

A **Stack** is a linear data structure that follows the principle:

> **LIFO (Last In, First Out)**

The last element inserted is the first element removed.

Example:

```text
Top
 ↓
30
20
10
```

If we `pop()`, **30** is removed first.

---

# Core Stack Operations

```cpp
push()
```

Insert an element at the top.

```cpp
pop()
```

Remove the top element.

```cpp
top()
```

Return the top element without removing it.

```cpp
empty()
```

Returns `true` if the stack is empty.

---

# Stack Implementations

A stack can be implemented using:

- Arrays
- Dynamic Arrays (Vectors)
- Linked Lists
- STL Stack

The **behaviour** is what defines a stack, **not the underlying data structure**.

---

# Time Complexity

| Operation | Complexity |
|-----------|------------|
| Push | O(1) |
| Pop | O(1) |
| Top | O(1) |
| Empty | O(1) |

---

# Why use Vector instead of Array?

Arrays require the size to be fixed beforehand.

```cpp
int arr[100];
```

Problem:

- Fixed size
- Can overflow
- Wastes memory if the array is too large

Instead we use a **vector** because it is a **dynamic array**.

Advantages:

- Automatically resizes
- Easier to implement
- No need to decide size beforehand

---

# Stack using Vector

```cpp
#include<iostream>
#include<vector>
using namespace std;

class Stack {

    vector<int> vec;

public:

    void push(int val) {
        vec.push_back(val);
    }

    void pop() {

        if (isEmpty()) {
            return;
        }

        vec.pop_back();
    }

    int top() {

        if (isEmpty()) {
            return -1;
        }

        int lastIdx = vec.size() - 1;

        return vec[lastIdx];
    }

    bool isEmpty() {

        return vec.size() == 0;
    }

};
```

---

# Class Template

The previous stack only works for integers.

Suppose we want:

```cpp
Stack<int>
Stack<double>
Stack<char>
Stack<string>
```

Instead of writing separate classes, C++ provides **Templates**.

Templates allow us to write one generic class that works for any data type.

---

# Stack using Class Template

```cpp
#include<iostream>
#include<vector>
using namespace std;

template<class T>

class Stack {

    vector<T> vec;

public:

    void push(T val) {
        vec.push_back(val);
    }

    void pop() {

        if (isEmpty()) {
            return;
        }

        vec.pop_back();
    }

    T top() {

        if (isEmpty()) {
            return T();
        }

        int lastIdx = vec.size() - 1;

        return vec[lastIdx];
    }

    bool isEmpty() {

        return vec.size() == 0;
    }

};
```

Example:

```cpp
Stack<int> s1;

Stack<double> s2;

Stack<char> s3;

Stack<string> s4;
```

---

# Stack using Linked List

Instead of using a vector, we can also implement a stack using a linked list.

The front of the linked list acts as the **Top** of the stack.

Why?

Because inserting and deleting at the front of a linked list takes **O(1)** time.

---

```cpp
#include<iostream>
#include<list>
#include<string>
using namespace std;

template<class T>

class Stack {

    list<T> ll;

public:

    void push(T val) {

        ll.push_front(val);
    }

    void pop() {

        if (isEmpty()) {
            return;
        }

        ll.pop_front();
    }

    T top() {

        if (isEmpty()) {
            return T();
        }

        return ll.front();
    }

    bool isEmpty() {

        return ll.empty();
    }

    void print() {

        for (T value : ll) {
            cout << value << " ";
        }

        cout << endl;
    }

};
```

---

# Stack using STL

C++ already provides a built-in stack.

```cpp
#include<iostream>
#include<stack>
using namespace std;

int main() {

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;

    s.pop();

    cout << s.top() << endl;

    cout << s.empty() << endl;

    return 0;
}
```

---

# STL Stack Functions

```cpp
push()
```

Insert element.

```cpp
pop()
```

Remove top element.

```cpp
top()
```

Return top element.

```cpp
empty()
```

Returns true if the stack is empty.

```cpp
size()
```

Returns the number of elements in the stack.

---

# Memory Pattern

```text
push()
↓

Adds element at TOP


pop()
↓

Removes element from TOP


top()
↓

Returns TOP element


empty()
↓

Checks whether stack is empty
```

---

# Summary

```text
Stack

↓

LIFO (Last In First Out)

↓

Operations

• push()
• pop()
• top()
• empty()

↓

Implementations

• Array
• Vector
• Linked List
• STL Stack

↓

Complexities

Push  → O(1)

Pop   → O(1)

Top   → O(1)

Empty → O(1)
```
````
