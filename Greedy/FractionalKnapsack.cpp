#include<iostream>
using namespace std;
// there are 2 knapsack problems 1) fractional knapsack 2) 0-1 knapsack
//we use greedy approach to solve fractional knapsack problem. 
//note: in 0-1 we use DP which we will learn later.
// approach: we will take the item with maximum value/weight ratio and put it in the knapsack until the knapsack is full.

bool compare(pair<double,int>p1, pair<double,int>p2){
    return p1.first>p2.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int W){
    int n =val.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0));// create a vector of size n to store pairs to store the value/weight ratio and the index of the item now initilized with 0;
    for(int i=0;i<n;i++){
        double r= val[i]/double(wt[i]);
        ratio[i]= make_pair(r,i);
    }
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int idx= ratio[i].second;
        if(wt[idx]<=W){
            ans+=val[idx];
            W-=wt[idx];
        }
        else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
    cout<<"maximum value in knapsack = "<<ans<<endl;
    return ans;
}

int main(){
    vector<int> val={60,100,120};
    vector<int> wt={10,20,30};
    int W=50;
    fractionalKnapsack(val,wt,W);
    return 0;
}