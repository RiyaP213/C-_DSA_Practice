#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    bool isprime=true;

    if (n<=1){
        isprime=false;
    }
    else{
        for(int i=2; i*i<=n; i++){// we can also do i<=sqrt(n) but that is costly as we have to calculate the square root of n every time
            if(n%i==0){
                isprime=false;
                break;
            }
        }
    
            
        }
    if (isprime){
            cout<<n<<" is a prime number.";
        }
        else{
            cout<<n<<" is not a prime number.";
    }
    return 0;
}
