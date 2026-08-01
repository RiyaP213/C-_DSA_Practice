
#include <iostream>
using namespace std;

// ============================================================
// DOUBLY LINKED LIST
//
// Each node stores:
// 1. data
// 2. next pointer
// 3. previous pointer
//
// Example:
//
// NULL <- 1 <=> 2 <=> 3 <=> 4 -> NULL
//
// Advantages:
// • Can traverse forward and backward.
// • pop_back() is O(1) because we have tail->prev.
//
// Disadvantage:
// • Extra memory for the prev pointer.
// ============================================================

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = nullptr;
    }

    // ========================================================
    // PUSH FRONT
    //
    // Before:
    // NULL <- 2 <=> 3 -> NULL
    //
    // push_front(1)
    //
    // After:
    // NULL <- 1 <=> 2 <=> 3 -> NULL
    // ========================================================

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // ========================================================
    // PUSH BACK
    //
    // Before:
    // NULL <- 1 <=> 2 -> NULL
    //
    // push_back(3)
    //
    // After:
    // NULL <- 1 <=> 2 <=> 3 -> NULL
    // ========================================================

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // ========================================================
    // POP FRONT
    //
    // Before:
    // NULL <- 1 <=> 2 <=> 3 -> NULL
    //
    // After:
    // NULL <- 2 <=> 3 -> NULL
    // ========================================================

    void pop_front() {

        // Empty list
        if (head == nullptr) {
            return;
        }

        Node* temp = head;

        // Move head forward
        head = head->next;

        // If list still has nodes
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            // List became empty
            tail = nullptr;
        }

        // Disconnect old head
        temp->next = nullptr;

        delete temp;
    }

    // ========================================================
    // POP BACK
    //
    // Before:
    // NULL <- 1 <=> 2 <=> 3 -> NULL
    //
    // After:
    // NULL <- 1 <=> 2 -> NULL
    // ========================================================

    void pop_back() {

        // Empty list
        if (tail == nullptr) {
            return;
        }

        Node* temp = tail;

        // Move tail backward
        tail = tail->prev;

        // If list still has nodes
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            // List became empty
            head = nullptr;
        }

        // Disconnect old tail
        temp->prev = nullptr;

        delete temp;
    }

    // ========================================================
    // PRINT LIST (Forward Traversal)
    // ========================================================

    void printList() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // ========================================================
    // PRINT LIST (Backward Traversal)
    // ========================================================

    void printBackward() {
        Node* temp = tail;

        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }
};

int main() {

    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    cout << "Forward Traversal:\n";
    dbll.printList();

    cout << "\nBackward Traversal:\n";
    dbll.printBackward();

    dbll.push_back(5);

    cout << "\nAfter push_back(5):\n";
    dbll.printList();

    dbll.pop_front();

    cout << "\nAfter pop_front():\n";
    dbll.printList();

    dbll.pop_back();

    cout << "\nAfter pop_back():\n";
    dbll.printList();

    return 0;
}

/*
============================================================
TIME COMPLEXITIES
============================================================

push_front()      O(1)

push_back()       O(1)

pop_front()       O(1)

pop_back()        O(1)

Forward Traversal O(n)

Backward Traversal O(n)

============================================================
MEMORY PATTERN
============================================================

push_front()

newNode->next = head;
head->prev = newNode;
head = newNode;


push_back()

tail->next = newNode;
newNode->prev = tail;
tail = newNode;


pop_front()

head = head->next;
head->prev = nullptr;


pop_back()

tail = tail->prev;
tail->next = nullptr;


Edge case:

If the last node is deleted,

head = tail = nullptr;

============================================================
*/