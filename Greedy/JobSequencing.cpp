#include<iostream>
using namespace std;
// job sequencing problem: we are given n jobs where every job has a deadline and profit associated with it. we have to schedule the jobs in such a way that we get maximum profit and all the jobs are completed within their deadlines. we can only schedule one job at a time. we will use greedy approach to solve this problem.
// approach: we will sort the jobs according to their profit in decreasing order and then we will

bool compare( pair<int,int>p1, pair<int,int>p2){
    return p1.first>p2.first;
}

int maxprofit(vector<pair<int,int>> jobs, int n){
    sort(jobs.begin(),jobs.end(),compare);
    int profit=jobs[0].second;
    int safedeadline=2;
    for(int i=0;i<jobs.size();i++){
        if(jobs[i].first>=safedeadline){
            profit+=jobs[i].second;
            safedeadline++;
                }

                cout<<"maximum profit = "<<profit<<endl;
return profit;   }

int main(){
    int n=4;
    vector<pair<int,int>> jobs={{0,0},{4,20},{1,10},{1,40},{1,30}};
    maxprofit(jobs,n);
    return 0;
}