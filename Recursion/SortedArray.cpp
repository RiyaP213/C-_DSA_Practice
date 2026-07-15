#include<iostream>
using namespace std;

bool Sorted( int arr[], int n){
    if (n==1){
        return true;

    }
    if (arr[n-1]<arr[n-2]){
        return false;
    }
    return Sorted(arr, n-1);

}

int main (){
    int arr[]={1,2,3,4,5};
    cout<<Sorted(arr, 5)<<endl; // Example usage: Check if the array is sorted
    return 0;
}