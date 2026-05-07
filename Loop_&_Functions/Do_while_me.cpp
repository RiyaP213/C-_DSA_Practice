
// instead of break statement we could do this using do while loop
#include<iostream>
using namespace std;
int main(){
    int n;
    do{
        cout<<"Enter a number: ";

        cin>>n;} while(n%10!=0);
cout<<"You entered: "<<n;
    return 0;   
    }