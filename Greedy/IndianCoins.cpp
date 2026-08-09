#include<iostream>
using namespace std;

// we are given an infinite supply of demominations [1,2,5,10,20,50,100,200,500,2000] and a value N. we have to find the minimum number of coins to make the value N. we will use greedy approach to solve this problem.
// approach: we will take the largest denomination which is less than or equal to N and subtract it from N and repeat this process until N becomes 0.

int getminchange(vector<int>coins, int v){
    int ans=0;
    int n=coins.size();
    for(int i=n-1;i>=0 && v>0; i--){
        if(v>=coins[i]){
            ans+=v/coins[i];
            v=v%coins[i];
        }
    }
    return ans;

}

int main(){
    vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
    int v=1099;
    cout<<"minimum number of coins to make value "<<v<<" = "<<getminchange(coins,v)<<endl;
    return 0;
}