#include<iostream>
using namespace std;

// we need to implement stack using deque because deque is a double ended queue which allows insertion and deletion from both ends.
// we need to implement push, pop, top, empty and size functions of stack using deque.
// we will use deque's push_front, pop_front, back, empty and size functions to implement stack's functions.

class Stack{
    private:
        deque<int> dq;
    public:
        void push(int data){
            dq.push_front(data);
        }
        void pop(){
            if(dq.empty()){
                cout<<"Stack is empty\n";
                return;
            }
            dq.pop_front();
        }
        int top(){
            if(dq.empty()){
                cout<<"Stack is empty\n";
                return -1;
            }
            return dq.front();
        }
        bool empty(){
            return dq.empty();
        }
        int size(){
            return dq.size();
        }
};

int main(){
    Stack s;
    for(int i=1; i<=5;i++){
    s.push(i);
    }

    for(int i=1; i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}