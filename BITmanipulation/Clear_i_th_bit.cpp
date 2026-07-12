#include <iostream>
using namespace std;
void clearIthBit(int n, int i)
{
    int mask = ~(0) << i; // create a mask by left shifting 1 by i positions
     n= n & mask;   // use bitwise AND to clear the i-th bit
     cout << "The number after clearing the " << i << "th bit is: " << n << endl;
}
int main()
{
    clearIthBit(6, 1); // Example usage: Clear the 1st bit of number 6 (binary 110) to 0
    return 0;

}