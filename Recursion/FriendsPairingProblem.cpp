#include<iostream>
using namespace std;

// total ways to pair n friends such that each friend can be single or paired up with some other friend.
// f(n) = f(n-1) + (n-1)*f(n-2)
// f(n-1) -> when the nth friend is single
// (n-1)*f(n-2) -> when the nth friend is paired up
int FriendsPairing(int n){
    if (n==1 || n==2){
        return n;
    }
    return FriendsPairing(n-1) + (n-1)*FriendsPairing(n-2);
}
int main(){
    cout<<FriendsPairing(5)<<endl; // Example usage: Calculate the number of
    //ways to pair 5 friends
    return 0;
}