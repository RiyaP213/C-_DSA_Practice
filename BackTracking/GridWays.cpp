#include<iostream>
using namespace std;

// find the number of ways to reach the destination in a grid of size m x n, starting from the top-left corner (0, 0) to the bottom-right corner (m-1, n-1). 
//You can only move either down or right at any point in time.

int Gridways( int r, int c, int n,int m){
    if(r==n-1 && c==m-1){
        return 1;
    }
    if(r>=n || c>=m){
        return 0;   

        // right
        int val1 = Gridways(r,c+1,n,m);
        // down
        int val2 = Gridways(r+1,c,n,m);
        return val1 + val2;

}}

int main(){
    int n=3,m=3;
    cout<<Gridways(0,0,n,m)<<endl; // Example usage: Calculate the number of ways to reach the destination in a 3x3 grid
    return 0;
}

// time complexity: O(2^(m+n)) because at each cell, we have two choices: move right or move down.
