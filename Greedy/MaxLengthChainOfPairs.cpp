#include<iostream>
#include<vector>
using namespace std;

// a pair(c,d) can come after pair(a,b) if b<c. we have to find the maximum length chain of pairs.
// similar to activity selection problem. we will sort the pairs according to their second element and then we will select the pairs greedily.
bool compare(pair<int,int>p1, pair<int,int>p2){
    return p1.second<p2.second;
}

int maxchainlength(vector<pair<int,int>> pairs){

    int n=pairs.size();
    sort(pairs.begin(),pairs.end(),compare);
    int ans=1;
    int curend=pairs[0].second;
    for(int i=1;i<n;i++){
        if(pairs[i].first>curend){
            ans++;
            curend=pairs[i].second;
        }
    }
    cout<<"maximum length of chain = "<<ans<<endl;
    return ans;
}

int main(){
    int n=5;
    vector<pair<int,int>> pairs={{5,24},{39,60},{5,28},{27,40},{50,90  }};
    maxchainlength(pairs);
    return 0;
}