#include<iostream>
#include<vector>
using namespace std;

int LastOccurance(const vector<int> &arr, int Target, int i){

    if(i<0){
        return -1;
        }
    if (arr[i]==Target){
        return i;
    }
return LastOccurance(arr,Target, i-1);
    

    }    

    int main(){
        const vector<int> arr ={ 1,2,3,4,5};
        cout<<LastOccurance(arr, 3, arr.size()-1)<<endl; // Example usage: Find the last occurrence of 3 in the array
        return 0;

    }




    int lastOccurance(vector<int> &arr, int Target, int i){
        if (i==arr.size()){
            return -1;
        }
        int indexFound = lastOccurance(arr, Target, i+1);
        if(indexFound == -1 && arr[i]==Target){
            return i;
        }
        return indexFound;}
