#include<iostream>
using namespace std;
#include<algorithm>
#include<climits>


int main(){
    int arr[]={1,2,3,4,7,8,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j; 

    }
    swap(arr[i],arr[minIndex]);
    }

    cout<<"Sorted array: \n";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}}

