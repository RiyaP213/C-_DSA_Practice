#include<iostream>
using namespace std;

int GetIthBit(int n, int i)
{
    int mask = 1 << i;

    if(n & mask){
        return 1;
    }
    else{
        return 0;
    }


}
int main()
{
    int n, i;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Enter the position of bit to be checked: ";
    cin>>i;

    int bit = GetIthBit(n, i);
    cout<<"The "<<i<<"th bit of "<<n<<" is: "<<bit<<endl;

    return 0;
}