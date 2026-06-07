#include<iostream>
using namespace std;
int Decimal(int n)
{
    int binary=0;
    int pow=1;
    while(n>0){
        int lastDigit=n%2;
        binary+=lastDigit*pow;
        pow*=10;
        n/=2;
    }
    return binary;

}
int main(){
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "The binary equivalent of " << n << " is: " << Decimal(n) << endl;
    return 0;
}
