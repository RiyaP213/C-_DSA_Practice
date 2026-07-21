// Populate an array with n elements and modify the array by subtracting 2 from each element using backtracking.
#include <iostream>
using namespace std;

void print( int arr[], int n){
    for (int i=0;i<n;i++){
        cout<< arr[i]<<" ";

    }
    cout<<endl;
}

void ChangeArray( int arr[], int n, int i){

    if(i==n)
    { 
        print(arr, n); 
        return; 
    }


     arr[i]=i+1;// before modification, populate the array with values 1 to n
    ChangeArray(arr, n, i+1);// recursive call to the next index
     arr[i] -= 2;// after the recursive call, modify the current index by subtracting 2 backtracking to the previous state
}


int main(){
    int n = 5;
    int arr[5]={0}; // initialize the array with zeros
    ChangeArray(arr, n, 0);
    return 0;
}