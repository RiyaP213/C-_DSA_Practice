#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "Enter a number";
    cin>>n;
    int numskip=0;
while (n>0){
    if(n%10==3){
        n/=10;
        continue;}
    numskip=numskip*10+n%10;
    n/=10;  
        
    }
int numskiprev=0;
    while(numskip>0){
        numskiprev=numskiprev*10+numskip%10;
        numskip/=10;
    }
cout<<"The number after skipping 3 is: "<<numskiprev;
return 0;   

}