#include<iostream>
using namespace std;
int main(){
    int arr[]={5, 1, 4, 2, 8};
    int n=sizeof(arr)/sizeof(arr[0]);

    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                    }
        }
    }
    cout<<"Sorted array: \n";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";

}}