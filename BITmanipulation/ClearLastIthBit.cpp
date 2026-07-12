#include<iostream>
using namespace std;


void clearIthBit(int n, int i)
{
    int mask = ~(1 << i); // create a mask by left shifting 1 by i positions
    int result = n & mask;   // use bitwise AND to clear the i-th bit
    cout << "The number after clearing the " << i << "th bit is: " << result << endl;
}

    int main(){
        clearIthBit(15, 2); // Example usage: Clear the 1st bit of number 15 (binary 1111) to 0
        return 0;

    }