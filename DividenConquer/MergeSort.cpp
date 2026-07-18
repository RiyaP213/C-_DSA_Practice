#include <iostream>
#include <vector>
using namespace std;

void mergeSort( int arr[], int si, int ei){

    if (si>=ei){// base case: if the starting index is greater than or equal to the ending index, return
        return;
    }

    int mid = si+ (ei-si)/2;// get the mid index to divide
    mergeSort(arr, si, mid);// left half
    mergeSort(arr, mid+1, ei);// right half

    merge (arr, si, mid, ei);// conquer step: merge the two halves
}

void merge( int arr[], int si, int mid, int ei){
    vector<int> temp;
    int i = si; // left part starting index
    int j = mid+1; // right part starting index

    while ( i<=mid && j<=ei){// while both parts have elements
        if (arr[i]<=arr[j]){// if left part element is smaller, add it to temp
            temp.push_back(arr[i]);
            i++;
        }
        else{// if right part element is smaller, add it to temp
            temp.push_back(arr[j]);
            j++;
        }
    }
    // add any remaining elements from either part
    while (i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=ei){
        temp.push_back(arr[j]);
        j++;
    }
    // copy the merged elements back to the original array
    for (int idx=si, x=0; idx<=ei; idx++){
        arr[idx] = temp[x++];
    }
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
     int arr[]={6,3,7,5,2,4};
     int n =6;

     mergeSort(arr, 0, n-1);
     printArray(arr, n);
     return 0;
}

// Time complexity: O(n log n) - The merge sort algorithm divides the array into halves (log n divisions) and 
//merges them back together (O(n) for merging). Therefore, the overall time complexity is O(n log n).