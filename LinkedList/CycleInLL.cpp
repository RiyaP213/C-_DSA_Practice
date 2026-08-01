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

// Detect cycle using Floyd's slow and fast pointer algorithm
bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;             // moves by 1
        fast = fast->next->next;       // moves by 2

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Detect and remove cycle
void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool cycleExists = false;

    // Step 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycleExists = true;
            break;
        }
    }

    // No cycle exists
    if (!cycleExists) {
        cout << "Cycle does not exist\n";
        return;
    }

    // Step 2: Move slow back to head
    slow = head;

    /*
    Special case:
    The cycle starts at head.

    Example:

    10 -> 20 -> 30 -> 40
    ^                 |
    |_________________|
    */
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }

        // fast is now the last node in the cycle
        fast->next = nullptr;
    }

    /*
    Normal case:
    The cycle starts somewhere after head.

    Example:

    10 -> 20 -> 30 -> 40
          ^           |
          |___________|
    */
    else {
        Node* prev = fast;

        // slow and fast meet at the first node of the cycle
        while (slow != fast) {
            slow = slow->next;

            prev = fast;
            fast = fast->next;
        }

        // prev is the last node in the cycle
        prev->next = nullptr;
    }

    cout << "Cycle removed successfully\n";
}

// Print list only after the cycle has been removed
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

int main() {
    // Create nodes
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    /*
    Normal list:

    10 -> 20 -> 30 -> 40 -> nullptr
    */

    // Create a cycle:
    // 40 points back to 20
    head->next->next->next->next = head->next;

    /*
    Cyclic list:

    10 -> 20 -> 30 -> 40
          ^           |
          |___________|
    */

    if (isCycle(head)) {
        cout << "Cycle exists\n";
    }
    else {
        cout << "Cycle does not exist\n";
    }

    // Remove the cycle
    removeCycle(head);

    // Check again
    if (isCycle(head)) {
        cout << "Cycle still exists\n";
    }
    else {
        cout << "Cycle no longer exists\n";
    }

    // Safe to print after removing cycle
    printList(head);

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}