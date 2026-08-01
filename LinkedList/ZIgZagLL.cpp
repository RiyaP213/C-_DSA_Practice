#include <iostream>
using namespace std;

// ============================================================
// NODE CLASS
// Each node stores data and a pointer to the next node.
// ============================================================

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// ============================================================
// LINKED LIST CLASS
// ============================================================

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void print() const {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "nullptr\n";
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }

    ~List() {
        clear();
    }
};

// ============================================================
// SPLIT THE LINKED LIST INTO TWO HALVES
//
// slow moves one step.
// fast moves two steps.
//
// Example:
//
// 1 -> 2 -> 3 -> 4 -> 5
//
// Left half:
// 1 -> 2 -> 3
//
// Right half:
// 4 -> 5
//
// The function returns the head of the right half.
// ============================================================

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // The node after slow is the head of the right half
    Node* rightHead = slow->next;

    // Break the connection between the two halves
    slow->next = nullptr;

    return rightHead;
}

// ============================================================
// REVERSE A LINKED LIST
//
// Example:
//
// 4 -> 5 -> nullptr
//
// becomes:
//
// 5 -> 4 -> nullptr
// ============================================================

Node* reverseList(Node* head) {
    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        // Save the remaining list
        nextNode = current->next;

        // Reverse the current link
        current->next = previous;

        // Move both pointers forward
        previous = current;
        current = nextNode;
    }

    // previous is the new head of the reversed list
    return previous;
}

// ============================================================
// CONVERT LINKED LIST INTO ZIG-ZAG ORDER
//
// Zig-zag means travelling alternately from the front
// and the back of the original linked list.
//
// Example:
//
// Original:
//
// 1 -> 2 -> 3 -> 4 -> 5
//
// Step 1: Split
//
// Left:  1 -> 2 -> 3
// Right: 4 -> 5
//
// Step 2: Reverse right half
//
// Right: 5 -> 4
//
// Step 3: Alternate merge
//
// Result:
//
// 1 -> 5 -> 2 -> 4 -> 3
// ============================================================

void zigZagLinkedList(Node* head) {
    // Empty list or one-node list needs no change
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Step 1: Split the linked list into two halves
    Node* rightHead = splitAtMid(head);

    // Step 2: Reverse the second half
    rightHead = reverseList(rightHead);

    // Step 3: Alternate merge the two halves
    Node* left = head;
    Node* right = rightHead;

    /*
        Before changing any links, store the next nodes.

        leftNext keeps the remaining left list.
        rightNext keeps the remaining right list.
    */

    while (left != nullptr && right != nullptr) {
        Node* leftNext = left->next;
        Node* rightNext = right->next;

        // Connect one left node to one right node
        left->next = right;

        // Connect the right node back to the next left node
        right->next = leftNext;

        // Move to the next available nodes
        left = leftNext;
        right = rightNext;
    }
}

// ============================================================
// MAIN FUNCTION
// ============================================================

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original linked list:\n";
    ll.print();

    zigZagLinkedList(ll.head);

    // Recalculate tail after rearranging the linked list
    ll.tail = ll.head;

    while (ll.tail != nullptr && ll.tail->next != nullptr) {
        ll.tail = ll.tail->next;
    }

    cout << "\nZig-zag linked list:\n";
    ll.print();

    return 0;
}