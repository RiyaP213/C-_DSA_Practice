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
        next = NULL;// use "nullptr"
    }

    ~Node() {
        if(next!=NULL){
            delete next;
            next=NULL;
            // or u can just do clear()
    }
};
---

# 2. LinkedList Class

The linked list stores:

- `head` → first node pointer
- `tail` → last node pointer

```cpp
class list {
private:
    Node* head;
    Node* tail;

public:

    list() {
        head = tail = NULL;//use "nullptr" thats compiler friendly.
    }

    ~List() {
        if(head!=NULL){
             delete head;
             head=NULL;// or just use clear() 
        }
    }

---

# 3. push_front()

Adds a node at the beginning.

```cpp
void push_front(int value) {

    Node* newNode = new Node(value);// allocate memory in heap dynamically

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
if head==nullptr we know its the first node so we point head and tail to "newnode" if its not the case 
Create node-> Connect new node to old head (because we are pushing in front -> Move head
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
if first node head and tail both point to new node else. Create node -> Connect old tail-> Move tail
```
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
Start at head-> Print-> Move-> Repeat.  we take a "temp" because we dont want to lose the head.
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
Reach previous node->  New node points to next node-> 
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

   // if(head == nullptr)
   //     tail = nullptr;
}
```

### Logic

```text
Save head-> Move head-> Delete old head
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

  //  if(head == nullptr)
     //   return;

    //if(head == tail) {
      //  delete head;
        //head = tail = nullptr;
        //return;
   // }

    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next =NULL//temp=tail's prev
    delete tail;

    tail = temp;
}
```

### Logic

```text
Reach node before tail-> Delete tail-> Move tail-> Set next = nullptr
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
Compare->  Move-> Repeat
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
Current node?-> Found?-> Search remaining list-> 
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
Save next->  Reverse link-> Move prev-> 
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
Save node-> Move head-> Delete node-> Repeat
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
Create-> Connect-> 
Move head
```

### push_back

```text
Create-> Connect tail-> Move tail
```

### insert

```text
Reach previous-> 
New → Next
Previous → New
```

### pop_front

```text
Save
Move head
Delete
```

### pop_back

```text
Find previous
Delete tail
Move tail
```

### reverse

```text
Save next
Reverse link
Move prev
Move current
```

### print / search

```text
Start at head
Visit node
Move
Repeat until nullptr
```
# 14. Reverse a Linkedlist
```cpp
void reverse(){
    node* curr= head;
    node * prev = null;
    tail = head;

    while(curr!=NULL){
        node*next = curr->next;
        curr->next =prev;
    }
    //update for next itr
    prev=curr;
    curr=next;}
    head= prev;
}

```

# 15. Remove Nth node
```cpp
int getsize(){
    int sz=0;
    node* temp= head;

    while(temp!=null){
        temp=temp->next;
        sz++;
    }
    return sz;
}

void removeNth(int n){
    int size =getsize();
    node* prev =head;

    for(int i=1; i<(size-n);i++){
        prev= prev->next;
    }
    node* toDel= prev->next;
    cout<<"going to delete :"<<toDel->data<<endl;
    prev->next =prev->next->next;
}
};

```text
common problems:
1) Palindrome
2) Detect and Remove a Cycle in a LL
3) MergeSort
4) zig-Zag LL
5) Doubly Linked List

# STL List and Iterator

`std::list` is the STL version of a **doubly linked list**.

To use it:

```cpp
#include <list>
```

Creating a list is similar to creating a vector:

```cpp
vector<int> v;
list<int> ll;
```

## Common Functions

```cpp
ll.push_front(value);   // insert at front
ll.push_back(value);    // insert at back

ll.pop_front();         // remove first element
ll.pop_back();          // remove last element

ll.front();             // first value
ll.back();              // last value

ll.size();              // number of elements
```

## Iterator

An iterator is an object used to **move through the elements of a container**.

It behaves somewhat like a pointer.

```cpp
auto it = ll.begin();
```

- `ll.begin()` → first element
- `ll.end()` → position after the last element
- `*it` → value at the iterator
- `it++` → move to the next element
- `it--` → move to the previous element

## Insert Using an Iterator

```cpp
ll.insert(it, value);
```

This inserts the value **before** the iterator position.

## Complete Code

```cpp
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(const list<int>& ll) {
    for (auto it = ll.begin(); it != ll.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
}

int main() {
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    // List: 1 2 3 4
    printList(ll);

    auto it = ll.begin();
    it++;                       // points to 2

    ll.insert(it, 10);          // inserts 10 before 2

    // List: 1 10 2 3 4
    printList(ll);

    cout << "Size: " << ll.size() << endl;
    cout << "Front: " << ll.front() << endl;
    cout << "Back: " << ll.back() << endl;

    ll.pop_front();
    ll.pop_back();

    // List: 10 2 3
    printList(ll);

    return 0;
}
```

## Quick Memory Note

```text
list<int> ll       → create STL linked list

begin()            → first element
end()              → after last element
*it                → current value
it++               → next element

insert(it, value)  → insert before iterator
```