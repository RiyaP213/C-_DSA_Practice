#include<iostream>
using namespace std;
int BinaryToDecimal(int n){
    int decimal=0;
    int pow=1;
    while(n>0){
        int lastDigit=n%10;
        decimal+=lastDigit*pow;
        pow*=2;
        n/=10;
    }
    return decimal;
}
int main(){
    int n;
    cout << "Enter a binary number: ";
    cin >> n;
    cout << "The decimal equivalent of " << n << " is: " << BinaryToDecimal(n) << endl;
    return 0;
}