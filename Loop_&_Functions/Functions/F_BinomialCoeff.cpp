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
int BionomialCoeff(int n, int r){
    return Factorial(n) / (Factorial(r) * Factorial(n - r));
}

int main(){
    int n,r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    cout << "The binomial coefficient C(" << n << ", " << r << ") is: " << BionomialCoeff(n, r) << endl;
    return 0;
}