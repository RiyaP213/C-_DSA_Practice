#include<iostream>
using namespace std;
// This is called staircase search algorithm. It works on sorted matrix where each row and column is sorted in ascending order. We start from the top right corner of the matrix and compare the target with the current element. If the target is equal to the current element, we have found the target. If the target is less than the current element, we move left (decrease column index). If the target is greater than the current element, we move down (increase row index). We continue this process until we find the target or go out of bounds of the matrix.

int main(){
    int arr[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};

    int rows=4;
    int cols=4;

    int target=7;

    int i=0,j=cols-1;

    while(i<rows && j>=0){
        if(arr[i][j]==target){
            cout<<"Found at: "<<i<<","<<j;
            return 0;
        }
        else if(arr[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }

    cout<<"Not found";
}