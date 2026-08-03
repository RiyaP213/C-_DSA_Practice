#include<iostream>
#include<vector>
using namespace std;

int TargetF(const vector<int> &arr, int Target, int i){

    if(i==arr.size()){

        return -1;
        }
    if (arr[i]==Target){
        return i;
    }
return TargetF(arr,Target, i+1);
    

    }    

    int main(){
        const vector<int> arr ={ 1,2,3,4,5};
        cout<<TargetF(arr, 3, 0)<<endl; // Example usage: Find the first occurrence of 3 in the array
        return 0;

    }