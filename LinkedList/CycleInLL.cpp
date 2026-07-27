#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

bool isCycle(Node* head){
       Node* slow =head;
       Node* fast =head;

       while(fast!= NULL && fast->next != NULL){
         slow=slow->next;//+1
         fast= fast->next->next;//+2;

         if(slow==fast){
            cout <<"cycle exists\n";
            return true;
         }
       }

       cout<< "cycle dosen't exist\n";
       return false;

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

    // Create a cycle for testing:
    // 40 points back to 20
    head->next->next->next->next = head->next;

    if (isCycle(head)) {
        cout << "Cycle exists\n";
    }
    else {
        cout << "Cycle does not exist\n";
    }

    return 0;
}