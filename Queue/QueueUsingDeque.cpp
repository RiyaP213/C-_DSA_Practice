#include<iostream>
#include<deque>
using namespace std;

// we need to implement queue using deque because deque is a double ended queue which allows insertion and deletion from both ends.
// we need to implement push, pop, front, back, empty and size functions of queue using deque.
// we will use deque's push_back, pop_front, front, back, empty and size functions to implement queue's functions.

class Queue{
    private:
        deque<int> dq;
    public:
        void push(int data){
            dq.push_back(data);
        }
        void pop(){
            if(dq.empty()){
                cout<<"Queue is empty\n";
                return;
            }
            dq.pop_front();
        }
        int front(){
            if(dq.empty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            return dq.front();
        }
        int back(){
            if(dq.empty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            return dq.back();
        }
        bool empty(){
            return dq.empty();
        }
        int size(){
            return dq.size();
        }
};