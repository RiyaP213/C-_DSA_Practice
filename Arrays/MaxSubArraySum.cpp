#include<iostream>
#include<climits>
using namespace std;

// this is a brute force approach to find the maximum subarray sum. Time complexity is O(n^3) and space complexity is O(1)

int main (){
    int arr[]={1,2,-3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);


    int MaxSum=INT_MIN;

    for(int start=0; start<n;start++){
        for(int end=start; end<n;end++){
            int currentsum=0;
            for(int i=start;i<=end;i++){  
                currentsum+=arr[i];
                }
                    MaxSum=max(currentsum,MaxSum);
            
            }
    }
    cout<<"Maximum Subarray Sum is: "<<MaxSum<<endl;
} 