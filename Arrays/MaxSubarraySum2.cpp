#include<iostream>
#include<climits>
using namespace std;

// this is an optimizedbrute force approach to find the maximum subarray sum. Time complexity is O(n^2) and space complexity is O(1)

int main (){
    int arr[]={1,2,-3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);


    int MaxSum=INT_MIN;

    for(int start=0; start<n;start++){
        int currentsum=0;
        for(int end=start; end<n;end++){

            currentsum+= arr[end];
                }
              MaxSum=max(currentsum,MaxSum);
            
            }
    
    cout<<"Maximum Subarray Sum is: "<<MaxSum<<endl;
}