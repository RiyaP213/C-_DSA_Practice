#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1) // base case: factorial of 0 or 1 is 1
        return 1;
    else
        return n * factorial(n - 1); // recursive case: n! = n * (n-1)!
}

int main(){
    cout << factorial(5) << endl; // Example usage: Calculate factorial of 5
    return 0;
}