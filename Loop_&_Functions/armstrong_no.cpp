#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    int org=n;
int cubesum=0;
    while(n>0){
        int dig=n%10;
        cubesum+=dig*dig*dig;
        n/=10;  

    }
    if(cubesum==org){
        cout<<org<<" is an Armstrong number.";
    }
    else{
        cout<<org<<" is not an Armstrong number.";
    }
    return 0;   
    }
