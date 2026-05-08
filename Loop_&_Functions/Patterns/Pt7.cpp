#include<iostream>
using namespace std;
int main (){
    int n=6;
    char ch='A';
    for (int i=0;i<=n;i++){
        for (int j=1;j<=i; j++){
            cout<<ch++<<" ";
        }
        cout<<endl;
    }
}