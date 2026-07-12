#include<iostream>
using namespace std;

// note : all powers of 2 have only one bit set in their binary representation. 
//so we can check if a number is a power of 2 by checking if it has only one bit set.
// we can do this by using the bitwise AND operator.
// if n is a power of 2, then n & (n-1) will be 0, otherwise it will be non-zero.


bool IsPowerOf2(int n)
{
    if( !(n &&(n-1 ))== 0)
        return true;
    else
        return false;
}
int main()
{ 
    cout<< IsPowerOf2(16); // Example usage: Check if 16 is a power of 2
    return 0;
    


}