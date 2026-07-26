# Singly Linked List (C++) Revision Notes

```cpp
#include <iostream>
using namespace std;
```

---

# 1. Node Class

Each node stores:
- Data
- Pointer to the next node

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }

    ~Node() {
        // Destructor
    }
};
```

Memory:

```text
[data | next]
```

Example:

```text
[10 | 0x200]
```

---

# 2. LinkedList Class

The linked list stores:

- `head` → first node
- `tail` → last node

```cpp
class LinkedList {
private:
    Node* head;
    Node* tail;

public:

    LinkedList() {
        head = tail = nullptr;
    }

    ~LinkedList() {
        clear();
    }
```

Initially:

```text
head → nullptr
tail → nullptr
```

---

# 3. push_front()

Adds a node at the beginning.

```cpp
void push_front(int value) {

    Node* newNode = new Node(value);

    if(head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}
```

### Logic

```text
Create node

↓

Connect new node to old head

↓

Move head
```

Example

Before

```text
head
 ↓
10 → 20
```

After

```text
head
 ↓
5 → 10 → 20
```

Time Complexity

```
O(1)
```

---

# 4. push_back()

Adds a node at the end.

```cpp
void push_back(int value) {

    Node* newNode = new Node(value);

    if(head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
```

### Logic

```text
Create node

↓

Connect old tail

↓

Move tail
```

Example

Before

```text
10 → 20
       ↑
      tail
```

After

```text
10 → 20 → 30
            ↑
           tail
```

Time Complexity

```
O(1)
```

---

# 5. print()

Traverses the list.

```cpp
void print() {

    Node* temp = head;

    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
```

### Logic

```text
Start at head

↓

Print

↓

Move

↓

Repeat
```

**Never move `head` while printing.**

Time Complexity

```
O(n)
```

---

# 6. insert() (Middle)

```cpp
void insert(int value, int index) {

    if(index == 0) {
        push_front(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    for(int i=0; i<index-1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
```

### Logic

```text
Reach previous node

↓

New node points to next node

↓

Previous node points to new node
```

Time Complexity

```
O(n)
```

---

# 7. pop_front()

Deletes the first node.

```cpp
void pop_front() {

    if(head == nullptr)
        return;

    Node* temp = head;

    head = head->next;

    delete temp;

    if(head == nullptr)
        tail = nullptr;
}
```

### Logic

```text
Save head

↓

Move head

↓

Delete old head
```

Time Complexity

```
O(1)
```

---

# 8. pop_back()

Deletes the last node.

```cpp
void pop_back() {

    if(head == nullptr)
        return;

    if(head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* temp = head;

    while(temp->next != tail) {
        temp = temp->next;
    }

    delete tail;

    tail = temp;

    tail->next = nullptr;
}
```

### Logic

```text
Reach node before tail

↓

Delete tail

↓

Move tail

↓

Set next = nullptr
```

Time Complexity

```
O(n)
```

---

# 9. Iterative Search

Returns index of key.

```cpp
int search(int key) {

    Node* temp = head;

    int index = 0;

    while(temp != nullptr) {

        if(temp->data == key)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}
```

### Logic

```text
Compare

↓

Move

↓

Repeat
```

Time Complexity

```
O(n)
```

---

# 10. Recursive Search

```cpp
int recursiveSearch(Node* current, int key) {

    if(current == nullptr)
        return -1;

    if(current->data == key)
        return 0;

    int idx = recursiveSearch(current->next, key);

    if(idx == -1)
        return -1;

    return idx + 1;
}

int searchRecursive(int key) {
    return recursiveSearch(head, key);
}
```

### Logic

```text
Current node?

↓

Found?

↓

Search remaining list

↓

Add 1 while returning
```

Time Complexity

```
O(n)
```

Space Complexity

```
O(n)
```

---

# 11. Reverse Linked List

```cpp
void reverse() {

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    tail = head;

    while(current != nullptr) {

        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }

    head = prev;
}
```

### Logic

```text
Save next

↓

Reverse link

↓

Move prev

↓

Move current
```

Time Complexity

```
O(n)
```

Space Complexity

```
O(1)
```

---

# 12. Delete Entire Linked List

Used inside the destructor.

```cpp
void clear() {

    while(head != nullptr) {

        Node* temp = head;

        head = head->next;

        delete temp;
    }

    tail = nullptr;
}
```

### Logic

```text
Save node

↓

Move head

↓

Delete node

↓

Repeat
```

Time Complexity

```
O(n)
```

---

# 13. Example (main)

```cpp
int main() {

    LinkedList ll;

    ll.push_front(20);
    ll.push_front(10);

    ll.push_back(30);
    ll.push_back(40);

    ll.print();

    ll.insert(25, 2);

    ll.print();

    ll.pop_front();

    ll.pop_back();

    ll.print();

    cout << ll.search(25) << endl;

    cout << ll.searchRecursive(30) << endl;

    ll.reverse();

    ll.print();

    return 0;
}
```

---

# Complexity Summary

| Operation | Time |
|-----------|------|
| push_front | O(1) |
| push_back | O(1) *(with tail)* |
| print | O(n) |
| insert | O(n) |
| pop_front | O(1) |
| pop_back | O(n) |
| search | O(n) |
| recursive search | O(n) |
| reverse | O(n) |
| clear | O(n) |

---

# Pointer Patterns (Memorize These)

### push_front

```text
Create
↓

Connect

↓

Move head
```

### push_back

```text
Create
↓

Connect tail

↓

Move tail
```

### insert

```text
Reach previous

↓

New → Next

↓

Previous → New
```

### pop_front

```text
Save

↓

Move head

↓

Delete
```

### pop_back

```text
Find previous

↓

Delete tail

↓

Move tail
```

### reverse

```text
Save next

↓

Reverse link

↓

Move prev

↓

Move current
```

### print / search

```text
Start at head

↓

Visit node

↓

Move

↓

Repeat until nullptr
```