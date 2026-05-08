
// same as patter 2 but another way of doing it. this is more effecient.


#include<iostream>
using namespace std;        
int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;

    for(int i=0;i<n;i++){  
        
        for (int j=n;j>i; j--){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}