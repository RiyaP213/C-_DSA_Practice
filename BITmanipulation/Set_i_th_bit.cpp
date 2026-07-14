// in this program we will set the i-th bit of a number to 1
// If the i-th bit is already 1, it will remain 1, if its 0, it will be changed to 1

int setIthBit(int n, int i)
{
    int mask = 1 << i; // create a mask by left shifting 1 by i positions
    return n | mask;   // use bitwise OR to set the i-th bit to 1
}

int main()
{
    setIthBit(6, 3); // Example usage: Set the 1st bit of number 5 (binary 101) to 1
    return 0;

}
