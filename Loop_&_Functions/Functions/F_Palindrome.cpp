#include<iostream>
using namespace std;
int Palindrome(int n){
    int original = n;
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10; // Get the last digit
        reversed = reversed * 10 + digit; // Append the digit to the reversed number
        n /= 10; // Remove the last digit
    }
    return original == reversed; // Check if the original number is equal to the reversed number
    

}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
   int yes= Palindrome(n);
   if (yes==1){
     cout<< "The number is palindrome: " << endl;}
   else
        {cout<< "The number is not palindrome: " << endl;}
};
