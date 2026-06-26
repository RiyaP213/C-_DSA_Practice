#include<iostream>
using namespace std;

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