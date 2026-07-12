#include<iostream>
using namespace std;

// this program will count the number of set bits in a given number
// we can do this by using the bitwise AND operator and right shifting the number
// we will keep right shifting the number until it becomes 0 and count the number of times we get a 1 in the least significant bit

int countSetBits(int num){
     int count=0;
        while(num>0){
             int lastBit=num&1; // get the last bit of the number
                count+=lastBit; // add the last bit to the count
                num=num>>1; // right shift the number by 1

}
cout<< count<< endl;
return count;
}

int main(){
    countSetBits(15); // Example usage: Count the number of set bits in number 15 (binary 1111)
    return 0;
    
}