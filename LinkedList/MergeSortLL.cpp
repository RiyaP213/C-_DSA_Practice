#include <iostream>
using namespace std;

// ============================================================
// NODE CLASS
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
// CUSTOM LINKED LIST CLASS
// This is our own List class—not std::list.
// ============================================================

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

// ============================================================
// PRINT LINKED LIST
// ============================================================

void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

// ============================================================
// SPLIT THE LINKED LIST AT THE MIDDLE
//
// slow moves 1 step.
// fast moves 2 steps.
// prev tracks the node before slow.
//
// After finding the middle:
//
// prev->next = nullptr
//
// splits the original list into two halves.
//
// The function returns the head of the right half.
// ============================================================

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // prev is the last node of the left half
    if (prev != nullptr) {
        prev->next = nullptr;
    }

    // slow is the head of the right half
    return slow;
}

// ============================================================
// MERGE TWO SORTED LINKED LISTS
//
// Compare elements from both sorted halves.
// Push the smaller value into the answer list.
//
// When one half finishes, copy the remaining values
// from the other half.
//
// Return the head of the merged list.
// ============================================================

Node* merge(Node* leftHead, Node* rightHead) {
    List ans; // stores the merged linked list

    Node* i = leftHead;
    Node* j = rightHead;

    while (i != nullptr && j != nullptr) {
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        }
        else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    // Add remaining nodes from the left half
    while (i != nullptr) {
        ans.push_back(i->data);
        i = i->next;
    }

    // Add remaining nodes from the right half
    while (j != nullptr) {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

// ============================================================
// MERGE SORT
//
// 1. Base case: empty or one-node list is already sorted.
// 2. Split the list into left and right halves.
// 3. Recursively sort both halves.
// 4. Merge the sorted halves.
// ============================================================

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

// ============================================================
// DELETE ALL NODES
// ============================================================

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================================
// MAIN
// ============================================================

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);

    // Current list:
    // 3 -> 2 -> 1 -> 4 -> 5 -> nullptr

    cout << "Before sorting:\n";
    printList(ll.head);

    ll.head = mergeSort(ll.head);

    cout << "\nAfter sorting:\n";
    printList(ll.head);

    deleteList(ll.head);

    return 0;
}