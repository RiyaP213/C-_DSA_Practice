#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
int reverse=0;
while(n>0){
    reverse=reverse*10+n%10;
    n/=10;
}
cout<<"The reverse of the number is: "<<reverse;
return 0;
}   

