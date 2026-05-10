// Diamond Pattern in C++

#include<iostream>
using namespace std;

int main(){

    int n;

    // take input from user
    cout << "Enter a number: ";
    cin >> n;

    // ------UPPER HALF OF DIAMOND-----------

    for(int i=1; i<=n; i++){

        // print spaces
        // spaces decrease every row
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }

        // print stars
        // stars increase like:
        // 1, 3, 5, 7 ...
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        }

        // move to next line
        cout << endl;
    }

    // ---------LOWER HALF OF DIAMOND------------

    for(int i=n-1; i>=1; i--){

        // print spaces
        // spaces increase every row
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }

        // print stars
        // stars decrease like:
        // 5, 3, 1 ...
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        }

        // move to next line
        cout << endl;
    }

    return 0;
}