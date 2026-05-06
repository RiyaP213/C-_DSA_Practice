#include<iostream>
using namespace std;

// An Armstrong number is a number that is equal to the sum of its digits raised to the power of the number of digits.
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int dig1= n%10;
    int dig2= (n/10)%10;
    int dig3= (n/100)%10;
    int sum = (dig1*dig1*dig1) + (dig2*dig2*dig2) + (dig3*dig3*dig3);
    if(sum==n){
        cout<<n<<" is an Armstrong number.";
    }
    else{
        cout<<n<<" is not an Armstrong number.";
    }
    return 0;
}   
