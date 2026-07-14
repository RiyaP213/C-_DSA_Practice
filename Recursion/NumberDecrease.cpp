#include<iostream>
using namespace std;

void decrease( int n){
     if (n==0){
        return;
    }
    cout << n << " ";
    decrease(n - 1);

}

int main (){
    decrease(5); // Example usage: Decrease from 5 to 1
    return 0;
}