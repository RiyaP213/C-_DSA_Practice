
// Do-While Loop in C++: Keep running the loop until the user enters a number that is a multiple of 10.
#include<iostream>

using namespace std;
int main(){
    int n;
    do{
        cout<<"Enter a number: ";
        cin>>n;
        if(n%10==0){
            break;
        }   
    }while(true);
    cout<<"You entered: "<<n;
    return 0;
}       