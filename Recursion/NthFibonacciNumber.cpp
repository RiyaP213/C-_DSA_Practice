#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n==0||n==1){
        return n;

    }
    return Fibonacci(n-1)+ Fibonacci(n-2);
    
}

int main(){
    cout<<Fibonacci(5)<<endl; // Example usage: Calculate the 5th Fibonacci number
    return 0;
}