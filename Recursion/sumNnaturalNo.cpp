#include<iostream>
using namespace std;
// Do you remember stack overflow? 
//It is a situation where the program runs out of stack memory due to too many nested function calls. 
//In recursion, each function call adds a new layer to the stack, and if the recursion is too deep, it can lead to stack overflow. 
//To avoid this, it's important to have a base case that stops the recursion.

int sum(int n){
    if (n==1){
         return 1;
    }
    return n + sum(n - 1);
}
int main (){
    cout << sum(5) << endl; // Example usage: Calculate the sum of first 5 natural numbers
    return 0;
}