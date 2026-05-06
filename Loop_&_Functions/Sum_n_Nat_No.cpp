#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout<<"Enter a natural number:";
    cin>>n;
    for (int i=0;i<=n;i++){
        sum+=i;
    }
    cout<<"The sum of first "<<n<<" natural numbers is "<<sum;
    return 0;
}