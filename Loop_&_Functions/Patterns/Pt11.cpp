#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // ======================
    // UPPER HALF
    // ======================

    for(int i=1; i<=n; i++){

        // left stars
        for(int j=1; j<=i; j++){
            cout << "*";
        }

        // middle spaces
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }

        // right stars
        for(int j=1; j<=i; j++){
            cout << "*";
        }

        cout << endl;
    }


    // LOWER HALF---------------------------

    for(int i=n; i>=1; i--){

        // left stars
        for(int j=1; j<=i; j++){
            cout << "*";
        }

        // middle spaces
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }

        // right stars
        for(int j=1; j<=i; j++){
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}