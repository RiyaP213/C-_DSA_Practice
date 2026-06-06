#include<iostream>
using namespace std;
int Factorial(int n){
    if (n==0 || n==1){
        return 1;
    }
    else{
        return n*Factorial(n-1);
    }
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The factorial of " << n << " is: " << Factorial(n) << endl;
    return 0;
}