#include<iostream>
using namespace std;
int main()
// even numbers right most bit is 0 and odd numbers right most bit is 1
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(n&1)
        cout<<n<<" is odd";
    else
        cout<<n<<" is even";
    return 0;
}
