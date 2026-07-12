#include<iostream>
using namespace std;

void updateIthBit(int num, int i, int value)
{
    num = num & ~(1 << i); // clear the i-th bit
    num = num | (value << i); // set the i-th bit to the desired
    cout<<"The updated number is: "<<num<<endl;

}


int main(){
    updateIthBit(7, 2, 0); // Example usage: Update the 1st bit of number 5 (binary 101) to 0
    return 0;

}