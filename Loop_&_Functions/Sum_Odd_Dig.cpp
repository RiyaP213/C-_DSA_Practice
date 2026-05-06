#include<iostream>
using namespace std;
int main(){
    int dig;
    cout<<"Enter a digit:";
    cin>>dig;
    int sum=0;
    while(dig!=0){
        if (dig%2!=0){
            sum+=dig%10;
        }
        dig/=10;
        }
    cout<<"The sum of odd digits is: "<<sum;
    return 0;
}
