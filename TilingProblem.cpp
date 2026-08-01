//Problem: if we have a floor of size 2 x n and tiles of size 2 x 1, then we can tile the floor in f(n) ways.
//we can place the tile vertically or horizontally. If we place it vertically, then we are left with a floor of size 2 x (n-1) 
//and if we place it horizontally, then we are left with a floor of size 2 x (n-2). Therefore, the recurrence relation is f(n) = f(n-1) + f(n-2).
#include<iostream>
using namespace std;

int TilingWays(int n){
    if (n==0 || n==1){
        return 1;
    }
    return TilingWays(n-1) + TilingWays(n-2);
}
int main(){
    cout<<TilingWays(5)<<endl; // Example usage: Calculate the number of
    //ways to tile a 2 x 5 floor
    return 0;
}
