#include<iostream>
using namespace std;


// we can calculate the power of a number using bit manipulation.
// we can do this by using the property of exponents.
// a^b = a^(b/2) * a^(b/2) if b is even
// a^b = a^(b/2) * a^(b/2) * a if b is odd
// we can use this property to calculate the power of a number in O(log b) time complexity.
// we can also use bit manipulation to check if a number is even or odd.
// if b is even, then the last bit of b will be 0, otherwise it will be 1.
// we can use this property to check if a number is even or odd in O(1) time complexity.
// we can also use bit manipulation to calculate the power of a number in O(log b) time complexity.
void FastExpo(int x, int n){

    int ans=1;

    while(n>0){
         int lastBit = n&1;
         if( lastBit){
            ans = ans *x;
         }

         x=x*x;
            n=n>>1;

         }
         cout<< ans<< endl;

    }
int main(){
    FastExpo(3,4);
    return 0;
}