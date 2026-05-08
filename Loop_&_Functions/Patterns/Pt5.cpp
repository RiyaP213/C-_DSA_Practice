#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"enter a number:";
    cin>>n;

    for(int i=0;i<=n;i++){  
        
        for (int j=1;j<=n; j++){
            if(j==1 || j==n||i==0||i==n){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}