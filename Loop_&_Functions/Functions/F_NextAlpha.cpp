#include<iostream>
using namespace std;

char nextAlpha(char c){
    if (c >= 'a' && c < 'z') {
        return c + 1; // Return the next lowercase letter
    } else if (c >= 'A' && c < 'Z') {
        return c + 1; // Return the next uppercase letter
    } else {
        return c; // Return the character unchanged if it's not an alphabet
    }

}
int main(){
    char c;
    cout << "Enter a character: ";
    cin >> c;
    cout << "The next alphabet after " << c << " is: " << nextAlpha(c) << endl;
    return 0;
}
