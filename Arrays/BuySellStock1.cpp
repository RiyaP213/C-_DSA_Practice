#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main (){
    int prices[]={10,20,3,45,60};
    int n=sizeof(prices)/sizeof(prices[0]);

    int bestbuy=INT_MAX;
    int maxprofit=0;
    for(int i=0;i<n;i++){
         bestbuy=min(bestbuy,prices[i]);
        int currentprofit=prices[i]-bestbuy;
            maxprofit=max(maxprofit,currentprofit);}


    
    cout<<"Maximum Profit is: "<<maxprofit<<endl;
    }